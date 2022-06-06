//CEmpty.cpp
#include "CEmpty.h"

CEmpty::CEmpty(char symbol): CTile(symbol){}

std::string CEmpty::getType() const {
    return "empty";
}

bool CEmpty::isBlock() {return false;}

bool CEmpty::isPlaceable() {return true;}

