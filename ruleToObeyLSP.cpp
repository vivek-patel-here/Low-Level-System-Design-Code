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

/*
===================== Signature Rule =================
This rule say the subclass must follow the signature of parent class
Types of signature : 
    - Method Argument Rule : The no. of argument and teh dType of argument must be same for the method overridding in child class.
    - Return Type Rule : The return type of a method in parent class must be either [same or subclass of the return type] for the method overridding in child class.
    - Exception Rule : The execption class of a method in parent class must be either [same or subclass of the exception class] for the method overridding in child class. 
*/


/*
// =============== Property rule =================


# Class Invariant : 
Invariant is the custom rule imposed on a class by the developer.
It must followed by all the subclasses .

# History Constraint :
It is the constraint imposed on some property , which restricts its state change. 
 */

class BankAccount{
// Invariant : Account Balance must be non - negative
public:
    int accountBalance ;
    virtual void withdraw () = 0;
};

class SavingAccount : public BankAccount{
    void withdraw(int amt){
        if(this->accountBalance < amt) return;
        this->accountBalance -=amt;
    }
};

// This following metro class is voilating the class Invariance rule.
class MetroCard : public BankAccount{
     void withdraw(int metroFair){
        this->accountBalance -=metroFair;
    }
};


/*
======================= Method Rule =========================
# pre-Condition Rule
These are the rule declared by the the developer that must be fulfilled before execution of any specific method.

# post-condition Rule

*/

class Precondition_rule{
public:
    string password;

    // Password len  > 0 and Password len <=10
    virtual void setPassword(string password) = 0;
};

class Precondition_rule_Child : public Precondition_rule{
public:
    // Password len  > 0 and Password len <=10
    void setPassword(string password){
        this->password = password;
    }
};

class PostCondition_rule{
public:
    int x ;

    virtual void setX(int x) = 0;

    // decrease method must decrese the x;
    virtual void decrease(){
        this->x -=10;
    }
};


// As we can see that the decrease method is decreasing the value of X more than parent class;
class PostCondition_rule_Child : public PostCondition_rule{
public:
    void setX(int x){
        this->x = x;
    }

    // decrease method must decrese the x;
    void decrease(){
        this->x -=20;
    }

};

int main(){
    return 0;
}