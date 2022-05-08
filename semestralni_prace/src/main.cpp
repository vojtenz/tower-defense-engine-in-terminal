#include <iostream>
#include "CEmpty.h"
#include "CWall.h"
#include "CPath.h"
#include <vector>
#include <memory>
#include "CActiveTile.h"
#include "CTowerRed.h"
#include "CTowerGreen.h"
using namespace std;

int main() {
    vector<shared_ptr<CTile>> barvy;
    barvy.push_back(make_shared<CTowerRed>('F',0,0,15000,3));
    barvy.push_back(make_shared<CTowerGreen>('O',15,15,690,1));

    for(const auto& x : barvy){
        cout << *x << "\n";
    }

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
    /*
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
