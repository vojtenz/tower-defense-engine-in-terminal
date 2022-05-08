//CTowerGreen.cpp
#include "CTowerGreen.h"
CTowerGreen::CTowerGreen(char symbol, int pos_x, int pos_y, int price, int range)
                        :CTower(symbol, pos_x, pos_y, price, range, "green"){}

std::string CTowerGreen::getType() const {
    return "tower_green";
}

void CTowerGreen::print(std::ostream &os) const {
    os << "\033[1;32m" << symbol << "\033[0m";
}