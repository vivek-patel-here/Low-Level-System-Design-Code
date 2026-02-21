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



// The following implementation show the voilation of LSP.
class Account_voilating_LSP{
public:
    string type;
    virtual void deposite() = 0;
    virtual void withdraw() = 0;
};

class Saving_voilating_LSP : public Account_voilating_LSP{
public:
    Saving_voilating_LSP(){
        this->type="Saving account";
    }

    void deposite(){
        cout<<"money deposited to saving account"<<endl;
    }

    void withdraw(){
        cout<<"money withdrawn from saving account"<<endl;
    }
};

class Current_voilating_LSP : public Account_voilating_LSP{
public:
    Current_voilating_LSP(){
        this->type="Current account";
    }

    void deposite(){
        cout<<"money deposited to current account"<<endl;
    }

    void withdraw(){
        cout<<"money withdrawn from current account"<<endl;
    }
};

class fixed_voilating_LSP : public Account_voilating_LSP{
public:
    fixed_voilating_LSP(){
        this->type="fixed account";
    }

    void deposite(){
        cout<<"money deposited to fixed account"<<endl;
    }
};

// The following client is tightly coupled with the the implementation of the account 
// This voilates LSP , SRP and making is less tightly coupled.
class Client_voilating_LPS{
public:
    vector<Account_voilating_LSP*> accList;

    void withdrawMoney(){
        for(auto &elem : accList){
            if(elem->type=="fixed account") continue;
            else cout<<"Money withdrawn"<<endl;
        }
    }
};


// This following implementation shows the best practice to handle such scenarios with voilating any SOLID principle .

class Non_withdrawable_account{
public:
    virtual void deposite() = 0;
};

class Withdrawable_account : public Non_withdrawable_account{
public:
    virtual void withdraw() = 0;
};

class Saving_Account_Following_LSP : public Withdrawable_account{
public:
    void deposite(){
        cout<<"money deposited to saving account"<<endl;
    }

    void withdraw(){
        cout<<"money withdrawn from saving account"<<endl;
    } 
};

class Current_Account_Following_LSP : public Withdrawable_account{
public:
    void deposite(){
        cout<<"money deposited to current account"<<endl;
    }

    void withdraw(){
        cout<<"money withdrawn from current account"<<endl;
    } 
};

class Fixed_Account_Following_LSP : public Non_withdrawable_account{
public:
    void deposite(){
        cout<<"money deposited to saving account"<<endl;
    }
};

class client_Followign_LSP{
public:
    vector<Withdrawable_account*> acc1;
    vector<Non_withdrawable_account*> acc2;

    void withdrawMoney(){
        for(auto &elem : acc1){
            cout<<"Money withdrawn"<<endl;
        }
    }

    void deposite(){
        for(auto &elem : acc1){
            cout<<"Money deposited"<<endl;
        }
        for(auto &elem : acc2){
            cout<<"Money depoisted"<<endl;
        }
    }

};

int main(){
    return 0;
}