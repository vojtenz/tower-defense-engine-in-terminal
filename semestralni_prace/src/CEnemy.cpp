//CEnemy.cpp
#include "CEnemy.h"

CEnemy::CEnemy(char symbol, int _health)
        : CActiveTile(symbol){
        health = _health;
}


std::string CEnemy::getType() const {
    return "enemy";
}

void CEnemy::print(std::ostream &os) const {
    os << (health <= 0 ? bleeding_color : "") << symbol << "\033[0m";
}

std::string CEnemy::bleeding_color = "\033[0;31m";