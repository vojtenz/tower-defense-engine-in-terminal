#ifndef __PROGTEST__
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
using namespace std;
#endif /* __PROGTEST__ */

class CFile
{
  public:
	//konstruktor
	CFile( void ): start(nullptr){}
    
	//destruktor:
		//	vymaze list, potom by se mel vymazat kazdy node samostatne, node bude CVersion co ma vlastni destruktor	
	~CFile( void ){
		listDelete(); 
	}	
    
	bool seek(uint32_t offset){
		// offset pozice musi byt >=0 && <= size
		// kdyz offset = size, tak se zapisuje az za posledni bajt -> probehne realokace
		if(offset >=0 && offset <= curr_version.m_size){
			curr_version.m_offset = offset;	
			return true;
		}
		else return false;
	}
    
	//cteni souboru
	uint32_t read(uint8_t* dst, uint32_t bytes ){
		//musi byt kam zapisovat
		if(dst == nullptr) return 0; 
		uint32_t i;
		for(i=0; i < bytes; i++){
			if(curr_version.m_offset >= curr_version.m_size)break;
			dst[i] = curr_version.m_data[curr_version.m_offset++];
			//cnt++;
		}
		return i;
	}
    
	//zapis 
	uint32_t write(const uint8_t* src, uint32_t bytes ){
		//musi byt z ceho cist
		if (src == nullptr) return 0;

		//prochazime pole 'bajtu' po jednotlivych bajtech a vkladame do pole
		for(uint32_t i=0;i < bytes;++i){
			
			//je treba realokovat
			if(curr_version.m_offset >= curr_version.m_cap){
				grow();
			}
			curr_version.m_data[curr_version.m_offset++] = src[i];
			
			//potrebujeme udrzovat konzistentni data
			if(curr_version.m_offset > curr_version.m_size) curr_version.m_size = curr_version.m_offset;
		}
		
		return bytes;	
	}
    
	void truncate( void ){
		curr_version.m_size = curr_version.m_offset;
	}
    
	uint32_t fileSize( void ) const{
		return curr_version.m_size;
	}

    //vytvori novou verzi, ktera se ulozi -> zkopiruje se aktualni stav souboru a vytvori se verze
	void addVersion( void ){
		start = createVersion();	
	}
    
	bool undoVersion( void ){
		if(start == nullptr) return false;
		//zkopiruje se obsah CVersion na ktery ukazuje pointer start, nejprve ale dereferencujeme
		curr_version = *start;
    	start = deleteVersion(start);
		return true;
	}



	void printData( void ) const{
		for(uint32_t i=0; i < curr_version.m_size; i++){
			cout << unsigned(curr_version.m_data[i]) << "|";
		} 
		cout << endl;
	
	}
	
	void printVerInfo( void ) const{
		cout << "Size: " << curr_version.m_size << endl;
		cout << "Cap: " << curr_version.m_cap << endl;
		cout << "Offset: " << curr_version.m_offset << endl;
		printData();
	}

	//print aktualniho zasobniku
	void printList(){
		if(start == nullptr) {
			cout << "LIST EMPTY" << endl;
			return;
		}
		CVersion *tmp = start;
		cout << "HEAD" << endl;
		while (tmp){
			cout << "->";
			for(size_t i = 0; i<tmp->m_size;i++) cout << unsigned(tmp->m_data[i]) << " ";
			cout << "\n";
			cout << "size: " << tmp->m_size << endl;
			cout << "cap: " << tmp->m_cap << endl;
			cout << "offset: " << tmp->m_offset << endl;
			tmp = tmp->m_next;
			cout << setfill('-') << setw(50) << "\n";
		}
		cout << "END OF LIST" << endl;
	}

  private:
	//struktura zachovajici udaje o verzi souboru
	struct CVersion{
		uint8_t* m_data;
		size_t m_size;
		size_t m_cap;
		uint32_t m_offset;
		CVersion* m_next; 

		//bezparametricky konstruktor
		CVersion():m_data(nullptr), m_size(0), m_cap(0), m_offset(0), m_next(nullptr){}

		//destruktor
		~CVersion(){
			delete [] m_data;
		}

		//kopirovaci konstruktor
		CVersion(const CVersion& param){
        	//kapacitu nastavim na size, kapacita by byla mozna zbytecne velka, v pripadne by se mel zavolat grow() 
			m_cap = param.m_size;
        	m_size = param.m_size;
        	m_offset = param.m_offset;
        	m_data = new uint8_t[param.m_size];
        	for (size_t i = 0; i < m_size; i++){
           		m_data[i] = param.m_data[i];
        	}
    	}

		//pretizeny operator prirazeni
		CVersion& operator = (const CVersion& right_side){
        	if (&right_side == this) return *this;
        	delete [] m_data;
        	m_size = right_side.m_size;
        	m_cap = right_side.m_size;
        	m_offset = right_side.m_offset;
        	m_next = right_side.m_next;
        	m_data = new uint8_t[right_side.m_size];
        	for(size_t i=0; i<right_side.m_size; i++){
            	m_data[i] = right_side.m_data[i];
        	}
        	return *this;
    	}
	};
	
	//natahovani pole u CVersion curr
	void grow(){
		int new_cap = 2 * curr_version.m_cap + 4;
		auto new_data = new uint8_t[new_cap];
		
		for(uint32_t i = 0; i < curr_version.m_size; ++i){
			new_data[i] = curr_version.m_data[i];
		}	

		delete[] curr_version.m_data;
		curr_version.m_data = new_data;
		curr_version.m_cap = new_cap;
	
	}

