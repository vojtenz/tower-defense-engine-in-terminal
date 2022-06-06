#ifndef SEMESTRALNI_PRACE_CENEMY_H
#define SEMESTRALNI_PRACE_CENEMY_H
//CEnemy.h
#include "CActiveTile.h"
/**
 * Class inherited from CActiveTile representing the enemy
 */
class CEnemy: public CActiveTile{
    public:
     CEnemy(char symbol, int _health);
     std::string getType()const override;
     void print(std::ostream& os) const override;
     int health;
    private:
     static std::string bleeding_color;
};

#endif //SEMESTRALNI_PRACE_CENEMY_H
