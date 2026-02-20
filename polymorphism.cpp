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


class Car{
protected:
    int speed;
    string brand;
    string model;
public:
    Car(string brand,string model){
        this->brand=brand;
        this->model=model;
        this->speed=0;
    }

    virtual void accelerate() = 0;
};

class ManualCar : public Car{
public:

    ManualCar(string brand, string model) : Car(brand, model) {}

    void accelerate(){
        this->speed+=20;
    }
};

class SportCar : public Car{
public:
    SportCar(string brand, string model) : Car(brand, model) {}
    void accelerate(){
        this->speed+=50;
    }
};



// ========== Method Overloading =======
class Human{
private:   
    int distanceCovered ;
public:
    Human(){
        this->distanceCovered=0;
    }

    void Walk(){
        this->distanceCovered+=2;
    }

    void Walk(int dist){
        this->distanceCovered+=dist;
    }

    void distance(){
        cout<<"Total Distance Covered : "<<this->distanceCovered<<endl;
    }

};

int main(){
    Car* wagonR = new ManualCar("Tayota","Wagon R");
    Car* tesla = new SportCar("Tesla","model S");

    // method  Overridding : Same method have different implementation in different child class.        [Dynamic Polymorphism]
    wagonR->accelerate();
    tesla->accelerate();

    Human* vivek = new Human();

    // method Overloading : same method behaves different in different context     [Static Polymorphism]
    vivek->distance();
    vivek->Walk();
    vivek->Walk(100);
    vivek->distance();
    return 0;
}