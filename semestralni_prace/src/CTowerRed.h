#ifndef SEMESTRALNI_PRACE_CTOWERRED_H
#define SEMESTRALNI_PRACE_CTOWERRED_H
//CTowerRed.h
#include "CTower.h"

class CTowerRed: public CTower{
    public:
     CTowerRed(char symbol, int pos_x, int pos_y, int _price, int _range);
     virtual void print(std::ostream& os)const;
     virtual std::string getType()const;
};
#endif //SEMESTRALNI_PRACE_CTOWERRED_H
