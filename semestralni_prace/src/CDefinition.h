#ifndef SEMESTRALNI_PRACE_CDEFINITION_H
#define SEMESTRALNI_PRACE_CDEFINITION_H
//CDefinition.h
#include <vector>
#include "CEnemy.h"
#include "CTower.h"

/**
 * Class for loading definitions from file
 */
class CDefinition{
    public:
     static bool loadEnemyDef(std::vector<CEnemy>& enemy);
     static bool loadTowerDef(std::vector<CTower>& tower);
};
#endif //SEMESTRALNI_PRACE_CDEFINITION_H
