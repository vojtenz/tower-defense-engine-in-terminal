#ifndef SEMESTRALNI_PRACE_CACTIVETILE_H
#define SEMESTRALNI_PRACE_CACTIVETILE_H
//CActiveTile.h
#include "CTile.h"

class CActiveTile: public CTile{
    public:
     CActiveTile(char symbol, int _pos_x, int _pos_y);
     int getX()const;
     int getY()const;

    protected:
        int pos_x;
        int pos_y;
};

#endif //SEMESTRALNI_PRACE_CACTIVETILE_H
