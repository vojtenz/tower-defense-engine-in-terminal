//CPathFinder.cpp
#include "CPathFinder.h"
#include <iostream>
#include <queue>
CPathFinder::CPathFinder(size_t _width, size_t _height, int x_start, int y_start): map_width(_width), map_height(_height), map_start_coord(x_start, y_start){
}

bool CPathFinder::pathExists(const std::vector<std::shared_ptr<CTile>> &map, std::string& directions) {
    Coord curr_coord = map_start_coord;
    Coord last_coord;
    Coord tmp;
    //Directions
    const char dir[4]= {'U','D','L','R'};

    //number of new neighbours around tile
    char neighbour_count;

    //the right direction to be headed
    int right_dir = -1;

    //in case of infinite loop, this will always ends, directions will never be longer than size of the map
    for(size_t i = 0; i < map.size(); ++i){
        neighbour_count = 0;
        for(int j = 0; j < 4; ++j){
            tmp = curr_coord;
            tmp.x+=dir_x[j];
            tmp.y+=dir_y[j];

            if(tmp.x>=0 && (size_t)tmp.x<map_height && tmp.y>=0 && (size_t)tmp.y<map_width){
                if(map.at(getMapPos(tmp))->getType() == "end") {
                    directions.push_back(dir[j]);
                    return true;
                }
                if(map.at(getMapPos(tmp))->getType() == "path" && tmp != last_coord){
                    ++neighbour_count;
                    right_dir = j;
                }
            }
        }

        if(neighbour_count == 1) {
            last_coord = curr_coord;
            curr_coord.x+=dir_x[right_dir];
            curr_coord.y+=dir_y[right_dir];
            directions.push_back(dir[right_dir]);
            continue;
        }
        break;
    }
    return false;
}

bool CPathFinder::pathFind(const std::vector<std::shared_ptr<CTile>> &map, std::string& directions) {
    directions.clear();
    std::vector<bool> visited(map.size(),false);
    std::queue<Coord> queue;
    std::vector<Coord*> prev(map.size(), nullptr);

    //the start coordinate
    queue.push(map_start_coord);

    visited.at(getMapPos(map_start_coord)) = true;
    bool isFound = false;
    while(!queue.empty()){
      Coord curr = queue.front();
       queue.pop();
       if(map.at(getMapPos(curr))->getType() == "end") {
            visited.at(getMapPos(curr)) = true;
            isFound = true;
            map_end_coord = curr;
            break;
       }
       for(int j = 0; j < 4; ++j) {
           Coord tmp = curr;
           tmp.x += dir_x[j];
           tmp.y += dir_y[j];

           if (tmp.x < 0 || (size_t)tmp.x >= map_height || tmp.y < 0 || (size_t)tmp.y >= map_width)continue;
           if (visited.at(getMapPos(tmp))) continue;
           if (map.at(getMapPos(tmp))->getType() == "wall") continue;
           queue.push(tmp);
           visited.at(getMapPos(tmp)) = true;
           prev.at((getMapPos(tmp))) = new Coord(curr.x, curr.y);
       }
    }

    if(!isFound){
        for(Coord *x : prev){delete x;}
        return false;
    }

    const char dir[]= {'D', 'U', 'R', 'L'};

    //creating directions string
    Coord *curr = prev.at(getMapPos(map_end_coord));
    Coord *last = &map_end_coord;
    while(curr != nullptr){
        for(int i = 0; i < 4; ++i){
            Coord tmp = *last;
            tmp.x+=dir_x[i];
            tmp.y+=dir_y[i];
            if(tmp == *curr) {
                directions.insert(0, 1, dir[i]);
                last = curr;
                break;
            }
        }
        curr = prev.at(getMapPos(*curr));
    }
    for(Coord *x : prev){delete x;}
    return true;
}

int CPathFinder::getMapPos(const CPathFinder::Coord &coordinates) const {
    return (coordinates.x*map_width)+coordinates.y;
}

bool CPathFinder::Coord::operator!=(const CPathFinder::Coord &r) const {
    return ((Coord::x != r.x) || (Coord::y != r.y));
}

bool CPathFinder::Coord::operator==(const CPathFinder::Coord &r) const {
    return ((Coord::x == r.x) && (Coord::y == r.y));
}
