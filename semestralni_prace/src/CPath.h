
#ifndef SEMESTRALNI_PRACE_CPATH_H
#define SEMESTRALNI_PRACE_CPATH_H
//CPath.h
#include "CTile.h"

class CPath: public CTile{
    public:
     CPath();
     virtual std::string getType()const;
};


#endif //SEMESTRALNI_PRACE_CPATH_H
