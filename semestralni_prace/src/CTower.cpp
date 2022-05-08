//CTower.cpp
#include "CTower.h"


CTower::CTower(char symbol, int pos_x, int pos_y, int _price, int _range, std::string _color)
                : CActiveTile(symbol, pos_x, pos_y){
    price=_price;
    range=_range;
    color=_color;
}

int CTower::getPrice() const {
    return price;
}

int CTower::getRange() const {
    return range;
}

std::string CTower::getType() const {
    return "tower";
}