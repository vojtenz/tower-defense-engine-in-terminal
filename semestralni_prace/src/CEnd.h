#ifndef SEMESTRALNI_PRACE_CEND_H
#define SEMESTRALNI_PRACE_CEND_H
//CEnd.h
#include "CTile.h"
/**
 * Class inherited from CTile representing ending tile
 */
class CEnd: public CTile{
public:
    explicit CEnd(char symbol = 'x');
    std::string getType()const override;
};
#endif //SEMESTRALNI_PRACE_CEND_H
