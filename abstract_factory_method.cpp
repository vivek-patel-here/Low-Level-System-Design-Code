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


//product 1
class garlicBread{
public:
    virtual void prepare() = 0;
};

// product 1 category 1
class BasicgarlicBread : public garlicBread{
public:
    void prepare() override{
        cout<<"Prepared a basic garlicBread with bread and garlic sauce."<<endl;
    }
};
class StandardgarlicBread : public garlicBread{
public:
    void prepare() override{
        cout<<"Prepared a standard garlicBread "<<endl;
    }
};
class PremiumgarlicBread : public garlicBread{
public:
    void prepare() override{
        cout<<"Prepared a premium garlicBread "<<endl;
    }
};

//product 1 category 2
class HealthyBasicgarlicBread : public garlicBread{
public:
    void prepare() override{
        cout<<"Prepared a healthy basic garlicBread "<<endl;
    }
};
class HealthyStandardgarlicBread : public garlicBread{
public:
    void prepare() override{
        cout<<"Prepared a healthy standard garlicBread "<<endl;
    }
};
class HealthyPremiumgarlicBread : public garlicBread{
public:
    void prepare() override{
        cout<<"Prepared a healthy premium garlicBread ."<<endl;
    }
};



//product 2
class Burger{
public:
    virtual void prepare() = 0;
};

// product 2 category 1
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

//product 2 category 2
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
class FoodFactory{
public:
    virtual Burger* createBurger(int type) = 0;
    virtual garlicBread* createGarlicBread(int type) = 0;
};

class FastFoodFactory : public FoodFactory{
public:
    Burger* createBurger(int type)override{
        if(type==0) return new BasicBurger();
        else if(type == 1) return new StandardBurger();
        else return new PremiumBurger();
    }

    garlicBread* createGarlicBread(int type)override{
        if(type==0) return new BasicgarlicBread();
        else if(type == 1) return new StandardgarlicBread();
        else return new PremiumgarlicBread();
    }


};

class HealthyTastyFoodFactory : public FoodFactory{
public:
    Burger* createBurger(int type)override{
        if(type==0) return new HealthyBasicBurger();
        else if(type == 1) return new HealthyStandardBurger();
        else return new HealthyPremiumBurger();
    }

    garlicBread* createGarlicBread(int type)override{
        if(type==0) return new HealthyBasicgarlicBread();
        else if(type == 1) return new HealthyStandardgarlicBread();
        else return new HealthyPremiumgarlicBread();
    }
};




int main(){
    FoodFactory* factory = new FastFoodFactory();
    // FoodFactory* factory = new HealthyTastyFoodFactory();

    Burger* burger = factory->createBurger(2);
    garlicBread* gBread = factory->createGarlicBread(0);
    burger->prepare();
    gBread->prepare();
    return 0;
}