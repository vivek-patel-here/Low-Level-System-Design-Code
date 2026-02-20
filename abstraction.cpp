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
public:
    virtual void startEngine() = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void stopEngine() = 0;
    virtual ~Car(){}
};

class SportsCar : public Car {
public:
    string brand;
    string model;
    bool isEngineOn ;
    int currentSpeed;
    int currentGear ;

    SportsCar(string brand,string model){
        this->brand=brand;
        this->model=model;
        this->isEngineOn = false;
        this->currentGear=1;
        this->currentSpeed=0; //(kmp)
        cout<<this->brand<<" "<<this->model<<endl;
    }

    void startEngine(){
        if(this->isEngineOn==true) return;
        this->isEngineOn = true;
        cout<<"broooooomrrRR broooooomrrrRRRR Ratatatatatatata tatata"<<endl;
    }

    void accelerate(){
        if(this->isEngineOn==false) return;
        int inc=0;
        if(this->currentGear==1) inc=10;
        if(this->currentGear==2) inc=20;
        if(this->currentGear==3) inc=30;
        if(this->currentGear==4) inc=40;
        this->currentSpeed+=inc;
        cout<<"Ratatatatatatata tatata"<<endl;
        cout<<"CurrentSpeed incremented to "<<this->currentSpeed<<endl;
    }

    void brake(){
        if(this->isEngineOn==false) return;
        this->currentSpeed=0;
        cout<<"car Stopped"<<endl;
    }

    void shiftGear(int gear){
        if(this->isEngineOn==false) return;
        if(gear<1 || gear>4) return;
        this->currentGear= gear;
        cout<<"Gear shifted to "<<gear<<endl;
    }

    void stopEngine(){
        if(this->isEngineOn==false) return;
        this->isEngineOn =false;
        cout<<"Engine turned Off"<<endl;
    }

};



int main(){

    Car* myCar = new SportsCar("Tayota","Supra");
    // Complex Implementaion is hidden and simple methods are provided.
    myCar->startEngine();
    myCar->accelerate();
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    myCar->accelerate();
    return 0;
}