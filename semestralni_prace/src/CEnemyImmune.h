#ifndef SEMESTRALNI_PRACE_CENEMYIMMUNE_H
#define SEMESTRALNI_PRACE_CENEMYIMMUNE_H
//CEnemyImmune.h
#include "CEnemy.h"
/**
 * Class representing enemy which is immune to some tower based on its color
 */
class CEnemyImmune: public CEnemy{
    public:
     CEnemyImmune(char symbol, int _health, std::string _tower_color);
     std::string getType()const override;
     const std::string& getImmuneTower() const;
     CEnemy * clone() const override;
     bool towerVisit(CTower *tower_ptr) override;
    private:
     std::string tower_color;
};

#endif //SEMESTRALNI_PRACE_CENEMYIMMUNE_H
