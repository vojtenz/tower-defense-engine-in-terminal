//CTile.cpp
#include "CTile.h"

CTile::CTile(char _symbol): symbol(_symbol){}

void CTile::print(std::ostream &os) const {
    os << symbol;
}

std::ostream& operator << (std::ostream& os, const CTile& ctile){
    ctile.print(os);
    return os;
}

