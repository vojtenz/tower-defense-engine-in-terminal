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
     CEnemyImmune(char symbol, int _health, const std::string& _tower_color);
     std::string getType()const override;
     std::string getImmuneTower() const;
    private:
     std::string tower_color;
};

#endif //SEMESTRALNI_PRACE_CENEMYIMMUNE_H
