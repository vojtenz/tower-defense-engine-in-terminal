#ifndef SEMESTRALNI_PRACE_CMAP_H
#define SEMESTRALNI_PRACE_CMAP_H
//CMap.h
#include "CTile.h"
#include <vector>
#include <memory>
#include <ostream>
/**
 * Class representing the map of the game
 */
class CMap{
    CMap() = default;
    /**
     *
     * @param x position in vector map
     * @return reference to the object at that position
     */
    CTile& at(int x);
    /**
     * Access object as 2D map
     * @param x x coordinate
     * @param y y coordinate
     * @return reference to the object at x and y coordinates
     */
    CTile& at(int x, int y);
    /**
     *
     * @param src path to the source file
     * @return true if reading from the file was succesful, otherwise false
     */
    bool loadMapfromFile(std::string src);

    /**
     * Prints the map
     * @param os output stream to map should be printed
     */
    void renderMap(std::ostream& os);
    int getWidth();
    int getHeight();

    private:
     int width;
     int height;
     std::vector<std::shared_ptr<CTile>> map; /** the container which is the whole map*/
};
#endif //SEMESTRALNI_PRACE_CMAP_H
