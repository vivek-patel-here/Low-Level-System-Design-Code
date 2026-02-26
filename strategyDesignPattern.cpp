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


// Strategy Design pattern defines a set of Algorithm , put them into seperate classes so that they can be changed at run time.


//Strategy classes
class walkingAbility{
public:
    virtual void walk() = 0;
};
class walkableRobot : public walkingAbility{
public:
    void walk(){
        cout<<"can walk"<<endl;
    }
};
class NotWalkableRobot : public walkingAbility{
public:
    void walk(){
        cout<<"cannot walk"<<endl;
    }
};

class flyingAbility{
public:
    virtual void fly() = 0;
};
class flyableRobot : public flyingAbility{
public:
    void fly(){
        cout<<"can fly"<<endl;
    }
};
class NotFlyableRobot : public flyingAbility{
public:
    void fly(){
        cout<<"Cannot fly"<<endl;
    }
};

class swimmingAbility{
public:
    virtual void swim() = 0;
};
class swimmableRobot : public swimmingAbility{
public:
    void swim(){
        cout<<"can Swim"<<endl;
    }
};
class NotswimmableRobot : public swimmingAbility{
public:
    void swim(){
        cout<<"cannot Swim"<<endl;
    }
};

// Client Class


class Robot{
private:
    string id;
    walkingAbility* w;
    flyingAbility* f;
    swimmingAbility* s;
    
public:
    Robot(string id, walkingAbility* w,flyingAbility* f,swimmingAbility* s){
        this->id=id;
        this->w=w;
        this->f=f;
        this->s=s;
    }

    void walk(){
        w->walk();
    }

    void fly(){
        f->fly();
    }

    void swim(){
        s->swim();
    }
};


int main(){
    // BirdRobot
    Robot* eagleRob = new Robot("Eagle007",new NotWalkableRobot(),new flyableRobot(),new NotswimmableRobot());
    Robot* penguinRob = new Robot("Penguin007",new walkableRobot(),new NotFlyableRobot(),new NotswimmableRobot());

    // and we can try varioud other permutations ...

    return 0;
}