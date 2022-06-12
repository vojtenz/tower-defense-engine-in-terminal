#ifndef SEMESTRALNI_PRACE_CROUND_H
#define SEMESTRALNI_PRACE_CROUND_H
//CRound.h
#include <memory>
#include <vector>
#include <deque>
#include "CEnemy.h"
#include "CMap.h"
#include "CDefinition.h"
/**
 * Class for managing rounds for the game
 */
class CRound{
    public:
     CRound();
     /**
      * Initialize one round based on round number, prepares the queue for enemies to be coming from
      * @param enemy_definition reference to the enemy definitions for generating enemies for the current round
      */
     void initRound(CDefinition& enemy_definition);
     /**
      * Removing dead enemies from the map and disabling them in in_game_round_enemies
      * @param map reference to the CMap map
      * @param money reference to the users score(money) to give money for dead enemies
      */
     void removeEnemies(CMap& map, int& money);
     /**
      * Move enemies step ahead
      * @param map reference to the CMap map where should the enemies be moving
      * @param enemy_def reference to the enemies definition
      * @param health users health, if enemies reach the end, users loses health
      */
     void moveEnemies(CMap& map,const std::vector<std::unique_ptr<CEnemy>>& enemy_def, int& health);
     /**
      * Makes damage to the enemies which are in the are of some tower
      * @param map reference to the CMap map
      * @param active_towers list of the current towers on the map which can threaten the enemy
      */
     void dealDmg(CMap& map, std::vector<std::shared_ptr<CTower>>& active_towers);
     /**
      * Returns true if no alive enemies are on the map and no others will keep coming
      * @return true/false
      */
     bool noEnemies();
     int round = 1;
    private:
     std::vector<std::shared_ptr<CEnemy>> in_game_round_enemies;/** enemies currently visible on the map and to the towers*/
     std::deque<size_t> round_enemies_queue; /**queue prepared for each round full of what enemies will be coming*/
     char char_step[4];
     int x_next_pos[4];
     int y_next_pos[4];
};
#endif //SEMESTRALNI_PRACE_CROUND_H
