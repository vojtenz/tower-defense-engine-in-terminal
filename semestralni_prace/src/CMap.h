#ifndef SEMESTRALNI_PRACE_CMAP_H
#define SEMESTRALNI_PRACE_CMAP_H
//CMap.h
#include "CTile.h"
#include "CTower.h"
#include <vector>
#include <memory>
#include <ostream>
#include <fstream>
/**
 * Class representing the map of the game
 */
class CMap{
public:
    CMap(){
        width = 0;
        height = 0;
    }
    /**
     * @param x position in vector map
     * @return reference to the object at that position
     */
    std::shared_ptr<CTile>& at(size_t x);
    /**
     * Access object as 2D map
     * @param x x coordinate
     * @param y y coordinate
     * @return reference to the object at x and y coordinates
     */
    std::shared_ptr<CTile>& at(size_t x, size_t y);

    /**
     * Initialize the map, loads from file, if no path is found or the path is invalid finds path based on BFS
     * @param src path to the source file
     * @return true if initialization(loading from the file, finding path,...) of the map was successful
     */
    bool initMap(const std::string& src_file);

    /**
     * Prints map to the output stream
     * @param os reference to the output stream
     * @param coords optional parameter, if true, map will be printed with coordinates around it
     * @param x optional parameter, x position on the map
     * @param y optional parameter, y position on the map
     * @param tower_ptr optional pointer to the tower with coordinates x and y given before, to print certain tower to the map without the need to directly inserting it to the map, just for the view(when buying)
     */
    void renderMap(std::ostream& os, bool coords = false, int x = -1, int y = -1, CTower* tower_ptr = nullptr);

    size_t getWidth() const;

    size_t getHeight() const;
    /**
     * Returns pair representing coordinates of the starting position
     * @return pair<int,int> as coordinates (x,y)
     */
    std::pair<int,int> getStartPos()const;
    /**
     * Returns either 'U','L','R','D','E' based on how many step enemy has taken
     * @param pos position on the path (number of steps taken)
     * @return char representing which direction enemy should be headed next
     */
    char getPathDirection(size_t pos)const;

private:
     std::pair<int,int> start;
     size_t width;
     size_t height;
     std::string path_direction; /**string containing all the directions to the end*/
     std::ifstream map_file;
     std::vector<std::shared_ptr<CTile>> map; /** the container which is the whole map*/
    /**
     * Add character x to the vector of CTile pointers
     * @param x character to be added to the vector(game map) of CTile
     */
     void addCharToMap(char x);

     void renderCords(std::ostream& os, int x , int y, CTower* tower_ptr);

     void renderNoCords(std::ostream& os);
     /**
      * Prints the horizontal coordinates
      * @param os reference to the output stream
      * @param reversed true if the dots and vertical lines should be printed first
      * @param coords_offset offset of the coordinates
      * @param distance frequency in which should the coordinates numbers should be printed at (default 5)
      */
     void renderHorizontalCords(std::ostream& os, bool reversed, int coords_offset, int distance = 5) const;
     /**
      * Loads map from the file
      * @param src path to the source file which should the map be loaded from
      * @return true if reading from the file was successful and the map meets the criteria
      */
     bool loadMapfromFile(const std::string& src);
     /**
      * Clears the path on the map, used in case where the map is not cut-clean and new path should be found
      */
     void clearPath();
     /**
      * Reconstructs the path by given directions
      * @param directions
      */
     void reconstructPath(const std::string& directions);
};
#endif //SEMESTRALNI_PRACE_CMAP_H
