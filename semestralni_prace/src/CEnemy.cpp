//CEnemy.cpp
#include "CEnemy.h"

CEnemy::CEnemy(char symbol, int _health)
        : CActiveTile(symbol){
        starting_health = _health;
        health = starting_health;
}

void CEnemy::print(std::ostream &os) const {
    os << (health <= 0 ? bleeding_color : "") << symbol << "\033[0m";
}

std::string CEnemy::bleeding_color = "\033[0;31m";

int CEnemy::getStartingHealth()const{
    return starting_health;
}
