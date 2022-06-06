#ifndef SEMESTRALNI_PRACE_CACTIVETILE_H
#define SEMESTRALNI_PRACE_CACTIVETILE_H
//CActiveTile.h
#include "CTile.h"
/**
 * Class inherited from CTile representing tiles which coordinates are needed
 */
class CActiveTile: public CTile{
    public:
     explicit CActiveTile(char symbol, int _pos_x = -1, int _pos_y = -1);
     int pos_x;
     int pos_y;
};

#endif //SEMESTRALNI_PRACE_CACTIVETILE_H
