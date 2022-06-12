//CEnemyImmune.cpp
#include "CEnemyImmune.h"

CEnemyImmune::CEnemyImmune(char symbol, int _health,std::string _tower_color)
                : CEnemy(symbol, _health), tower_color(_tower_color){
}

std::string CEnemyImmune::getType() const {
    return "enemy_immune";
}

const std::string& CEnemyImmune::getImmuneTower() const {
    return tower_color;
}

CEnemy* CEnemyImmune::clone() const {
    return new CEnemyImmune(*this);
}

bool CEnemyImmune::towerVisit(CTower *tower_ptr) {
    if(this->tower_color != tower_ptr->getColor()
       && this->pos_x >= tower_ptr->pos_x-tower_ptr->getRange()
       && this->pos_x <= tower_ptr->pos_x+tower_ptr->getRange()
       && this->pos_y >= tower_ptr->pos_y-tower_ptr->getRange()
       && this->pos_y <= tower_ptr->pos_y+tower_ptr->getRange()){
        this->health -= tower_ptr->getDmg();
        return true;
    }
    return false;
}
