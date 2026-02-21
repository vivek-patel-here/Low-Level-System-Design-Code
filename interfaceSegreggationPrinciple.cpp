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

// Interface Segregattion principle says that :
// - Instead making single general purpose class , make multiple specific classes.
// - Child class must not forced to implement the method they donot need.

// =================== ISP Voilated ======================


class Shape_Voilated_ISP{
public:
    virtual int area() = 0;
    virtual int volume() = 0;
};

class Square_Voilated_ISP : public Shape_Voilated_ISP{
public:
    int side;
    Square_Voilated_ISP(int side){
        this->side = side;
    }

    int area(){
        return this->side * this->side;
    }
    // This square class is forced to implement the following volume method , hence voilating the ISP principle .
    int volume(){
        cout<<"It is a 2D shape , so volume is not possible ";
        return -1;
    }
};

class Cube_Voilated_ISP : public Shape_Voilated_ISP{
public:
    int side;

    Cube_Voilated_ISP(int side){
        this->side = side;
    }

    int area(){
        return 6*this->side * this->side;
    }

    int volume(){
        return this->side * this->side * this->side;
    }
};



// =================== ISP Respected ======================

class Shape_2D_Following_ISP{
public:
    virtual int area() = 0;
};

class Shape_3D_Following_ISP{
public:
    virtual int area() = 0;
    virtual int volume() = 0;
};

class Square_Following_ISP : public Shape_2D_Following_ISP{
public:
    int side;

    Square_Following_ISP(int side){
        this->side = side;
    }

    int area(){
        return this->side * this->side;
    }
};

class Cube_Following_ISP : public Shape_3D_Following_ISP{
public:
    int side;

    Cube_Following_ISP(int side){
        this->side = side;
    }

    int area(){
        return 6*this->side * this->side;
    }

    int volume(){
        return this->side * this->side * this->side;
    }
};


int main(){
    return 0;
}