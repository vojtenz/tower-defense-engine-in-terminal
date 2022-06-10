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
     * Prints the map to the output stream
     * @param os output stream in which map should be printed to
     * @param coords optional parameter determining if the printing should be with coordinates around the map (default false)
     * @param tower_ptr optional parameter enabling to print tower in certain position for user to see without the need to add tower to the map
     */
    void renderMap(std::ostream& os, bool coords = false, int x = -1, int y = -1, CTower* tower_ptr = nullptr);

    size_t getWidth() const;

    size_t getHeight() const;

    const std::string& getPathDirection()const;

private:
     std::pair<int,int> start;
     size_t width;
     size_t height;
     std::string path_direction;
     std::ifstream map_file;
     std::vector<std::shared_ptr<CTile>> map; /** the container which is the whole map*/
    /**
     * Add character x to the vector of CTile pointers
     * @param x character to be added to the vector(game map) of CTile
     */
     void addCharToMap(char x);

     /**
      * Prints map with the coordinates around the map
      * @param os reference to the output stream
      * @param tower_ptr Optional parameter, pointer to the tower which should be printed at certain position for user to see without the need to insert tower to the map
      */
     void renderCords(std::ostream& os, int x , int y, CTower* tower_ptr);

     /**
      * Prints map without the coordinates
      * @param os reference to the output stream
      */
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
