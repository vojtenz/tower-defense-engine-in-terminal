//CStart.cpp
#include "CStart.h"

CStart::CStart(char symbol): CTile(symbol){}

std::string CStart::getType() const {
    return "start";
}


