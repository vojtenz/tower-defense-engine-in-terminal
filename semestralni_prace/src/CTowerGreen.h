#ifndef SEMESTRALNI_PRACE_CTOWERGREEN_H
#define SEMESTRALNI_PRACE_CTOWERGREEN_H
//CTowerGreen.h
#include "CTower.h"
/**
 * Class inherited from CActiveTile representing green tower
 */
class CTowerGreen: public CTower{
    public:
     CTowerGreen(char symbol, int pos_x, int pos_y, int price, int range);
     virtual std::string getType()const;
     virtual void print(std::ostream& os)const;

};
#endif //SEMESTRALNI_PRACE_CTOWERGREEN_H
