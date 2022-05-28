//CMap.cpp
#include "CMap.h"
#include <iostream>
#include "CWall.h"
#include "CEmpty.h"
#include "CPath.h"
#include "CEnd.h"
#include "CStart.h"
#include "CTowerRed.h"
#include <iomanip>
#define COORDS_OFFSET 5

bool CMap::loadMapfromFile(std::string src) {

    CMap::map_file.open(src);
    if(!CMap::map_file.good() || !CMap::map_file.is_open()) return false;

    std::string first_line;
    getline(CMap::map_file,first_line);
    int width = first_line.length();
    // go through line and add to my vector in map
    for(const char curr_char : first_line){
        addCharToMap(curr_char);
    }

    //first line already done
    int height = 1;
    auto hasSE = std::make_pair<int,int>(0,0);
    while(CMap::map_file.good()){
        std::string current_line;
        getline(CMap::map_file, current_line);
        if(current_line.length() != width) return false;
        for(const char curr_char : current_line){
            if(curr_char == 's') hasSE.first++;
            if(curr_char == 'x') hasSE.second++;
            addCharToMap(curr_char);
        }
        ++height;
    }
    if(!map_file.eof()) return false;
    if(hasSE.first != 1 || hasSE.second !=1) return false;
    CMap::height = height;
    CMap::width = width;

    return true;
}

void CMap::addCharToMap(const char x) {
    switch (x) {
        case '#':
            CMap::map.push_back(std::make_shared<CWall>());
            break;
        case 's':
            CMap::map.push_back(std::make_shared<CStart>());
            break;
        case 'x':
            CMap::map.push_back(std::make_shared<CEnd>());
            break;
        case '.':
            CMap::map.push_back(std::make_shared<CPath>());
            break;

        //delete this later on
        case 'A':
            CMap::map.push_back(std::make_shared<CTowerRed>('F',0,0,15000,3));
            break;

        default:
            CMap::map.push_back(std::make_shared<CEmpty>());
    }
}

void CMap::renderMap(std::ostream &os, bool coords) {
    coords ? renderCords(os) : renderNoCords(os);
}

void CMap::renderNoCords(std::ostream &os) {
    for(int i = 0; i < CMap::map.size(); ++i){
        if((i%CMap::width)==0) os  << (i!=0 ? "\n" : "");
        os << *(CMap::map.at(i)) ;
    }
}

void CMap::renderCords(std::ostream &os) {

    //offset
    os << std::string(COORDS_OFFSET, ' ');
    for(int jj = 0; jj < CMap::width; ++jj){
        if((jj%5 == 0)) os << std::setw(5) << std::left << jj;
        else os << std::setfill(' ');
    }
    os << "\n";

    //offset
    os << std::string(COORDS_OFFSET, ' ');
    for(int j = 0; j < CMap::width; ++j){
        os << ((j%5 == 0) ? "|" : ".");
    }
    os << "\n";

    int line = 0;
    for(int i = 0; i < CMap::map.size(); ++i){
        if((i%CMap::width)==0) os  << (i!=0 ? "\n" : "") << line++ << std::string(COORDS_OFFSET - 1, ' ');
        os << *(CMap::map.at(i)) ;
    }
}

int CMap::getWidth() {
    return CMap::width;
}

int CMap::getHeight() {
    return CMap::height;
}
