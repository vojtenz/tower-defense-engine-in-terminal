//CTower.cpp
#include "CTower.h"
#include <iomanip>
#include <locale>
CTower::CTower(char symbol, int _price, int _range, int _dmg, const std::string& _color)
                : CActiveTile(symbol), color(_color){
    price=_price;
    range=_range;
    dmg=_dmg;
}

int CTower::getPrice() const {
    return price;
}

int CTower::getRange() const {
    return range;
}

std::string CTower::getType() const {
    return "tower";
}

std::map<std::string, std::string> CTower::initColorMap() {
    std::map<std::string, std::string> map;
    //unfortunately used for enemies when they are about to die
    //map["red"] = "\033[1;31m";
    map["green"] = "\033[1;32m";
    map["brown"] = "\033[1;33m";
    map["blue"] = "\033[1;34m";
    map["purple"] = "\033[1;35m";
    map["yellow"] = "\033[1;33m";
    return map;
}

const std::string &CTower::getColor() const {
    return color;
}
void CTower::print(std::ostream &os) const {
    os << (colorMap.count(color) > 0 ? colorMap.at(color) : "") << symbol << "\033[0m";
}
std::map<std::string, std::string> CTower::colorMap = CTower::initColorMap();

void CTower::printAttribute(std::ostream &os) const {
    os << "Symbol: ";
    print(os);
    os.imbue(std::locale(""));
    os << " | Price: " << std::fixed << price;
    os << " | Range: " << range;
    os << " | Damage: " << dmg;
}

int CTower::getDmg() const {
    return 0;
}
