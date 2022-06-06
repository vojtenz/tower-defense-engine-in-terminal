
#ifndef SEMESTRALNI_PRACE_CPATH_H
#define SEMESTRALNI_PRACE_CPATH_H
//CPath.h
#include "CTile.h"
/**
 * Class inherited from CTile representing path
 */
class CPath: public CTile{
    public:
     explicit CPath(char symbol = ':');
     std::string getType()const override;
     bool isBlock() override;
};


#endif //SEMESTRALNI_PRACE_CPATH_H
