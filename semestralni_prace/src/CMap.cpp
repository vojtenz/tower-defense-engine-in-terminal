//CMap.cpp
#include "CMap.h"
#include "CWall.h"
#include "CEmpty.h"
#include "CPath.h"
#include "CEnd.h"
#include "CStart.h"
#include "CPathFinder.h"
#include "CTower.h"
#include <iomanip>
#include <iostream>

std::shared_ptr<CTile>& CMap::at(size_t x) {
    if(x >= 0 && x < CMap::map.size())
        return CMap::map.at(x);
    throw std::out_of_range("Invalid position x in function CMap::at(int x)");
}

std::shared_ptr<CTile>& CMap::at(size_t x, size_t y) {
    if(x<CMap::height && y < CMap::width)
        return CMap::map.at((x*CMap::width)+y);
    throw std::out_of_range("Invalid position x or y in function CMap::at(int x, int y)");
}

bool CMap::initMap(const std::string& src_file) {
    if(!loadMapfromFile(src_file)) return false;
    CPathFinder fp(width, height, start.first,start.second);
    std::string str_path;
    if(!fp.pathExists(map, str_path)) {
        clearPath();
        if(!fp.pathFind(map,str_path)) return false;
        reconstructPath(str_path);
    }
    path_direction = str_path;
    return true;
}

bool CMap::loadMapfromFile(const std::string& src) {
    CMap::map_file.open(src);
    if(!CMap::map_file.good() || !CMap::map_file.is_open()) return false;

    //hasSE = has Start and End, pair representing coordinates
    std::pair<int,int> hasSE = std::make_pair<int,int>(0,0);
    std::pair<int, int> start_coords= std::make_pair<int,int>(-1,-1);
    size_t local_height = 0;
    size_t local_width = 0;
    int x = 0;
    while(CMap::map_file.good()){
        std::string current_line;
        getline(CMap::map_file, current_line);
        if(local_height == 0) {
            local_width = current_line.length();
        }
        if(current_line.length() != local_width) return false;
        int y = 0;
        for(const char curr_char : current_line){
            if(curr_char == 's') {
                hasSE.first++;
                start_coords.first = x;
                start_coords.second = y;
            }
            if(curr_char == 'x') hasSE.second++;
            addCharToMap(curr_char);
            ++y;
        }
        ++local_height;
        ++x;
    }

    if(!map_file.eof()) return false;

    //map has to have one END and one START for cut-clear path
    if(hasSE.first != 1 || hasSE.second !=1) return false;

    CMap::height = local_height;
    CMap::width = local_width;
    start = start_coords;
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
        case ':':
            CMap::map.push_back(std::make_shared<CPath>());
            break;
        default:
            CMap::map.push_back(std::make_shared<CEmpty>());
    }
}
void CMap::reconstructPath(const std::string& directions) {
    std::pair<int,int> curr = start;
    const char dir_char[]= {'U','D','L','R'};
    const int dir_x[] = {-1,1,0,0};
    const int dir_y[] = {0,0,-1,1};
    for(size_t j = 0; j < directions.length()-1; ++j){
        for(int i = 0; i < 4 ;++i){
            if(directions[j] == dir_char[i]){
                curr.first+=dir_x[i];
                curr.second+=dir_y[i];
                at(curr.first, curr.second) = std::make_shared<CPath>();
                break;
            }
        }
    }
}

void CMap::renderMap(std::ostream &os, bool coords, CTower* tower_ptr) {
    coords ? renderCords(os, tower_ptr) : renderNoCords(os);
}

void CMap::renderNoCords(std::ostream &os) {
    for(size_t i = 0; i < CMap::map.size(); ++i){
        if((i%CMap::width)==0) os  << (i!=0 ? "\n" : "");
        os << *(CMap::map.at(i)) ;
    }
}

void CMap::renderCords(std::ostream &os, CTower* tower_ptr) {
    const short int coords_offset = 5;
    renderHorizontalCords(os,false, coords_offset);
    os << "\n";
    int line = 0;
    for(size_t i = 0; i < CMap::map.size(); ++i){
        if((i%CMap::width)==0) os  << (i!=0 ? "\n" : "") << line++ << std::string(coords_offset - 1, ' ');
        if(tower_ptr != nullptr && i == (tower_ptr->getX()*width)+tower_ptr->getY()){
            os << *tower_ptr;
            continue;
        }
        os << *(CMap::map.at(i));
    }
    os << "\n";
    renderHorizontalCords(os,true, coords_offset);
}

void CMap::renderHorizontalCords(std::ostream&os, bool reversed, int coords_offset, int distance)const{
    char option = reversed ? 1 : 0;
    for(int i = 0; i < 2; ++i, ++option, option%=2) {
        //horizontal offset, numbers with default distance 5
        if (option == 0) {
            os << std::string(coords_offset, ' ');
            for (size_t jj = 0; jj < CMap::width - 1; ++jj) {
                if ((jj % distance == 0)) os << std::setw(distance) << std::left << jj;
                else os << std::setfill(' ');
            }
            os << CMap::width - 1;
            if(!reversed) os << "\n";
        }
        //horizontal offset, dots and vertical lines associated to number above
        if (option == 1) {
            os << std::string(coords_offset, ' ');
            for (size_t j = 0; j < CMap::width - 1; ++j) {
                os << ((j % distance == 0) ? "|" : ".");
            }
            os << "|";
            if(reversed) os << "\n";
        }
    }
}

void CMap::clearPath() {
    for(auto & i : map){
        if(i->getType() == "path") i = std::make_shared<CEmpty>();
    }
}

size_t CMap::getWidth() const{
    return CMap::width;
}

size_t CMap::getHeight() const{
    return CMap::height;
}

const std::string& CMap::getPathDirection() const {
    return path_direction;
}

