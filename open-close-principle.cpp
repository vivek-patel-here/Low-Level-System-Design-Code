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




// This class is voilating Open-Close Principle.
class Car_Voilating_OCP{
public:
    int speed ;
    string vehicle;

    Car_Voilating_OCP(string vehicle){
        this->vehicle=vehicle;
        this->speed=0;
    }

    int getSpeed(){
        return this->speed;
    }

    // Tommorrow If we will have to add a new feature for sport car then we have to modify the old working code. 
    void accelerate(){
        if(vehicle=="bike") this->speed+=20;
        else if(vehicle=="car") this->speed+=25;
        else if(vehicle=="plane") this->speed+=50;
        else if(vehicle=="truck") this->speed+=10;
        else if(vehicle=="bus") this->speed+=15;
        // else if(vehicle=="Sport-car") this->speed+=40;    [tommorrows if Need to add this we have to modify old implementation]
    }

};

// Class following Open-Close Principle
class Car_Following_OCP{
public:
    int speed;
    string vehicle;

    Car_Following_OCP(string vehicle){
        this->vehicle=vehicle;
        this->speed=0;
    }

    virtual void accelerate() =0;
    virtual ~Car_Following_OCP(){}
};


class Bike: public Car_Following_OCP{
    void accelerate(){
        this->speed+=20;
    }
};

class Car: public Car_Following_OCP{
    void accelerate(){
        this->speed+=25;
    }
};

class Plane: public Car_Following_OCP{
    void accelerate(){
        this->speed+=50;
    }
};

class Truck: public Car_Following_OCP{
    void accelerate(){
        this->speed+=10;
    }
};

class Bus: public Car_Following_OCP{
    void accelerate(){
        this->speed+=15;
    }
};

// [Tommorrow If need we can easily extend without modifying the already existing code]

// class SportCar: public Car_Following_OCP{
//     void accelerate(){
//         this->speed+=50;
//     }
// };



int main(){
    return 0;
}