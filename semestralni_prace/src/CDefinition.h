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
     static bool loadEnemyDef(std::vector<std::unique_ptr<CEnemy>>& enemy, std::string src);
     static bool loadTowerDef(std::vector<std::unique_ptr<CTower>>& tower, std::string src);
};
#endif //SEMESTRALNI_PRACE_CDEFINITION_H
