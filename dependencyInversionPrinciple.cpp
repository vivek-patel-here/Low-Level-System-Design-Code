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

// Dependency Inversion Principle : Any high level module should not talk to any low level module directly .
// There must be a interface layer in between . 
class Application_DIP_Voilation{
// High level module
public:
    SQL_DIP_Voilation* sqlInstance;
    Mongo_DIP_Voilation* mongoInstance;

    void saveToSQL(){
        sqlInstance->saveToDB();
    }

    void saveToMongo(){
        mongoInstance->saveToDB();
    }

};

class SQL_DIP_Voilation{
// Low level module
public:
    void saveToDB(){
        cout<<"Saved to SQL DB"<<endl;
    }
};

class Mongo_DIP_Voilation{
// low level module
public:
    void saveToDB(){
        cout<<"Saved to MONGO DB"<<endl;
    }
};



// following implementation introduces a DB-Persistance Layer between application and Database-Instance.
class Application_DIP_Followed{
public:
    Persistance* DBInstance;

    Application_DIP_Followed(Persistance* db){
        this->DBInstance = db;
    }

    void saveToDB(){
        DBInstance->save();
    }
};

class Persistance{
public:
    virtual void save() = 0;
};

class SQLInstance : public Persistance{
public:
    void save(){
        cout<<"Saved to SQL DB"<<endl;
    }
};

class MongoInstance : public Persistance{
public:
    void save(){
        cout<<"Saved to Mongo DB"<<endl;
    }
};

class CassandraInstance : public Persistance{
public:
    void save(){
        cout<<"Saved to Cassandra DB"<<endl;
    }
};

int main(){
    Application_DIP_Followed app1(new SQLInstance());
    Application_DIP_Followed app1(new MongoInstance());
    Application_DIP_Followed app1(new CassandraInstance());
    return 0;
}