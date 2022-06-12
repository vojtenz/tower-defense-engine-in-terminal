//CDefinition.cpp
#include "CDefinition.h"
#include "CTowerGreen.h"
#include "CEnemyImmune.h"
#include "CTowerGeneric.h"
#include "CEnemyGeneric.h"
#include <fstream>
#include <iostream>
bool CDefinition::loadEnemyDef(std::string src) {
    //in case of multiple loading of the definitions
    if(!enemy.empty())enemy.clear();
    std::ifstream src_file_stream(src);
    while(src_file_stream.good()){
        std::string current_line;
        getline(src_file_stream, current_line);
        int health;
        char symbol;
        char immune[51];
        int err;
        err = sscanf(current_line.c_str(),"%c,%d,%50s",&symbol,&health,immune);
        if(err == 2) {
            enemy.push_back(std::make_unique<CEnemyGeneric>(symbol,health));
            continue;
        }
        if(err == 3) {
            std::string immune_str(immune);
            enemy.push_back(std::make_unique<CEnemyImmune>(symbol,health,immune));
            continue;
        }
        break;
    }
    if(!src_file_stream.eof()) {
        src_file_stream.close();
        return false;
    }
    src_file_stream.close();
    return true;
}

bool CDefinition::loadTowerDef(std::string src) {
    //in case of multiple loading of the definitions
    if(!tower.empty())tower.clear();
    std::ifstream src_file_stream(src);
    int id = 0;
    while(src_file_stream.good()){
        std::string current_line;
        getline(src_file_stream, current_line);
        int price, range,dmg;
        char symbol;
        char color[51];
        if((sscanf(current_line.c_str(), "%c,%d,%d,%d,%50s",&symbol,&price,&range,&dmg,color))==5){
            std::string color_str(color);
            if(color_str == "green"){
                tower.push_back(std::make_unique<CTowerGreen>(symbol,price,range,dmg,id));
            }
            else tower.push_back(std::make_unique<CTowerGeneric>(symbol,price,range,dmg,color,id));
            id++;
        }
        else break;
    }
    if(!src_file_stream.eof()) {
        src_file_stream.close();
        return false;
    }
    src_file_stream.close();
    return true;
}

bool CDefinition::loadDefinitions(std::string tower_src, std::string enemy_src) {
    return (loadTowerDef(tower_src) && loadEnemyDef(enemy_src));
}

std::vector<std::unique_ptr<CTower>> &CDefinition::getTowerDefinition() {
    return tower;
}

std::vector<std::unique_ptr<CEnemy>> &CDefinition::getEnemyDefinition() {
    return enemy;
}

