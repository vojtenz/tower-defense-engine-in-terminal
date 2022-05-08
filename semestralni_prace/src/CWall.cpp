//CWall.cpp
#include "CWall.h"

CWall::CWall(): CTile('#'){}

std::string CWall::getType() const {
    return "wall";
}
