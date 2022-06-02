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
    /**
     * Using BFS algorithm finds shortest possible path
     * @param map reference to the map
     * @param directions input/output parameter, final path determined by U,D,L,R from the start to end
     * @return true if path was found, false if path from start to end doesnt exist
     */
    bool pathFind(const std::vector<std::shared_ptr<CTile>> &map, std::string& directions);

private:
    size_t map_width;
    size_t map_height;
    /**
     * Helper struct for easier work with coordinates within CPathFinder class
     */
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
    /**
     * Returns position in 1D array from 2D parameters based on width of the map
     * @param coordinates position in the 2D grid
     * @return position in 1D array
     */
    int getMapPos(const CPathFinder::Coord& coordinates) const;
    Coord map_start_coord;
    Coord map_end_coord;
    //UP and DOWN
    const int dir_x[4]= {-1,1,0,0};
    //LEFT and RIGHT
    const int dir_y[4]= {0,0,-1,1};
};
#endif //SEMESTRALNI_PRACE_CPATHFINDER_H
