#ifndef SEMESTRALNI_PRACE_CSTART_H
#define SEMESTRALNI_PRACE_CSTART_H
//CStart.h
#include "CTile.h"
/**
 * Class inherited from CTile representing starting tile from which are enemies generated
 */
class CStart: public CTile{
public:
    explicit CStart(char symbol = 's');
    std::string getType()const override;
};
#endif //SEMESTRALNI_PRACE_CSTART_H
