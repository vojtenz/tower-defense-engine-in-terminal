//CTowerGeneric.cpp
#include "CTowerGeneric.h"
CTowerGeneric::CTowerGeneric(char symbol, int _price, int _range, int _dmg, const std::string &_color, int id)
                : CTower(symbol,_price,_range,_dmg,_color,id){
}

CTower* CTowerGeneric::clone() const {
    return new CTowerGeneric(*this);
}

std::string CTowerGeneric::getType() const {
    return "tower_generic";
}
