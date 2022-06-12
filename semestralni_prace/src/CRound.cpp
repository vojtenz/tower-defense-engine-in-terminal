//CRound.cpp
#include "CRound.h"
#include <algorithm>
#include "CEmpty.h"
#include "CPath.h"
#include "CEnd.h"

CRound::CRound(): char_step{'U','D','L','R'}, x_next_pos{-1,1,0,0}, y_next_pos{0,0,-1,1}{
}

void CRound::initRound(CDefinition& enemy_definition){
    if(!in_game_round_enemies.empty())in_game_round_enemies.clear();
    if(!round_enemies_queue.empty())round_enemies_queue.clear();
    for(size_t i = 0; i < enemy_definition.getEnemyDefinition().size(); ++i){
        for(size_t j = 0; j < round/((i*2)+1); ++j){
            round_enemies_queue.push_back(i);
        }
    }
}

void CRound::removeEnemies(CMap& map, int& money) {
    std::shared_ptr<CPath> tmp_path(new CPath);
    for(auto it = in_game_round_enemies.begin(); it != in_game_round_enemies.end(); ++it){
        if((*it)!=nullptr && (*it)->health <=0){
            map.at((*it)->pos_x,(*it)->pos_y) = tmp_path;
            money+=(*it)->getStartingHealth()/5;
            (*it) = nullptr;
        }
    }

}
void CRound::moveEnemies(CMap &map,const std::vector<std::unique_ptr<CEnemy>>& enemy_def, int& player_health) {
    if(!round_enemies_queue.empty()){
        in_game_round_enemies.push_back(std::shared_ptr<CEnemy>(enemy_def.at(round_enemies_queue.front())->clone()));
        in_game_round_enemies.back()->pos_x = map.getStartPos().first;
        in_game_round_enemies.back()->pos_y = map.getStartPos().second;
        round_enemies_queue.pop_front();
    }
        std::shared_ptr<CPath> tmp_path(new CPath);
        std::shared_ptr<CEnd> tmp_end(new CEnd);

    for(auto it = in_game_round_enemies.begin(); it != in_game_round_enemies.end();++it) {
        if ((*it) == nullptr)continue;
        char step_dir = map.getPathDirection((*it)->step);
        if (step_dir == 'E'){
            map.at((*it)->pos_x, (*it)->pos_y) = tmp_end;
            player_health-=((*it)->getStartingHealth()/3);
            (*it) = nullptr;
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            if (step_dir != char_step[i]) continue;
            map.at((*it)->pos_x + x_next_pos[i], (*it)->pos_y + y_next_pos[i]) = *it;
            if ((*it)->step != 0)map.at((*it)->pos_x, (*it)->pos_y) = tmp_path;
            (*it)->pos_x += x_next_pos[i];
            (*it)->pos_y += y_next_pos[i];
            (*it)->step++;
        }
    }
}

bool CRound::noEnemies() {
    if(in_game_round_enemies.empty())return false;
    for(auto it = in_game_round_enemies.begin(); it != in_game_round_enemies.end(); ++it){
        if((*it) != nullptr) return false;
    }
    return true;
}

void CRound::dealDmg(CMap &map, std::vector<std::shared_ptr<CTower>>& active_towers) {
    for(auto tower_it = active_towers.begin(); tower_it != active_towers.end(); ++tower_it){
        for(auto enemy_it = in_game_round_enemies.begin(); enemy_it != in_game_round_enemies.end(); ++enemy_it){
            if((*enemy_it)==nullptr)continue;
            if((*enemy_it)->towerVisit((*tower_it).get()) == true){
                break;
            }
        }
    }
}