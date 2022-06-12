//CSaveFile.cpp
#include "CSaveFile.h"
#include <fstream>
#include <tuple>
bool CSaveFile::saveGame(std::string file_destination, std::vector<std::shared_ptr<CTower>>& active_towers, int round,
                         int life, int score) {
    std::ofstream file_stream(file_destination, std::ofstream::out | std::ofstream::trunc);
    if(!file_stream.is_open()) {
        file_stream.close();
        return false;
    }
    file_stream << active_towers.size() << "\n";
    for(auto it = active_towers.begin(); it != active_towers.end(); ++it){
        file_stream << (*it)->getID() << ";" << (*it)->pos_x << ";" << (*it)->pos_y << "\n";
    }
    file_stream << round << "\n";
    file_stream << life << "\n";
    file_stream << score << "\n";
    file_stream.close();
    return true;
}

bool CSaveFile::loadGame(std::string file_destination, CMap& map,std::vector<std::shared_ptr<CTower>>& active_towers, CRound& round_manager,
                         int& life, int& score, CDefinition& definition) {
    std::ifstream file_stream(file_destination);
    int number_of_towers;
    if(!(file_stream >> number_of_towers))return false;
    std::vector<tower> tower_info;
    char delimiter = ';';
    char symbol[2];
    for(int i = 0; i < number_of_towers; ++i){
        int id;
        int pos_x;
        int pos_y;
        file_stream >> id >> symbol[0] >> pos_x >> symbol[1] >> pos_y;
        if(symbol[0] != delimiter || symbol[1] != delimiter)return false;
        tower_info.emplace_back(pos_x,pos_y,id);
    }
    int round;
    if(!(file_stream >> round)) return false;
    int number_of_lives;
    if(!(file_stream >> number_of_lives)) return false;
    int money;
    if(!(file_stream >> money)) return false;
    for(size_t i = 0; i < tower_info.size(); ++i){
        std::shared_ptr<CTower> tmp_shared_ptr(definition.getTowerDefinition().at(tower_info.at(i).id)->clone());
        tmp_shared_ptr->pos_x = tower_info.at(i).pos_x;
        tmp_shared_ptr->pos_y = tower_info.at(i).pos_y;
        active_towers.push_back(tmp_shared_ptr);
        map.at(tower_info.at(i).pos_x,tower_info.at(i).pos_y) = tmp_shared_ptr;
    }
    round_manager.round = round;
    life = number_of_lives;
    score = money;
    return true;
}
