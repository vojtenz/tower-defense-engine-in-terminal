//CTowerGreen.cpp
#include "CTowerGreen.h"
CTowerGreen::CTowerGreen(char symbol, int price, int range, int dmg, int id)
                        :CTower(symbol, price, range,dmg, "green", id){}

std::string CTowerGreen::getType() const {
    return "tower_green";
}

CTower* CTowerGreen::clone() const {
    return new CTowerGreen(*this);
}
