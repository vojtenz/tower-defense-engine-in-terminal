//CTower.h
#ifndef SEMESTRALNI_PRACE_CTOWER_H
#define SEMESTRALNI_PRACE_CTOWER_H

#include "CActiveTile.h"

class CTower: public CActiveTile{
    public:
     CTower(char symbol, int pos_x, int pos_y, int _price, int _range, std::string _color);
     virtual std::string getType()const;
     int getPrice()const;
     int getRange()const;
    protected:
     int price;
     int range;
     std::string color;

};
#endif //SEMESTRALNI_PRACE_CTOWER_H
