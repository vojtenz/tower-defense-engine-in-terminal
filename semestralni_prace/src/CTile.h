#ifndef SEMESTRALNI_PRACE_CTILE_H
#define SEMESTRALNI_PRACE_CTILE_H

//CTile.h
#include <ostream>

class CTile{
    protected:
        char symbol;
    public:
     CTile(char _symbol);
     virtual ~CTile() = default;
     virtual void print(std::ostream& os) const;
     virtual std::string getType()const = 0;
};

std::ostream& operator << (std::ostream& os, const CTile& ctile);

#endif //SEMESTRALNI_PRACE_CTILE_H
