//CTowerGreen.cpp
#include "CTowerGreen.h"
CTowerGreen::CTowerGreen(char symbol, int price, int range, int dmg)
                        :CTower(symbol, price, range,dmg, "green"){}

std::string CTowerGreen::getType() const {
    return "tower_green";
}

void CTowerGreen::print(std::ostream &os) const {
    os << "\033[1;32m" << symbol << "\033[0m";
}