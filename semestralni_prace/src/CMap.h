#ifndef SEMESTRALNI_PRACE_CMAP_H
#define SEMESTRALNI_PRACE_CMAP_H
//CMap.h
#include "CTile.h"
#include <vector>
#include <memory>
#include <ostream>

class CMap{
    CMap() = default;
    CTile& at(int x);
    CTile& at(int x, int y);
    bool loadMapfromFile(std::string src);
    void renderMap(std::ostream& os);
    int getWidth();
    int getHeight();

    private:
     int width;
     int height;
     std::vector<std::shared_ptr<CTile>> map;
};
#endif //SEMESTRALNI_PRACE_CMAP_H
