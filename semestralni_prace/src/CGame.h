#ifndef SEMESTRALNI_PRACE_CGAME_H
#define SEMESTRALNI_PRACE_CGAME_H
//CGame.h
#include "CMap.h"
#include "CDefinition.h"
#include "CDialog.h"
#include "CRound.h"
/**
 * Main class for the whole game
 */
class CGame{
    public:
     CGame(int starting_score = 250, int number_of_life = 150);
     /**
      * Starts the game
      */
     void start();
     /**
      * Initialize all needed parameters (map,definitions,..)
      * @return true if initialization was successful
      */
     bool init();
     void clearScreen();
     /**
      * Renders map, score(money), health, round,..
      */
     void render();
    private:
     int score;
     int heart;
     CMap map;
     CDefinition definition;
     CDialog dialog;
     CRound round_manager;


};
#endif //SEMESTRALNI_PRACE_CGAME_H
