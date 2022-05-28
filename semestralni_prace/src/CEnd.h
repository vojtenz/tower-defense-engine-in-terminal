#ifndef SEMESTRALNI_PRACE_CEND_H
#define SEMESTRALNI_PRACE_CEND_H
//CEnd.h
#include "CTile.h"
/**
 * Class inherited from CTile representing ending tile
 */
class CEnd: public CTile{
public:
    CEnd();
    virtual std::string getType()const;
};
#endif //SEMESTRALNI_PRACE_CEND_H
