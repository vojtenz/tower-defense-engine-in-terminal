//CEnemyImmune.cpp
#include "CEnemyImmune.h"

CEnemyImmune::CEnemyImmune(char symbol, int _health,const std::string& _tower_color)
                : CEnemy(symbol, _health), tower_color(_tower_color){
}

std::string CEnemyImmune::getType() const {
    return "enemy_immune";
}

std::string CEnemyImmune::getImmuneTower() const {
    return tower_color;
}
