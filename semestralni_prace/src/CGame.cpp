//CGame.cpp
#include <iostream>
#include "CGame.h"
#include "CDefinition.h"
#include <unistd.h>
#include "CSaveFile.h"
void CGame::start() {
    bool running = true;
    bool save = false;
    CSaveFile saveFile;
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
            if (option == 2) dialog.buyTower(map, definition.getTowerDefinition(),active_towers, score);
            if (option == 4) {
                if(!saveFile.loadGame("./examples/save/save_file.txt",map,active_towers,round_manager,heart,score,definition)){
                    std::cout << "Loading save file failed\n";
                }
            }
        }while(option!=1);

        if(option == -2){
            clearScreen();
            std::cout << "Goodbye!\n";
        }

        if(!running)break;
        round_manager.initRound(definition);

        while(heart>0){
            round_manager.dealDmg(map,active_towers);
            render();
            usleep(90000);
            round_manager.removeEnemies(map,score);
            round_manager.moveEnemies(map,definition.getEnemyDefinition(),heart);
            if(round_manager.noEnemies())break;
        }
        if(heart<=0){
            clearScreen();
            render();
            std::cout << "GAME OVER!\n";
            return;
        }
        round_manager.round++;
    }
    if(save == true){
        if(!saveFile.saveGame("./examples/save/save_file.txt",active_towers,round_manager.round,heart,score)){
            std::cout << "Unable to save the game\n";
        }
    }
}

void CGame::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void CGame::render() {
    clearScreen();
    std::cout << "Round: " << round_manager.round << "\n";
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

CGame::CGame(int starting_score, int number_of_life): dialog(std::cout){
    score = starting_score;
    heart = number_of_life;
}

