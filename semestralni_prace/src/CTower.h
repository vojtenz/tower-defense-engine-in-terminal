//CTower.h
#ifndef SEMESTRALNI_PRACE_CTOWER_H
#define SEMESTRALNI_PRACE_CTOWER_H

#include "CActiveTile.h"
#include <map>
#include <memory>

/**
 * Class inherited from CActiveTile representing generic tower
 */
class CTower: public CActiveTile{
    public:
     CTower(char symbol, int _price, int _range, int _dmg, const std::string& _color);
     int getPrice()const;
     int getRange()const;
     int getDmg()const;
     const std::string& getColor()const;
     void print(std::ostream& os) const override;
     virtual void printAttribute(std::ostream& os)const;
     virtual CTower* clone()const = 0;
    protected:
     int dmg;
     int price;
     int range;
     std::string color;
     static std::map<std::string, std::string> colorMap;
     static std::map<std::string, std::string> initColorMap();
     void priceDelim(std::ostream& os, int local_price)const;

};
#endif //SEMESTRALNI_PRACE_CTOWER_H
