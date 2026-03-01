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
#include <mutex>
using namespace std;


// Singleton Design Pattern introduces a special class that only return a single object instance everytime .
class Singleton{
private:

    static Singleton* instance;
    static mutex mtx;
    Singleton(){
        cout<<"A singleton Object is instantiated"<<endl;
    }
public:
    static Singleton* getInstance(){
        if(instance==nullptr){
            lock_guard<mutex>  lock(mtx);           // Multithreading Safety using mutex to avoid CSP.
            if(instance==nullptr) instance = new Singleton();
        }
        return instance;
    }

    //Eager getInstance method.
    static Singleton* getEagerInstance(){
        return instance;
    }

};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;


// Eager Initialisation
Singleton* Singleton::instance = new Singleton();

int main(){

    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();
    Singleton* obj3 = Singleton::getInstance();
    // Even after calling so many object but all of them holds reference of the same object .
    // So constrcutor will be called only once.

    return 0;
}