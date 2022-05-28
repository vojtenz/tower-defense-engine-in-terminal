//CEmpty.cpp
#include "CEmpty.h"

CEmpty::CEmpty(): CTile(' '){}

std::string CEmpty::getType() const {
    return "empty";
}

