#ifndef SEMESTRALNI_PRACE_CTILE_H
#define SEMESTRALNI_PRACE_CTILE_H

//CTile.h
#include <ostream>
/**
 * Base class for every other class representing tile on the map
 */
class CTile{
    protected:
        char symbol;
    public:
     explicit CTile(char _symbol);
     virtual ~CTile() = default;

     /**
      * Prints symbol which symbolize the tile to given output stream.
      * @param os reference to the output stream.
      */
     virtual void print(std::ostream& os) const;

     /**
      * Return the name of the class.
      * @return string representing the name of the class type.
      */
     virtual std::string getType()const = 0;

     /**
      * Returns true if tower can be placed on this tile
      * @return true/false
      */
     virtual bool isPlaceable();
};

/**
 * Overloaded operator << for output
 * @return returns stream reference
 * @param os stream reference which to the output will be interpreted
 * @param ctile reference to the base class CTile
 */
std::ostream& operator << (std::ostream& os, const CTile& ctile);

#endif //SEMESTRALNI_PRACE_CTILE_H
