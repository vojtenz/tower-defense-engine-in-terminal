#ifndef SEMESTRALNI_PRACE_CENEMY_H
#define SEMESTRALNI_PRACE_CENEMY_H
//CEnemy.h
#include "CActiveTile.h"
/**
 * Class inherited from CActiveTile representing the enemy
 */
class CEnemy: public CActiveTile{
    public:
     CEnemy(char symbol, int _pos_x, int _pos_y, int _health);
     virtual std::string getType()const;
     int health;
};

#endif //SEMESTRALNI_PRACE_CENEMY_H
