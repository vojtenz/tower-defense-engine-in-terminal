//CActiveTile.cpp
#include "CActiveTile.h"

CActiveTile::CActiveTile(char symbol, int _pos_x, int _pos_y): CTile(symbol){
    pos_x = _pos_x;
    pos_y = _pos_y;
}

int CActiveTile::getX() const {return pos_x;}

int CActiveTile::getY() const {return pos_y;}


