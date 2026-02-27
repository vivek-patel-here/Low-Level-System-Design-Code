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


// factory Design Pattern is used to seperate the object creation part of the code base from the core bussiness logic part .
/*
    It has three thing. : 
        - Simple Factory
        - Factory Method
        - Abstarct Factory Method 
*/

// Simple factory is uses a factory class to create a specific type of product on runtime.
// A factory class that decides which concrete class to instantiate . 

class Burger{
public:
    virtual void prepareBurger() = 0;
};

class BasicBurger : public Burger{
public:
    void prepareBurger() override{
        cout<<"Prepared a basic buger with bun , patty and sauce "<<endl;
    }
};

class StandardBurger : public Burger{
public:
    void prepareBurger() override{
        cout<<"Prepared a standard buger with bun , patty , sauce  and lettuce"<<endl;
    }
};

class PremiumBurger : public Burger{
public:
    void prepareBurger() override{
        cout<<"Prepared a premium buger with premium bun , extra large patty ,multiple sauces , cheeseSlice , veg-es and lettuce"<<endl;
    }
};


class BurgerFactory{
public:
    // type 0 : basic Burger , type 1: satndard burger , type 2 : premium Burger
    Burger* createBurger(int type){
        if(type==0) return new BasicBurger();
        else if(type == 1) return new StandardBurger();
        else return new PremiumBurger();
    }
};



int main(){
    BurgerFactory* burgerKing = new BurgerFactory();
    Burger* burger1 = burgerKing->createBurger(0);  // Basic Burger
    Burger* burger2 = burgerKing->createBurger(1);  // Standard Burger
    Burger* burger3 = burgerKing->createBurger(2);  // Premimum Burger
    
    burger1->prepareBurger();
    burger2->prepareBurger();
    burger3->prepareBurger();

    return 0;
}