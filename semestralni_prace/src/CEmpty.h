#ifndef SEMESTRALNI_PRACE_CEMPTY_H
#define SEMESTRALNI_PRACE_CEMPTY_H

//CEmpty.h
#include "CTile.h"
/**
 * Class inherited from CTile representing empty space
 */
class CEmpty: public CTile{
    public:
     CEmpty();
     virtual std::string getType()const;
};


#endif //SEMESTRALNI_PRACE_CEMPTY_H
