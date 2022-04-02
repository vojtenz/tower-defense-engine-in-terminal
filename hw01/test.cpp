#ifndef __PROGTEST__
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <memory>
#include <functional>
#include <stdexcept>
using namespace std;
#endif /* __PROGTEST__ */

struct BitManager{
	
	bool openFile(const char* filename){
		f.open(filename, ios::binary | ios::in);
		return f.good();
	}

	//nacitani charu z binaru
	char getChar(bool& err){
		char znak=0;
		for(int j=0;j<8;j++){
			if(bit_position<0){
				if(!loadByte()){
					err=false;
					return -1;
				}
				bit_position=7;
			}
			znak<<=1;
			znak|=((byte >> bit_position) & 1);
			bit_position--;
		}	

		//jestlize bajt ma prvni bit 1 -> neni ASCII
		if((znak >> 7) & 1){
			err=false;
			return -1;
		}

		return znak;
	}

	//nacitani bitu z binaru
	char getBit(){
		if(bit_position<0){
			if(!loadByte())return -1;
			bit_position=7;
		}
		char x = ((byte >> bit_position) & 1);
		bit_position--;
		return x;
	}


	int getLastChunkSize(){
		int x=0;
		for(int j=0;j<12;j++){
			if(bit_position<0){
				if(!loadByte())return -1;
				bit_position=7;
			}
			x<<=1;
			x|=((byte >> bit_position) & 1);
			bit_position--;
		}
		return x;
	}
	
	bool eof(){
		return f.eof();
	}	

	bool endIn(){
		f.close();		
		return f.fail();
	}

	private:
		ifstream f;
		char byte;
		int bit_position=-1;

		//funkce pro nacitani dalsiho bajtu do pameti
		bool loadByte(){
			if(f.good())f.get(byte);
			return f.good();
		}

};

struct HuffTree{
	
	~HuffTree(){
		deleteTree(root);
	}
	
	//vykonstruovani stromu
	bool constructTree(BitManager& mng){
		bool success=true;
		root=constructTreeRec(mng,success);
		return success;
	}


	char findTreeChar(BitManager& mng, bool& success){
		Node* node=root;

		//pokud nas to navede to null hodnoty, vracime false
		if(node==nullptr){
			success=false;
			return 0;
		}

		//dokud nenarazime na list stromu, ridime se instrukcemi 
		while(!isLeaf(node)){
			short int bit=mng.getBit();

			//neco se pokazilo s nacitanim bitu
			if(bit<0){
				success=false;
				return 0;
			}


			if(bit==1)node=node->right;
			else node=node->left;
		}

		return node->data;
	}

	private:
		struct Node{
			//mozna udelat bez konstruktoru a inicializovat uz jako atributy
			Node(){
				data=0;
				left=nullptr;
				right=nullptr;
			}

			//char data=0;
			//Node* left=nullptr;
			//Node* right=nullptr;
			char data;
			Node* left;
			Node* right;
		};

		//root stromu
		Node* root=nullptr;
		
		bool isLeaf(Node* node){
			//pokud ma node pravou i levou null -> je to list
			return (node->left==nullptr && node->right==nullptr);
		}
		
		//rekurzivni mazani stromu
		void deleteTree(Node* node){
			if(node==nullptr)return;
			deleteTree(node->left);
			deleteTree(node->right);
			delete node;
		}
		
		//rekurzivni konstruovani stromu
		Node* constructTreeRec(BitManager& mng, bool& success){
			char bit;
			//neco se pokazilo pri nacitani bitu
			if((bit=mng.getBit())<0){
				success=false;
				return nullptr;
			}

			Node *tmp=new Node();
			if(bit == 1){
				//kdyz pri getChar() dojde k chybe, return je -1, tudiz neresim co se priradi do tmp->data
				//ale success nastavim na false
				tmp->data=mng.getChar(success);
				return tmp;
			}

			tmp->left=constructTreeRec(mng,success);
			tmp->right=constructTreeRec(mng,success);
			
			return tmp;
		}
};



bool decompressFile ( const char * inFileName, const char * outFileName )
{
	//nepodarilo se otevrit vystupni soubor
	ofstream out(outFileName,ios::binary | ios::out);
	if(!out.good()){
		return false;
	}

	BitManager mng;
	//nepodarilo se otevrit vstupni soubor
	if(!mng.openFile(inFileName)){
		return false;
	}

	HuffTree tree;
	bool good=true;
	
	//chyba pri konstrukci stromu
	if(!tree.constructTree(mng)){
		return false;
	}
		
	short int chunk_bit;
	//dokud nenarazim na chunk ktery zacina 1, tedy posledni chunk
	while((chunk_bit=mng.getBit())==1){
		for(int i=0;i<4096;i++){
			char x=tree.findTreeChar(mng,good);
			if(good) {
				if(!out.good())return false;
				out.put(x);
				out.flush();
			}
			else return false;
		}
	}
	
	//nemusel byt nalezen posledni chunk, chunk_bit by byl nastaven na -1
	if(!good || chunk_bit!=0){
		return false;
	}
	
	//velikost posledniho chunku
	int chunk_size=mng.getLastChunkSize();	
	
	//kdyz se spatne nacetl posledni chunk
	if(chunk_size<0){
		return false;
	}

	for(int i=0;i<chunk_size;i++){
		char x=tree.findTreeChar(mng,good);
		if(good){
			if(out.good()){
				out.put(x);
				out.flush();
			}
		}
		else return false;
	}

	//uzavreni input stream
	if(mng.endIn())return false;	

	//uzavreni output stream
	out.close();
	if(out.fail())return false;

	return true;
}

bool compressFile ( const char * inFileName, const char * outFileName )
{
  // keep this dummy implementation (no bonus) or implement the compression (bonus)
  return false;
}
#ifndef __PROGTEST__
bool identicalFiles ( const char * fileName1, const char * fileName2 )
{
  // todo
  return false;
}

int main ( int argc, char** argv )
{
  assert ( decompressFile ( "tests/test0.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/test0.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/test1.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/test1.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/test2.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/test2.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/test3.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/test3.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/test4.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/test4.orig", "tempfile" ) );

  assert ( ! decompressFile ( "tests/test5.huf", "tempfile" ) );


  assert ( decompressFile ( "tests/extra0.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/extra0.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/extra1.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/extra1.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/extra2.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/extra2.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/extra3.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/extra3.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/extra4.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/extra4.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/extra5.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/extra5.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/extra6.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/extra6.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/extra7.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/extra7.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/extra8.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/extra8.orig", "tempfile" ) );

  assert ( decompressFile ( "tests/extra9.huf", "tempfile" ) );
  assert ( identicalFiles ( "tests/extra9.orig", "tempfile" ) );

	//bool x=decompressFile(argv[1],"out.bin");
	//cout << "Good :" << boolalpha << x << endl;
	return 0;
}
#endif /* __PROGTEST__ */
