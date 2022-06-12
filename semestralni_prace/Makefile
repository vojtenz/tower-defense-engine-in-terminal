CXX=g++
LD=g++
CXXFLAGS=-Wall -pedantic -g
SRC_DIR = ./src/
VALGRIND_FLAGS = --leak-check=full --track-origins=yes
SOURCE_FILES = $(SRC_DIR)CDefinition.o $(SRC_DIR)CDialog.o $(SRC_DIR)CEmpty.o $(SRC_DIR)CEnd.o $(SRC_DIR)CEnemy.o $(SRC_DIR)CEnemyImmune.o $(SRC_DIR)CGame.o $(SRC_DIR)CMap.o $(SRC_DIR)CPathFinder.o $(SRC_DIR)CPath.o $(SRC_DIR)CStart.o $(SRC_DIR)CTile.o $(SRC_DIR)CTowerGreen.o $(SRC_DIR)CTower.o $(SRC_DIR)main.o $(SRC_DIR)CActiveTile.o $(SRC_DIR)CWall.o $(SRC_DIR)CTowerGeneric.o $(SRC_DIR)CEnemyGeneric.o $(SRC_DIR)CRound.o $(SRC_DIR)CSaveFile.o

all: compile doc

compile: hejlevoj

hejlevoj: $(SOURCE_FILES)
	$(LD) $(CXXFLAGS) -o $@ $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(SRC_DIR)*.o hejlevoj doc/

deps:
	$(CXX) -MM *cpp > Makefile.d

run: hejlevoj
	./hejlevoj

run_valgrind: hejlevoj
	valgrind $(VALGRIND_FLAGS) ./hejlevoj
	
doc: Doxyfile $(HEADERS)
	doxygen Doxyfile	

-include Makefile.d
