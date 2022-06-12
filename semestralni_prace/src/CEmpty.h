#ifndef SEMESTRALNI_PRACE_CEMPTY_H
#define SEMESTRALNI_PRACE_CEMPTY_H

//CEmpty.h
#include "CTile.h"
/**
 * Class inherited from CTile representing empty space
 */
class CEmpty: public CTile{
    public:
     explicit CEmpty(char symbol = ' ');
     std::string getType()const override;
     bool isPlaceable() override;
};


#endif //SEMESTRALNI_PRACE_CEMPTY_H
