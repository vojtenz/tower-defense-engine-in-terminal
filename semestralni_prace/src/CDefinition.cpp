//CDefinition.cpp
#include "CDefinition.h"
#include "CTowerGreen.h"
#include "CEnemyImmune.h"
#include <fstream>
#include <iostream>
#include <sstream>
bool CDefinition::loadEnemyDef(std::vector<std::unique_ptr<CEnemy>>& enemy, std::string src) {
    std::ifstream src_file_stream(src);
    while(src_file_stream.good()){
        std::string current_line;
        getline(src_file_stream, current_line);
        int health;
        char symbol;
        char immune[51];
        int err;
        err = sscanf(current_line.c_str(),"%c,%d,%50s",&symbol,&health,immune);
        if(err == 2) enemy.push_back(std::make_unique<CEnemy>(symbol,health));
        std::string immune_str(immune);
        if(err == 3) enemy.push_back(std::make_unique<CEnemyImmune>(symbol,health,immune));
    }
    if(!src_file_stream.eof()) return false;
}

bool CDefinition::loadTowerDef(std::vector<std::unique_ptr<CTower>> &tower, std::string src) {
    std::ifstream src_file_stream(src);
    while(src_file_stream.good()){
        std::string current_line;
        getline(src_file_stream, current_line);
        int price, range,dmg;
        char symbol;
        char color[51];
        if((sscanf(current_line.c_str(), "%c,%d,%d,%d,%50s",&symbol,&price,&range,&dmg,color))==5){
            std::string color_str(color);
            if(color_str == "green"){
                tower.push_back(std::make_unique<CTowerGreen>(symbol,price,range,dmg));
            }
            else tower.push_back(std::make_unique<CTower>(symbol,price,range,dmg,color));
        }
        else break;
    }
    if(!src_file_stream.eof()) return false;
}
