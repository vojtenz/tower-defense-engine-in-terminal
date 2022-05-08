#ifndef SEMESTRALNI_PRACE_CENEMYIMMUNE_H
#define SEMESTRALNI_PRACE_CENEMYIMMUNE_H
//CEnemyImmune.h
#include "CEnemy.h"
/**
 * Class representing enemy which is immune to some tower
 *
 */
class CEnemyImmune: public CEnemy{
    public:
     CEnemyImmune(char symbol, int _pos_x, int _pos_y, int _health, std::string _tower);
     virtual std::string getType()const;
     std::string getImmuneTower() const;
    private:
     std::string tower_color;
};

#endif //SEMESTRALNI_PRACE_CENEMYIMMUNE_H
