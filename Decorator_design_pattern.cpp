#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <numeric>
#include <stack>
#include <queue>
#include <unordered_set>
#include <tuple>
#include <cmath>
using namespace std;



// base class
class Character{
public:
    virtual string getAbility() = 0;
};

// Character 1
class Mario : public Character{
public:
    string getAbility()override{
        return "Mario";
    }
};

//Character 2
class Toad : public Character{
public:
    string getAbility()override{
        return "Toad";
    }
};




// base decorator class
class Decorator : public Character{
public:
    Character* ch;
};

// decorator 1
class Healthup : public Decorator{
public:
    Healthup(Character* ch){
        this->ch=ch;
    }

    string getAbility(){
        return this->ch->getAbility() + " with healthup";
    }
};

// decorator 2
class GunAbility : public Decorator{
public:
    GunAbility(Character* ch){
        this->ch=ch;
    }

    string getAbility(){
        return this->ch->getAbility() + " with gun up ability";
    }
};

// decorator 3
class StarAbility : public Decorator{
public:
    StarAbility(Character* ch){
        this->ch=ch;
    }

    string getAbility(){
        return this->ch->getAbility() + " with star ability";
    }
};



int main(){
    Character* mario = new Mario();
    cout<<mario->getAbility()<<endl;
    mario = new Healthup(mario);
    cout<<mario->getAbility()<<endl;
    mario = new GunAbility(mario);
    cout<<mario->getAbility()<<endl;
    mario = new StarAbility(mario);
    cout<<mario->getAbility()<<endl;

    return 0;
}