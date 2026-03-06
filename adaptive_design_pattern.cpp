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


// Adapter design pattern is used to provide adapter that facilitates the communication between two incompatible classes.
// Allowing them to decouple and intgrate seemlessly.

//Third Party Service
class Adaptee{
public:
    virtual string getData() = 0;
};

class XMLDataProvider : public Adaptee{
public:
    string data;
    XMLDataProvider(){
        this->data="This is XML Data.\nHello world.\nData from XML provider.";
    }
    string getData() override{
        return this->data;
    }
};


// Adapter
class IReport{
public:
    virtual string GetData() = 0;
};

class Adapter : public IReport{
private:
    Adaptee* adpt;
public:
    Adapter(Adaptee* adpt){
        this->adpt=adpt;
    }

    string convertToJSON(string xmlData){
        return "JSON : "+xmlData;
    }

    string GetData(){
        string xmldata =  adpt->getData();
        string jsonData = convertToJSON(xmldata);
        return jsonData;
    }
};


//client 
class Client{
public:
    IReport* report;
    Client(IReport* r){
        this->report=r;
    }

    void printInfo(){
        cout<<report->GetData()<<endl;
    }
};

int main(){

    Adaptee* xmlprovider = new XMLDataProvider();
    IReport* adptr = new Adapter(xmlprovider);
    Client* app = new Client(adptr);

    app->printInfo();


    return 0;
}