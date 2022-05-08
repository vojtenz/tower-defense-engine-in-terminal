#ifndef SEMESTRALNI_PRACE_CGAME_H
#define SEMESTRALNI_PRACE_CGAME_H
//CGame.h

/**
 * Main class for the whole game system
 *
 */
class CGame{
    public:
     void start();
     void clearScreen();
     void render();
     bool createEnemyLine();
     /**
      * Round initiliazation
      */
     void initRound();

};
#endif //SEMESTRALNI_PRACE_CGAME_H
