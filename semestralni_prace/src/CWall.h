#ifndef SEMESTRALNI_PRACE_CWALL_H
#define SEMESTRALNI_PRACE_CWALL_H

//CWall.h
#include "CTile.h"

class CWall: public CTile{
public:
    CWall();
    virtual std::string getType()const;
};

#endif //SEMESTRALNI_PRACE_CWALL_H