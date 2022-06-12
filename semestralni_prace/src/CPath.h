
#ifndef SEMESTRALNI_PRACE_CPATH_H
#define SEMESTRALNI_PRACE_CPATH_H
//CPath.h
#include "CTile.h"
/**
 * Class inherited from CTile representing path on which enemies are moving towards the ending tile
 */
class CPath: public CTile{
    public:
     explicit CPath(char symbol = ':');
     std::string getType()const override;
};


#endif //SEMESTRALNI_PRACE_CPATH_H
