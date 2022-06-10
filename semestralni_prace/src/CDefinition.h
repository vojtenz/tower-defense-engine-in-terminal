#ifndef SEMESTRALNI_PRACE_CDEFINITION_H
#define SEMESTRALNI_PRACE_CDEFINITION_H
//CDefinition.h
#include <vector>
#include <memory>
#include "CEnemy.h"
#include "CTower.h"

/**
 * Class for loading definitions from file
 */
class CDefinition{
    public:
     bool loadDefinitions(std::string tower_src, std::string enemy_src);
     bool loadEnemyDef(std::string src);
     bool loadTowerDef(std::string src);
    std::vector<std::unique_ptr<CTower>>& getTowerDefinition();
    std::vector<std::unique_ptr<CEnemy>>& getEnemyDefinition();
    private:
     std::vector<std::unique_ptr<CEnemy>> enemy;
     std::vector<std::unique_ptr<CTower>> tower;
};
#endif //SEMESTRALNI_PRACE_CDEFINITION_H
