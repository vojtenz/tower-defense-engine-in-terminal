//CEnemyImmune.cpp
#include "CEnemyImmune.h"

CEnemyImmune::CEnemyImmune(char symbol, int _pos_x, int _pos_y, int _health, std::string _tower_color)
                : CEnemy(symbol, _pos_x, _pos_y, _health){
            tower_color = _tower_color;
}

std::string CEnemyImmune::getType() const {
    return "enemy_immune";
}

std::string CEnemyImmune::getImmuneTower() const {
    return tower_color;
}
