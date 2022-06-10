#ifndef SEMESTRALNI_PRACE_CGAME_H
#define SEMESTRALNI_PRACE_CGAME_H
//CGame.h
#include "CMap.h"
#include "CDefinition.h"
#include "CDialog.h"
/**
 * Main class for the whole game system
 *
 */
class CGame{
    public:
     CGame(int starting_score = 250, int number_of_life = 150);
     bool start();
     bool init();
     void clearScreen();
     void render();
     bool createEnemyLine();
     /**
      * Round initiliazation
      */
     void initRound();
    private:
     int score;
     int heart;
     CMap map;
     CDefinition definition;
     CDialog dialog;


};
#endif //SEMESTRALNI_PRACE_CGAME_H
