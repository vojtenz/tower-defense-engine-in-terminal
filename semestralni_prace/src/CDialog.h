#ifndef SEMESTRALNI_PRACE_CDIALOG_H
#define SEMESTRALNI_PRACE_CDIALOG_H
//CDialog.g
#include "CTower.h"
#include "CMap.h"
#include <vector>
/**
 * Class used for communicating with the user
 *
 */
class CDialog{
    public:
    /**
     * Tower definitions reference and map reference needed for checking valid answers from the user
     * @param towers reference tower definitions
     * @param map reference to map
     */
     CDialog(std::vector<CTower>& towers, CMap& map);

     /**
      * Get option from the user on what he wants to do (a menu)
      * @return int representing some option
      */
     int getOption();

     /**
      * Lists aviliable towers to buy
      *
      * @return
      */
     void listTowers();

     /**
      * Shows opening credits to the game
      *
      */
     void openingText();

     /**
      * Get from user coordinates and id of the tower he wants to buy
      * @param id_tower input/output reference to what id of the tower user chose
      * @return pair representing coordinates on the map
      */
     std::pair<int,int> towerCords(int& id_tower);
};
#endif //SEMESTRALNI_PRACE_CDIALOG_H
