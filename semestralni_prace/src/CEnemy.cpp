//CEnemy.cpp
#include "CEnemy.h"

CEnemy::CEnemy(char symbol, int _pos_x, int _pos_y, int _health)
        : CActiveTile(symbol, _pos_x, _pos_y){
        health = _health;
}

std::string CEnemy::getType() const {
    return "enemy";
}
