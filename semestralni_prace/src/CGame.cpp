//CGame.cpp
#include <iostream>
#include "CGame.h"
#include "CDefinition.h"
#include <unistd.h>
bool CGame::start() {
    bool running = true;
    bool save = false;
    //dialog.openingText();
    std::vector<std::shared_ptr<CTower>> active_towers;
    while(running){
            int option;
        do{
            render();
            option = dialog.getOption();
            if (option <= 0) {
                save = (option == 0 ? true : false);
                running = false;
                break;
            }
            if (option == 2) {
                std::cout << "Buying towers..\n";
                //usleep(1000000);
                dialog.buyTower(map, definition.getTowerDefinition(),active_towers, score);
            }
        }while(option!=1);
        if(option == -2){
            clearScreen();
            std::cout << "Goodbye!\n";
        }
        if(!running)break;
        std::cout << "Init round..\n";
        usleep(1000000);
        std::cout << "Starting round..\n";
        usleep(1000000);
    }
}

void CGame::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void CGame::render() {
    clearScreen();
    std::cout << "Score: " << score << "\n";
    std::cout << "Life: " << heart << "\n\n";
    map.renderMap(std::cout,false);
}

bool CGame::init() {
    if(!map.initMap("./examples/map/map.txt")) {
        std::cout << "Error while loading map\n";
        return false;
    }
    if(!definition.loadTowerDef("./examples/definition/tower_def.csv")){
        std::cout << "Error while loading towers definition\n";
        return false;
    }
    if(!definition.loadEnemyDef("./examples/definition/enemy_def.csv")){
        std::cout << "Error while loading enemies definition\n";
        return false;
    }
    return true;
}

void CGame::initRound() {

}

CGame::CGame(int starting_score, int number_of_life): dialog(std::cout) {
    score = starting_score;
    heart = number_of_life;
}

