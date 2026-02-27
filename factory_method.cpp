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

class Burger{
public:
    virtual void prepare() = 0;
};

// product category 1
class BasicBurger : public Burger{
public:
    void prepare() override{
        cout<<"Prepared a basic burger with bun , patty and sauce"<<endl;
    }
};
class StandardBurger : public Burger{
public:
    void prepare() override{
        cout<<"Prepared a standard burger with bun , patty , sauce and lettuce"<<endl;
    }
};
class PremiumBurger : public Burger{
public:
    void prepare() override{
        cout<<"Prepared a premium burger with premium bun , extralarge patty , sauce , cheese slice and vegetables with lattuce"<<endl;
    }
};

//product category 2
class HealthyBasicBurger : public Burger{
public:
    void prepare() override{
        cout<<"Prepared a healthy basic burger with whole wheat bun , patty and sauce"<<endl;
    }
};
class HealthyStandardBurger : public Burger{
public:
    void prepare() override{
        cout<<"Prepared a healthy standard burger with whole wheat bun , patty , sauce and lettuce"<<endl;
    }
};
class HealthyPremiumBurger : public Burger{
public:
    void prepare() override{
        cout<<"Prepared a healthy premium burger with whole wheat premium bun , extralarge patty , sauce , cheese slice and vegetables with lattuce and olives"<<endl;
    }
};


// Factory and its sub - classes
class BurgerFactory{
public:
    virtual Burger* createBurger(int type) = 0;
};

class FastFoodFactory : public BurgerFactory{
public:
    Burger* createBurger(int type)override{
        if(type==0) return new BasicBurger();
        else if(type == 1) return new StandardBurger();
        else return new PremiumBurger();
    }
};

class HealthyTastyFoodFactory : public BurgerFactory{
public:
    Burger* createBurger(int type)override{
        if(type==0) return new HealthyBasicBurger();
        else if(type == 1) return new HealthyStandardBurger();
        else return new HealthyPremiumBurger();
    }
};

int main(){
    // BurgerFactory* mac2l = new FastFoodFactory();
    BurgerFactory* mac2l = new HealthyTastyFoodFactory();
    Burger* burger1 = mac2l->createBurger(0);
    Burger* burger2 = mac2l->createBurger(1);
    Burger* burger3 = mac2l->createBurger(2);

    burger1->prepare();
    burger2->prepare();
    burger3->prepare();

    return 0;
}