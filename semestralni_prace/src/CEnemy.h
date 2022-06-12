#ifndef SEMESTRALNI_PRACE_CENEMY_H
#define SEMESTRALNI_PRACE_CENEMY_H
//CEnemy.h
#include "CActiveTile.h"
#include "CTower.h"
/**
 * Abstract class inherited from CActiveTile representing all enemies
 */
class CEnemy: public CActiveTile{
    public:
     CEnemy(char symbol, int _health);
     virtual ~CEnemy() = default;
     void print(std::ostream& os) const override;
     /**
      * Returns CEnemy pointer representing the new instance of derived class
      * @return CEnemy pointer representing the new instance of derived class
      */
     virtual CEnemy* clone()const = 0;
     /**
      * Pure virtual method
      * @param tower_ptr CTower pointer
      * @return true/false if enemy is in the shooting range of the tower
      */
     virtual bool towerVisit(CTower* tower_ptr) = 0;
     /**
      * Returns health which the enemy started with
      * @return health which the enemy started with
      */
     int getStartingHealth()const;
     int health;
     int step = 0;
    private:
     int starting_health;
     static std::string bleeding_color; /**color represented as unix color sequence to represent dying enemy*/
};

#endif //SEMESTRALNI_PRACE_CENEMY_H
