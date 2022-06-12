#ifndef SEMESTRALNI_PRACE_CTOWERGENERIC_H
#define SEMESTRALNI_PRACE_CTOWERGENERIC_H
//CTowerGeneric.h
#include "CTower.h"
/**
 * Derived class inherited from base class CTower representing generic tower
 */
class CTowerGeneric: public CTower{
    public:
     CTowerGeneric(char symbol, int _price, int _range, int _dmg, const std::string& _color, int id);
     CTower* clone() const override;
     std::string getType()const override;
};

#endif //SEMESTRALNI_PRACE_CTOWERGENERIC_H
