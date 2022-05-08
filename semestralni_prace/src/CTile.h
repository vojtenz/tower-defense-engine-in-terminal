#ifndef SEMESTRALNI_PRACE_CTILE_H
#define SEMESTRALNI_PRACE_CTILE_H

//CTile.h
#include <ostream>
/**
 * Base class for every other class representing tile on the map
 *
 */
class CTile{
    protected:
        char symbol;

    public:
     CTile(char _symbol);
     virtual ~CTile() = default;

     /**
      * Prints symbol which symbolize the tile to given output stream.
      * @param os reference to the output stream.
      */
     virtual void print(std::ostream& os) const;

     /**
      * Prints name of the class.
      * @return string representing the class type.
      */
     virtual std::string getType()const = 0;
};

/**
 * @return returns stream reference
 * @param os stream reference which to the output will be interpreted
 * @param ctile reference to the base class CTile
 */

std::ostream& operator << (std::ostream& os, const CTile& ctile);

#endif //SEMESTRALNI_PRACE_CTILE_H
