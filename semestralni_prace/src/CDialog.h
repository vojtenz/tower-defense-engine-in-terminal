#ifndef SEMESTRALNI_PRACE_CDIALOG_H
#define SEMESTRALNI_PRACE_CDIALOG_H
//CDialog.g
#include "CTower.h"
#include "CMap.h"
#include <vector>
#include <memory>
/**
 * Class used for communicating with the user
 */
class CDialog{
    public:
    /**
     * Tower definitions reference and map reference needed for checking valid answers from the user
     * @param towers reference tower definitions
     * @param map reference to map
     */
     CDialog(CMap& map, std::ostream& os);

     /**
      * Get option from the user on what he wants to do (a menu)
      * @return int representing some option
      */
     int getOption();

     /**
      * Lists aviliable towers to buy
      * @return
      */
     void listTowers(const std::vector<std::unique_ptr<CTower>>& towers, int money)const;

     /**
      * Shows opening credits to the game
      */
     void openingText()const;

     void buyTower(CMap& dialog_map,const std::vector<std::unique_ptr<CTower>>& towers, int money);


private:
    void clearScreen();
    CMap& dialog_map;
    std::ostream& dialog_os;
};
#endif //SEMESTRALNI_PRACE_CDIALOG_H
