//CEnemyGeneric.cpp
#include "CEnemyGeneric.h"

CEnemyGeneric::CEnemyGeneric(char symbol, int _health): CEnemy(symbol,_health) {

}

std::string CEnemyGeneric::getType() const {
    return "enemy_generic";
}

CEnemy* CEnemyGeneric::clone() const {
    return new CEnemyGeneric(*this);
}

bool CEnemyGeneric::towerVisit(CTower *tower_ptr) {
    if(this->pos_x >= tower_ptr->pos_x-tower_ptr->getRange()
    && this->pos_x <= tower_ptr->pos_x+tower_ptr->getRange()
    && this->pos_y >= tower_ptr->pos_y-tower_ptr->getRange()
    && this->pos_y <= tower_ptr->pos_y+tower_ptr->getRange()){
        this->health -= tower_ptr->getDmg();
        return true;
    }
    return false;
}
