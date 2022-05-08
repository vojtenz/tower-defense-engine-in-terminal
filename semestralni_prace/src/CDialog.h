#ifndef SEMESTRALNI_PRACE_CDIALOG_H
#define SEMESTRALNI_PRACE_CDIALOG_H
//CDialog.g
#include "CTower.h"
#include "CMap.h"
#include <vector>
class CDialog{
    public:
     CDialog(std::vector<CTower>& towers, CMap& map);
     int getOption();
     int listTowers();
     void openingText();
     std::pair<int,int> towerCords(int& id_tower);
};
#endif //SEMESTRALNI_PRACE_CDIALOG_H
