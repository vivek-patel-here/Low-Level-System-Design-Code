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
    bool isEngineOn;
    int currentSpeed;
public:
    virtual void startEngine(){
        if(this->isEngineOn) return;
        this->isEngineOn = true;
        cout<<"Engine Started : broommm broommm"<<endl;
    }

    virtual void stopEngine(){
        if(!this->isEngineOn) return;
        this->isEngineOn = false;
        cout<<"Engine turned off"<<endl;
    }

    virtual ~Car(){}
};


class ManualCar : public Car{
private:
    int currentGear;
public:
    void accelerate(){
        if(this->isEngineOn==false) return;
        int inc=0;
        if(this->currentGear==1) inc=10;
        if(this->currentGear==2) inc=20;
        if(this->currentGear==3) inc=30;
        if(this->currentGear==4) inc=40;
        this->currentSpeed+=inc;
        cout<<"Current speed incremented to "<<this->currentSpeed<<" kmp"<<endl;
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
};

class ElectricCar : public Car{
private:
    int battery=100;
public:
    void accelerate(){
        if(this->isEngineOn==false) return;
        int inc=0;
        if(this->battery<=0){
            this->currentSpeed=0;
            return;
        }else if(this->battery<=10) inc=0;
        else if(this->battery<=25) inc=10;
        else if(this->battery<=50) inc=20;
        else if(this->battery<=75) inc=30;
        else if(this->battery>75) inc=40;
        this->currentSpeed+=inc;
        this->battery-=10;
        cout<<"Current speed incremented to "<<this->currentSpeed<<" kmp"<<endl;
    }

    void charge(){
        this->battery = 100;
    }

    void brake(){
        if(this->isEngineOn==false) return;
        this->currentSpeed=0;
        cout<<"car Stopped"<<endl;
    }

    
};

int main(){
    ManualCar* car1 = new ManualCar();
    ElectricCar* car2 = new ElectricCar();
    car1->startEngine();
    car1->accelerate();
    car1->shiftGear(4);
    car1->startEngine();

    car2->startEngine();
    car2->accelerate();
    car2->charge();
    car2->stopEngine();
    return 0;
}