#include <iostream>
#include <vector>
#include <memory>
#include "CActiveTile.h"
#include "CTowerGreen.h"
#include "CDefinition.h"
#include "CEnemyImmune.h"
#include "CDialog.h"
#include <unistd.h>
#include "CGame.h"
using namespace std;

int main() {
    CGame h(11000,300);
    if(!h.init()) {
        std::cout << "Neco je spatne vojtechu\n";
        return EXIT_FAILURE;
    }
    h.start();

    /*
    h.render();
    CMap map;
    map.initMap("examples/map/map.txt");
    vector<unique_ptr<CTower>> nvm;
    CDefinition def;
    //nvm
    bool x = def.loadTowerDef("examples/definition/tower_def.csv");
    cout << "Loading tower definition: " << boolalpha << x << "\n";
    CDialog dialog(map,std::cout);
    //dialog.openingText();
    bool running = true;
    bool save = false;
    while(running){
        //clearing screen;
        std::cout << "\033[2J\033[1;1H";
        map.renderMap(std::cout);
        //render(); with score etc
        int option = dialog.getOption();
        if(option<=0){
            if(option == 0)save = true;
            running = false;
            break;
        }
        if(option == 2){

            usleep(1000000);
            //buyTower();
        }
        //CRound??
        //initRound();
        //startRound();
        cout << "Init round..\n";
        usleep(1000000);
        cout << "Starting round..\n";
        usleep(1000000);
    }
     */
    /*
    for(const auto& y : nvm ){
        //cout << x->printAttribute() << "\n";
        y->printAttribute(std::cout);
        cout << "\n";
    }
    cout << "\n";
    vector<unique_ptr<CEnemy>> nvm_en;
    bool x_en = CDefinition::loadEnemyDef(nvm_en,"../examples/definition/enemy_def.csv");
    cout << "Loading enemy definition: " << boolalpha << x_en << "\n";
    for(const auto& y : nvm_en ){
        //cout << x->printAttribute() << "\n";
        cout << y->getType()<< "\n";
    }
     */
     /*
    CMap map;
    assert(map.initMap("../examples/map/map.txt"));
    cout << "Height: " << map.getHeight() << endl;
    cout << "Width: " << map.getWidth() << endl;
    cout << "\n";
    map.renderMap(cout);
    cout << "\n";
    cout << "\n";
    cout << "\n";
    CTowerRed nvm('P',15000,4);
    nvm.pos_x = 4;
    nvm.pos_y = 8;
    map.renderMap(cout, true, &nvm);
    cout << "\n";
    cout << "\n";
    cout << "\n";
    map.renderMap(cout, true);
     */
/*
    vector<shared_ptr<CTile>> barvy;
    barvy.push_back(make_shared<CTower>('F',15000,3,"blue"));
    barvy.push_back(make_shared<CTower>('F',15000,3,"ynvnvlow"));
    barvy.push_back(make_shared<CTower>('F',15000,3,"red"));
    barvy.push_back(make_shared<CTower>('F',15000,3,"purple"));
    barvy.push_back(make_shared<CTower>('F',15000,3,"green"));
    for(const auto& x : barvy){
        cout << *x << "\n";
    }
*/
    /*

    cout << "UDAJE O VEZICH" << endl;
    CTower h('n',0,0,15000,9,"rude");
    barvy.push_back(shared_ptr<CTile>(new CTower(h)));

    for(auto& x : barvy){
        std::shared_ptr<CTower>tmp = static_pointer_cast<CTower>(x);
        cout << "Coordinates: " << tmp->getX() << " " << tmp->getY() << "\n";
        cout << "Range: " << tmp->getRange() << "\n";
        cout << "Price: " << tmp->getPrice() << "\n";
        cout << "--------------------------------------------\n";
    }

    vector<shared_ptr<CTile>> nvm;
    nvm.push_back(make_shared<CEmpty>());
    nvm.push_back(make_shared<CWall>());
    nvm.push_back(make_shared<CPath>());
    for(const auto& x : nvm){
        cout << x->getType() << "\n";
    }

    nvm[0] = make_shared<CWall>();

    for(const auto& x : nvm){
        cout << *x << "\n";
    }

    cout << "WALL" << endl;
    CWall wall;
    cout << wall << endl;
*/
    return 0;
}
