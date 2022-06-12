//CTower.h
#ifndef SEMESTRALNI_PRACE_CTOWER_H
#define SEMESTRALNI_PRACE_CTOWER_H

#include "CActiveTile.h"
#include <map>
#include <memory>

/**
 * Abstract class inherited from CActiveTile representing all towers
 */
class CTower: public CActiveTile{
    public:
     CTower(char symbol, int _price, int _range, int _dmg, const std::string& _color, int _id);
     virtual ~CTower() = default;
     int getPrice()const;
     int getRange()const;
     int getDmg()const;
     const std::string& getColor()const;
     void print(std::ostream& os) const override;
     /**
      * Prints attribute of the tower to the desired output stream
      * @param os output stream
      */
     virtual void printAttribute(std::ostream& os)const;
     /**
      * Clone method similar to the enemy clone method, expects it returns base class CTower pointer
      * @return CTower pointer
      */
     virtual CTower* clone()const = 0;
     int getID()const;
    protected:
     int dmg;
     int price;
     int range;
     int id;
     std::string color;
     static std::map<std::string, std::string> colorMap;
     static std::map<std::string, std::string> initColorMap();

};
#endif //SEMESTRALNI_PRACE_CTOWER_H
