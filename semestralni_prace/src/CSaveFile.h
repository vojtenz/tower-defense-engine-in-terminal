#ifndef SEMESTRALNI_PRACE_CSAVEFILE_H
#define SEMESTRALNI_PRACE_CSAVEFILE_H
#include <string>
#include <vector>
#include "CTower.h"
#include "CDefinition.h"
#include "CRound.h"
class CSaveFile{
    public:
        CSaveFile() = default;
        bool saveGame(std::string file_destination, std::vector<std::shared_ptr<CTower>>& active_towers, int round,int life, int score);
        bool loadGame(std::string file_destination, CMap& map,std::vector<std::shared_ptr<CTower>>& active_towers, CRound& round_manager, int& life, int& score, CDefinition& definition);
    private:
        struct tower{
            tower(int _x, int _y, int _id){
                pos_x = _x;
                pos_y = _y;
                id = _id;
            }
            int pos_x;
            int pos_y;
            int id;
        };
};
#endif //SEMESTRALNI_PRACE_CSAVEFILE_H