	CVersion curr_version;
	CVersion *start;

	//vytvori verzi z momentalniho stavu curr_version (mozna prejmenovat)	
	CVersion* createVersion(){
    	CVersion *tmp = new CVersion();
    	tmp->m_data = new uint8_t[curr_version.m_size];
    	for(size_t i=0; i<curr_version.m_size; i++){
        	tmp->m_data[i] = curr_version.m_data[i];
    	}
    	tmp->m_size = curr_version.m_size;
		tmp->m_offset = curr_version.m_offset;
		tmp->m_cap = curr_version.m_size;
		tmp->m_next = start;

    	return tmp;
	}
	
	//odstrani verzi ze zasobniku v parametru a vrati ukazatel na dalsi verzi
	CVersion* deleteVersion(CVersion* ver){
    	CVersion * next = ver->m_next;
    	//mel by se zavolat destruktor CVersion
		//	destruktor deletuje dynamicky alokovane pole 
		delete ver;
    	return next;
	}

	void listDelete(){
    	//jen pointer, nic se nekopiruje
		CVersion* curr = start;
    	while(curr){
        	curr = deleteVersion(curr);
    	}
		start = nullptr;
	}

};


#ifndef __PROGTEST__
bool               writeTest                               ( CFile           & x,
                                                             const initializer_list<uint8_t> & data,
                                                             uint32_t          wrLen )
{
  return x . write ( data . begin (), data . size () ) == wrLen;
}

bool               readTest                                ( CFile           & x,
                                                             const initializer_list<uint8_t> & data,
                                                             uint32_t          rdLen )
{
  uint8_t  tmp[100];
  uint32_t idx = 0;

  if ( x . read ( tmp, rdLen ) != data . size ())
	 return false;
  for ( auto v : data )
    if ( tmp[idx++] != v )
      return false;
  return true;
}

int main ( void )
{
	
	//SEEK TEST
	/*
	   CFile f0;
	   f0.printVerInfo();
      assert(f0.seek(0));	
	  assert(!f0.seek(3));
	  assert(!f0.seek(-1));
	  assert ( writeTest ( f0, { 10, 20, 30, 69, 99, 126, 99, 200 }, 8 ) );
	  assert(f0.seek(6));
	  assert(f0.seek(7));
	  assert(f0.seek(8));
	  assert(!f0.seek(9));
	  assert ( writeTest ( f0, { 10, 20 }, 2 ) );
	  f0.printVerInfo();
	  assert(f0.seek(3));
	  f0.truncate();
	  f0.printVerInfo();
	  assert(f0.seek(3));
	  assert(!f0.seek(4));
*/
	
  CFile f0;

  assert ( writeTest ( f0, { 10, 20, 30 }, 3 ) );
  assert ( f0 . fileSize () == 3 );
  assert ( writeTest ( f0, { 60, 70, 80 }, 3 ) );
  assert ( f0 . fileSize () == 6 );
  assert ( f0 . seek ( 2 ));
  assert ( writeTest ( f0, { 5, 4 }, 2 ) );
  assert ( f0 . fileSize () == 6 );
  assert ( f0 . seek ( 1 ));
  assert ( readTest ( f0, { 20, 5, 4, 70, 80 }, 7 ));
  assert ( f0 . seek ( 3 ));
  f0 . addVersion();
  assert ( f0 . seek ( 6 ));
  assert ( writeTest ( f0, { 100, 101, 102, 103 }, 4 ) );
  f0 . addVersion();
/*
f0.printList();
f0.printData();
f0.printVerInfo();
f0.undoVersion();  
cout << "---------------------------" << endl;
f0.printData();
f0.printVerInfo();
f0.undoVersion();
f0.seek(4);
assert ( writeTest ( f0, { 0, 129, 1, 222 }, 4 ) );
f0.printData();
f0.printVerInfo();
f0.addVersion();
f0.addVersion();
assert ( writeTest ( f0, { 0, 12, 9, 22 }, 4 ) );
f0.seek(0);
f0.addVersion();
f0.printData();
f0.printVerInfo();
f0.printList();
*/
  
  assert ( f0 . seek ( 5 ));
//!!!!!!!!!!!!!!!!!!!!!!!!!  //CFile f1 ( f0 );
  f0 . truncate ();
  assert ( f0 . seek ( 0 ));
  assert ( readTest ( f0, { 10, 20, 5, 4, 70 }, 20 ));
  assert ( f0 . undoVersion () );
  assert ( f0 . seek ( 0 ));
  assert ( readTest ( f0, { 10, 20, 5, 4, 70, 80, 100, 101, 102, 103 }, 20 ));
  assert ( f0 . undoVersion () );
  assert ( f0 . seek ( 0 ));
  assert ( readTest ( f0, { 10, 20, 5, 4, 70, 80 }, 20 ));
  assert ( !f0 . seek ( 100 ));
/*
  assert ( writeTest ( f1, { 200, 210, 220 }, 3 ) );
  assert ( f1 . seek ( 0 ));
  assert ( readTest ( f1, { 10, 20, 5, 4, 70, 200, 210, 220, 102, 103 }, 20 ));
  assert ( f1 . undoVersion () );
  assert ( f1 . undoVersion () );
  assert ( readTest ( f1, { 4, 70, 80 }, 20 ));
  assert ( !f1 . undoVersion () );
  */
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
