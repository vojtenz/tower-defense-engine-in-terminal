#ifndef SEMESTRALNI_PRACE_CENEMYGENERIC_H
#define SEMESTRALNI_PRACE_CENEMYGENERIC_H
//CEnemyGeneric.h
#include "CEnemy.h"
/**
 * Class representing generic enemy
 */
class CEnemyGeneric: public CEnemy{
    public:
     CEnemyGeneric(char symbol, int _health);
     std::string getType()const override;
     CEnemy * clone() const override;
     bool towerVisit(CTower *tower_ptr) override;
};
#endif //SEMESTRALNI_PRACE_CENEMYGENERIC_H
