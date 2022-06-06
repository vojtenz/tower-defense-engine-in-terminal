//CEnd.cpp
#include "CEnd.h"

CEnd::CEnd(char symbol): CTile(symbol){}

std::string CEnd::getType() const {
    return "end";
}


