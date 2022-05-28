#ifndef SEMESTRALNI_PRACE_CSTART_H
#define SEMESTRALNI_PRACE_CSTART_H
//CStart.h
#include "CTile.h"
/**
 * Class inherited from CTile representing starting tile
 */
class CStart: public CTile{
public:
    CStart();
    virtual std::string getType()const;
};
#endif //SEMESTRALNI_PRACE_CSTART_H
