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
     * Output stream to which the communication should be went through
     * @param os reference to the output stream
     */
     CDialog(std::ostream& os);

     /**
      * Get option from the user on what he wants to do (a menu)
      * @return int representing some option the user chose
      */
     int getOption();

    /**
     * Lists all available towers to buy
     * @param towers vector containing different towers available
     * @param money parameter is used to print info that the user doesnt have enough money to buy certain tower
     */
     void listTowers(const std::vector<std::unique_ptr<CTower>>& towers, int money)const;

     /**
      * Shows opening credits to the game
      */
     void openingText()const;
    /**
     * Whole process of buying towers
     * @param dialog_map reference to the CMap to check if given coordinates are valid
     * @param towers reference to the vector of all towers later given to method listTowers()
     * @param active_towers reference to the vector of current towers which are in the game
     * @param money reference to the money user has, subtracting if user decides to buy tower
     */
     void buyTower(CMap& dialog_map,const std::vector<std::unique_ptr<CTower>>& towers, std::vector<std::shared_ptr<CTower>>& active_towers, int &money);


private:
    void clearScreen();
    std::ostream& dialog_os;
};
#endif //SEMESTRALNI_PRACE_CDIALOG_H
