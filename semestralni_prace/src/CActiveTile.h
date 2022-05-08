#ifndef SEMESTRALNI_PRACE_CACTIVETILE_H
#define SEMESTRALNI_PRACE_CACTIVETILE_H
//CActiveTile.h
#include "CTile.h"
/**
 * Class inherited from CTile representing tiles which coordinates are needed
 */
class CActiveTile: public CTile{
    public:
     CActiveTile(char symbol, int _pos_x, int _pos_y);

     /**
      * Returns X coordinates of the CActiveTile class
      * @return X coordinates
      */
     int getX()const;

    /**
     * Returns Y coordinates of the CActiveTile class
     * @return Y coordinates
     */
     int getY()const;

    protected:
        int pos_x;
        int pos_y;
};

#endif //SEMESTRALNI_PRACE_CACTIVETILE_H
