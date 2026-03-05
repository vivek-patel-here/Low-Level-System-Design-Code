#ifndef VEHICLE_H
#define VEHICLE_H

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

class Vehicle{
public:
    string code;
    string type;
};


class Bike : public Vehicle{
public:
    Bike(string code){
        this->code=code;
        this->type="Bike";
    }
};

class Car : public Vehicle{
public:
    Car(string code){
        this->code=code;
        this->type="Car";
    }
};


class HMV:public Vehicle{
public:
    HMV(string code){
        this->code=code;
        this->type="truck";
    }
};



#endif