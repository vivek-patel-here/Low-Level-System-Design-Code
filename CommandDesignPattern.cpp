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

// Command Design pattern helps in decoupling the sender from the receiver by encapsulatiing the request as an object.
class Appliance{
private:
    string name;
    bool state;
public:
    Appliance(string nm){
        this->name = nm;
        this->state = false;
    }

    void On(){
        this->state = true;
        cout<<this->name<<" is turn On"<<endl;
    }

    void Off(){
        this->state = false;
        cout<<this->name<<" is turn Off"<<endl;
    }
};

class ICommand{
private:
    Appliance* device;
public:
    ICommand(Appliance* appliance){
        this->device=appliance;
    }
    void execute(){
        this->device->On();
    }
    void undo(){
        this->device->Off();
    }
    ~ICommand(){
        delete device;
    }
};

class Remote{
private:
    vector<ICommand*> commands;
    vector<bool> state; 
public:
    Remote(){
        this->commands.resize(0);
        this->state.resize(0);
    }

    void addCommand(ICommand* cmd){
        this->commands.push_back(cmd);
        state.push_back(false);
    }

    void pressBtn(int idx){
        if(idx>=commands.size()) return;
        if(this->state[idx]==false){
             this->commands[idx]->execute();
             this->state[idx]=true;
        }else{
             this->commands[idx]->undo();
             this->state[idx]=false;
        }
    }
};


int main(){
    Remote* remote = new Remote();

    Appliance* light = new Appliance("Light");
    Appliance* fan = new Appliance("Fan");
    Appliance* musicSystem = new Appliance("Music System");

    ICommand* lightBtn = new ICommand(light);
    ICommand* fanBtn = new ICommand(fan);
    ICommand* musicSysBtn = new ICommand(musicSystem);

    remote->addCommand(lightBtn);
    remote->addCommand(fanBtn);
    remote->addCommand(musicSysBtn);

    remote->pressBtn(0);
    remote->pressBtn(0);
    remote->pressBtn(1);
    remote->pressBtn(1);
    remote->pressBtn(2);
    remote->pressBtn(2);
    remote->pressBtn(2);



    return 0;
}