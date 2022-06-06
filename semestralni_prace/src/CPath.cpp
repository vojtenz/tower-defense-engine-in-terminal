//CPath.cpp
#include "CPath.h"

CPath::CPath(char symbol): CTile(symbol){}

std::string CPath::getType() const {
    return "path";
}

bool CPath::isBlock() {return false;}
