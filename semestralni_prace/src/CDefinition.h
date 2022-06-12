#ifndef SEMESTRALNI_PRACE_CDEFINITION_H
#define SEMESTRALNI_PRACE_CDEFINITION_H
//CDefinition.h
#include <vector>
#include <memory>
#include "CEnemy.h"
#include "CTower.h"

/**
 * Class for loading tower/enemies definitions from file
 */
class CDefinition{
    public:
     /**
      * Method for loading enemy and tower definition at the same time
      * @param tower_src source path leading to towers definition
      * @param enemy_src source path leading to enemies definition
      * @return true if loading of the definitions was successful
      */
     bool loadDefinitions(std::string tower_src, std::string enemy_src);
     bool loadEnemyDef(std::string src);
     bool loadTowerDef(std::string src);
     std::vector<std::unique_ptr<CTower>>& getTowerDefinition();
     std::vector<std::unique_ptr<CEnemy>>& getEnemyDefinition();
    private:
     std::vector<std::unique_ptr<CEnemy>> enemy;/**vector of base class pointers to contain all the enemies*/
     std::vector<std::unique_ptr<CTower>> tower;/**vector of base class pointers to contain all the towers*/
};
#endif //SEMESTRALNI_PRACE_CDEFINITION_H
