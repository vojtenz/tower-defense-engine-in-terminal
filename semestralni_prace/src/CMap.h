#ifndef SEMESTRALNI_PRACE_CMAP_H
#define SEMESTRALNI_PRACE_CMAP_H
//CMap.h
#include "CTile.h"
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
     *
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
     *
     * @param src path to the source file
     * @return true if initialization(loading from the file, finding path,...) of the map was successful
     */

    bool initMap(const std::string& src_file);

    /**
     * Prints the map on the terminal
     * @param os output stream to map should be printed
     */
    void renderMap(std::ostream& os, bool coords);

    size_t getWidth() const;

    size_t getHeight() const;

private:
     std::pair<int,int> start;
     size_t width;
     size_t height;
     std::string path;
     std::ifstream map_file;
     std::vector<std::shared_ptr<CTile>> map; /** the container which is the whole map*/
    /**
     *
     * Add character x to the vector of CTile pointers
     * @param x character to be added to the vector(game map) of CTile
     */
     void addCharToMap(char x);

     /**
      * Outputs map to the stream with coordinates
      */
     void renderCords(std::ostream& os);
     void renderNoCords(std::ostream& os);
     /**
      *
      * @param src path to the source file which should the map be loaded from
      * @return true if reading from the file was successful and the map meets the criteria
      */
     bool loadMapfromFile(const std::string& src);
     void clearPath();
     void reconstructPath(const std::string& directions);
};
#endif //SEMESTRALNI_PRACE_CMAP_H
