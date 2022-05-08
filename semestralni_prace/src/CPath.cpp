//CPath.cpp
#include "CPath.h"

CPath::CPath(): CTile('.'){}

std::string CPath::getType() const {
    return "path";
}
