//CDialog.cpp
#include "CDialog.h"
#include <unistd.h>
#include <iostream>
#include <climits>
#include <iomanip>
#include <climits>
#define EOF_CODE -2
#define START_ROUND 1
#define BUY_TOWERS 2
#define QUIT_GAME_WITH_SAVE 0
#define QUIT_GAME_NO_SAVE -1
#define QUIT_BUY -3

CDialog::CDialog(CMap &map, std::ostream& os):dialog_map(map), dialog_os(os){}

int CDialog::getOption() {
    dialog_os << "Menu:\n";
    int option = 0;
    dialog_os << "1) start round\n2) buy towers\n3) quit game\n";
    while((!(std::cin >> option) || option<=0 || option >3) && !std::cin.eof()){
        dialog_os << "Incorrect input, please enter correct option (1,2,3)\n";
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');
    }
    if(std::cin.eof()) {
        return EOF_CODE;
    }
    char answer = 0;
    if(option == 3){
        dialog_os << "Do you wish to save the game? y/n\n";
        while((!(std::cin >> answer) || (answer != 'y' && answer !='n')) && !std::cin.eof()){
            dialog_os << "Please enter 'y' for yes and 'n' for no\n";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        if(std::cin.eof()) return EOF_CODE;
        return answer == 'y' ? QUIT_GAME_WITH_SAVE : QUIT_GAME_NO_SAVE;
    }
    return option;
}

void CDialog::openingText() const{
    dialog_os << "\033[2J\033[1;1H";
    dialog_os << "Tower defense game represented in the terminal made by Vojtech Hejlek\n";
    usleep(2000000);
    dialog_os << "\033[2J\033[1;1H";
}

void CDialog::listTowers(const std::vector<std::unique_ptr<CTower>>& towers, int money)const{
    for(size_t i = 0; i < towers.size(); ++i){
        dialog_os << "ID: " << i << " | ";
        towers.at(i)->printAttribute(dialog_os);
        dialog_os << (money < towers.at(i)->getPrice() ? "\033[1;31m (Not enough money)" : "") << "\033[0m";
        dialog_os << "\n";
    }
}

void CDialog::buyTower(CMap &map, const std::vector<std::unique_ptr<CTower>> &towers, int money) {
    //while(true){
        clearScreen();
        dialog_os << "Money: " << money << "\n\n";
        map.renderMap(dialog_os, true);
        dialog_os << std::string(2,'\n');
        listTowers(towers,money);
        dialog_os << "\nChoose ID of the tower you want to buy or type 'q' if you are done buying towers:\n";
        int tower_id = -1;
        bool expected_exit = false;
        std::string line;
        std::istringstream isstream;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        while(getline(std::cin,line)){
            if(!line.empty() && line.at(0) == 'q') {
                expected_exit = true;
                return;
            }
            isstream.clear();
            isstream.str(line);
            if((!(isstream >> tower_id)) || tower_id<0 || tower_id >= towers.size()){
                dialog_os << "Please select valid tower ID\n";
                continue;
            }
            if(towers.at(tower_id)->getPrice()>money){
                dialog_os << "You dont have enough money for this one!\n";
                continue;
            }
            expected_exit = true;
            break;
        }
        if(!expected_exit) {
            return;
        }
        int x,y;
        dialog_os << "Select coordinates(x,y) you wish to put tower at (for example: '5 4'):\n";
        while((!(std::cin >> x >> y) || x < 0 || y < 0 || x >= map.getHeight() || y >=map.getWidth() || !map.at(x,y)->isPlaceable()) && !std::cin.eof()){
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
            if(!map.at(x,y)->isPlaceable()){
                dialog_os << "You cant put tower at this place!\n";
                continue;
            }
            dialog_os << "Please select valid coordinates based on the map as 'x y'\n";
        }
        if(std::cin.eof())return;
        clearScreen();
        map.renderMap(dialog_os, true, x, y,towers.at(tower_id).get());
        char answ = 0;
        dialog_os << "Do you want to place tower like this? (y/n)\n";
        while((!(std::cin >> answ) || (answ != 'y' && answ !='n')) && !std::cin.eof()){
            dialog_os << "Please enter 'y' for yes and 'n' for no\n";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        if(std::cin.eof())return;
        if(answ == 'y'){

        }

}

void CDialog::clearScreen() {
    dialog_os << "\033[2J\033[1;1H";
}


