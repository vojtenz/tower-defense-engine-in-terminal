//CWall.cpp
#include "CWall.h"

CWall::CWall(char symbol): CTile(symbol){}

std::string CWall::getType() const {
    return "wall";
}
