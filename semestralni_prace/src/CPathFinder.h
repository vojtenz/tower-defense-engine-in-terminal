#ifndef SEMESTRALNI_PRACE_CPATHFINDER_H
#define SEMESTRALNI_PRACE_CPATHFINDER_H
//CPathFinder.h
#include <string>
#include "CTile.h"
#include <memory>
#include <vector>

class CPathFinder{
public:
    CPathFinder(size_t _width, size_t _height, int x_start, int y_start);
    /**
        * Finds if there is already existing path from start to end in the game map
        * @param map reference to the game map in which tha path should be found
        * @param directions input/output parameter, final path determined by U,D,L,R (up, down, left, right)
        * @return true if clear-cut directions from start to end was found
    */
    bool pathExists(const std::vector<std::shared_ptr<CTile>>& map, std::string& directions);
    bool pathFind(const std::vector<std::shared_ptr<CTile>> &map, std::string& directions);
private:
    size_t map_width;
    size_t map_height;
    struct Coord{
        public:
            Coord(int _x = -1, int _y = -1){
                x = _x;
                y = _y;
            }
            int x;
            int y;
            bool operator != (const Coord& r)const;
            bool operator == (const Coord& r)const;
    };
    int getMapPos(const CPathFinder::Coord& xy) const;
    Coord map_start_coord;
    Coord map_end_coord;
    //UP and DOWN
    const int dir_x[4]= {-1,1,0,0};
    //LEFT and RIGHT
    const int dir_y[4]= {0,0,-1,1};
    //Directions
    const char dir[4]= {'U','D','L','R'};
};
#endif //SEMESTRALNI_PRACE_CPATHFINDER_H
