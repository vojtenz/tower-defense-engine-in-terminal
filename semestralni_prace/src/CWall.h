#ifndef SEMESTRALNI_PRACE_CWALL_H
#define SEMESTRALNI_PRACE_CWALL_H

//CWall.h
#include "CTile.h"
/**
 * Class inherited from CTile representing wall
 */
class CWall: public CTile{
public:
    explicit CWall(char symbol = '#');
    std::string getType()const override;
};

#endif //SEMESTRALNI_PRACE_CWALL_H
