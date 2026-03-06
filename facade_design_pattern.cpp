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


// Complex SubSytem of Multiple modules
class MotherBoard{
private:
    bool state;
public:
    void startMotherBoard(){
        this->state=true;
        cout<<"Motherboard has powered Up"<<endl;
        cout<<"Executing Power-On Self Test"<<endl;
    }

    void StopMotherBoard(){
        this->state=false;
        cout<<"MotherBoard is shutting down"<<endl;
        cout<<"power Off"<<endl;
    }
};

class BIOS{
private:
    bool state;
public:
    BIOS(){
        this->state=false;
    }

    void startBIOS(){
        this->state=true;
        cout<<"BIOS Chip has powered up."<<endl;
        cout<<"Basic Input Output programming is executing";
    }

    void stopBIOS(){
        this->state=false;
        cout<<"BIOS chip has shutdown."<<endl;
    }
};

class Processor{
private:
    bool state;
public:
    void startProcessor(){
        this->state=true;
        cout<<"Processor has Initialised."<<endl;
    }

    void StopProcessor(){
        this->state=false;
        cout<<"Processor has stopped."<<endl;
    }
};

class Harddisk{
private:
    bool state;
public:
    void startHarddisk(){
        this->state=true;
        cout<<"Harddisk has Initialised"<<endl;
    }

    void StopHarddisk(){
        this->state=false;
        cout<<"Harddisk has stopped."<<endl;
    }
};

class RAM{
private:
    bool State;
public:
    void startRAM(){
        this->State=true;
        cout<<"RAM has Initialised"<<endl;
        cout<<"Looking for Master Boot record ."<<endl;
        cout<<"Scanning Hard disk...."<<endl;
        cout<<"MBR found."<<endl;
        cout<<"Running MBR"<<endl;
        cout<<"OS has successfully Loaded."<<endl;
    }

    void StopRAM(){
        this->State=false;
        cout<<"Memory has flushed"<<endl;
        cout<<"RAM is shutting down"<<endl;
    }
};

class OS{
private:    
    bool state;
public:
    void startOS(){
        this->state=true;
        cout<<"OS has initialied"<<endl;
        cout<<"Computer has Started successfully!";
        cout<<"Welcome Client!"<<endl;
    }

    void StopOS(){
        this->state = false;
        cout<<"OS has Stopped."<<endl;
    }
};


// Intermediate Facade Module
class ComputerFacadeModule{
private:
    MotherBoard* mb;
    BIOS* bios;
    Processor* processor;
    Harddisk* sanddisK_1TB;
    RAM* Ram16GB;
    OS* Window10;
public:
    ComputerFacadeModule(MotherBoard* mb,BIOS* bios,Processor* cpu,Harddisk* disk,RAM* ram,OS* os){
        this->mb=mb;
        this->bios=bios;
        this->processor=cpu;
        this->sanddisK_1TB=disk;
        this->Ram16GB=ram,
        this->Window10=os;
    }


    void StartComputer(){
        this->mb->startMotherBoard();
        this->bios->startBIOS();
        this->processor->startProcessor();
        this->sanddisK_1TB->startHarddisk();
        this->Ram16GB->startRAM();
        this->Window10->startOS();
    }

    void StopComputer(){
        this->Window10->StopOS();
        this->Ram16GB->StopRAM();
        this->sanddisK_1TB->StopHarddisk();
        this->processor->StopProcessor();
        this->bios->stopBIOS();
        this->mb->StopMotherBoard();
    }
};


// High Level Client Module
class Client{
private:
    ComputerFacadeModule* facade;
public:
    Client(ComputerFacadeModule* facade){
        this->facade=facade;
    }

    void StartComputer(){
        this->facade->StartComputer();
    }

    void StopComputer(){
        this->facade->StopComputer();
    }
};

int main(){
    MotherBoard* zebronicMB = new MotherBoard();
    BIOS* bios = new BIOS();
    Processor* i7 = new Processor();
    Harddisk* sanddisk1TB = new Harddisk();
    RAM* ram16gb = new RAM();
    OS* window10 = new OS();

    ComputerFacadeModule* facade = new ComputerFacadeModule(zebronicMB,bios,i7,sanddisk1TB,ram16gb,window10);

    Client* myapp = new Client(facade);

    myapp->StartComputer();
    cout<<endl;
    myapp->StopComputer();

    return 0;
}