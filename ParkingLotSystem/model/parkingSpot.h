#ifndef PARKING_SPOT
#define PARKING_SPOT

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
#include "vehicle.h"
using namespace std;


class ParkingSpot{
public:
    int floor ;
    int spot;
    string type;
    bool availabiltity;
    Vehicle *assignedVehicle;

    virtual bool assignSpot(Vehicle *vh) =0 ;
    bool isFree(){
        return !this->assignedVehicle;
    }
};


class BikeSpot : public ParkingSpot{
public:
    BikeSpot(int flr,int spt){
        this->floor=flr;
        this->spot=spt;
        this->availabiltity=true;
        this->type="Bike";
        this->assignedVehicle = nullptr;

    }
    bool assignSpot(Bike* bike){
        this->assignedVehicle = bike;
        this->availabiltity = true;
        return this->assignedVehicle;
    }
};



class CarSpot : public ParkingSpot{
public:
    CarSpot(int flr,int spt){
        this->floor=flr;
        this->spot=spt;
        this->availabiltity=true;
        this->type="Car";
        this->assignedVehicle = nullptr;

    }
    bool assignSpot(Car* car){
        this->assignedVehicle = car;
        this->availabiltity = true;
        return this->assignedVehicle;
    }
};



class HMVSpot : public ParkingSpot{
public:
    HMVSpot(int flr,int spt){
        this->floor=flr;
        this->spot=spt;
        this->availabiltity=true;
        this->type="HMV";
        this->assignedVehicle = nullptr;

    }
    bool assignSpot(HMV* hmv){
        this->assignedVehicle = hmv;
        this->availabiltity = true;
        return this->assignedVehicle;
    }
};


#endif