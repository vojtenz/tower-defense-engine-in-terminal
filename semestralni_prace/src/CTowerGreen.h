#ifndef SEMESTRALNI_PRACE_CTOWERGREEN_H
#define SEMESTRALNI_PRACE_CTOWERGREEN_H
//CTowerGreen.h
#include "CTower.h"
/**
 * Class inherited from CActiveTile representing green tower
 */
class CTowerGreen: public CTower{
    public:
     CTowerGreen(char symbol, int price, int range, int dmg);
     std::string getType()const override;
     CTower * clone() const override;
};
#endif //SEMESTRALNI_PRACE_CTOWERGREEN_H
