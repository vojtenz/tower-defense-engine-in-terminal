//CMap.cpp
#include "CMap.h"
#include "CWall.h"
#include "CEmpty.h"
#include "CPath.h"
#include "CEnd.h"
#include "CStart.h"
#include "CPathFinder.h"
#include <iomanip>
#define COORDS_OFFSET 5

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
    path = str_path;
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
        case '.':
            CMap::map.push_back(std::make_shared<CPath>());
            break;

        default:
            CMap::map.push_back(std::make_shared<CEmpty>());
    }
}

void CMap::renderMap(std::ostream &os, bool coords) {
    //system("clear");
    //os << "\033[2J\033[1;1H";
    coords ? renderCords(os) : renderNoCords(os);
    os << "\n";
}

void CMap::renderNoCords(std::ostream &os) {
    for(size_t i = 0; i < CMap::map.size(); ++i){
        if((i%CMap::width)==0) os  << (i!=0 ? "\n" : "");
        os << *(CMap::map.at(i)) ;
    }
}

void CMap::renderCords(std::ostream &os) {

    //offset
    os << std::string(COORDS_OFFSET, ' ');
    for(size_t jj = 0; jj < CMap::width-1; ++jj){
        if((jj%5 == 0)) os << std::setw(5) << std::left << jj;
        else os << std::setfill(' ');
    }
    os << CMap::width-1;
    os << "\n";

    //offset
    os << std::string(COORDS_OFFSET, ' ');
    for(size_t j = 0; j < CMap::width-1; ++j){
        os << ((j%5 == 0) ? "|" : ".");
    }
    os << "|";
    os << "\n";

    int line = 0;
    for(size_t i = 0; i < CMap::map.size(); ++i){
        if((i%CMap::width)==0) os  << (i!=0 ? "\n" : "") << line++ << std::string(COORDS_OFFSET - 1, ' ');
        os << *(CMap::map.at(i)) ;
    }
}

void CMap::clearPath() {
    for(auto & i : map){
        if(i->getType() == "path") i = std::make_shared<CEmpty>();
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

size_t CMap::getWidth() const{
    return CMap::width;
}

size_t CMap::getHeight() const{
    return CMap::height;
}
