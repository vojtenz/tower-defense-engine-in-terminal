//CTowerRed.cpp
#include "CTowerRed.h"

CTowerRed::CTowerRed(char symbol, int pos_x, int pos_y, int price, int range)
                    : CTower(symbol,pos_x, pos_y, price, range, "red"){}

std::string CTowerRed::getType() const {
    return "tower_red";
}

void CTowerRed::print(std::ostream &os) const {
    os << "\033[1;31m" << symbol << "\033[0m";
}