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


// Abstract Notification Class
class INotification{
public:
    virtual string getContent() = 0;
    virtual ~INotification() {};
};

// Simple Concrete Notification
class SimpleNotification :public INotification{
public:
    string text;

    SimpleNotification(string content){
        this->text = content;
    }

    string getContent() override{
        return this->text;
    }
};


/// Decorator 
class INotificationDecorator : public INotification{
protected:
    INotification* Inote;
public:
    INotificationDecorator(INotification* note){
        this->Inote=note;
    }

    virtual ~INotificationDecorator(){
        delete this->Inote;
    }
};


class TimeStampDecorator : public INotificationDecorator{
public:
    TimeStampDecorator(INotification* note):INotificationDecorator(note){};

    string getContent() override{
        return this->Inote->getContent() + " \nTime Stamp : [2026-01-01]";
    }
};


class WaterMark : public INotificationDecorator{
public: 
    WaterMark(INotification* note) : INotificationDecorator(note){};

    string getContent() override{
        return this->Inote->getContent() + "[Brand Logo , Brand Name , Watermark]";
    }
};

// Observer Design component


// abstract observer class
class IObserver{
public:
    virtual void update() = 0;
};


//abstract observable class
class IObservable {
public:
    virtual void addObserver(IObserver* observer) = 0;
    virtual void removeObserver(IObserver* observer) = 0;
    virtual void notify() = 0;
};


// concrete observable
class INotificationObservable: IObservable{
protected:
    vector<IObserver*> observers;
    INotification* notification;
public:
    INotificationObservable(){
        this->notification=nullptr;
    }
    void addObserver(IObserver* observer) override {
        this->observers.push_back(observer);
    }

    void removeObserver(IObserver* observer) override {
        this->observers.erase(remove(this->observers.begin(),this->observers.end(),observer),this->observers.end());
    }

    void notify()override{
        for(auto &elem : this->observers){
            elem->update();
        }
    }

    INotification* getNotification(){
        return this->notification;
    }

    string getNotificationContent(){
        return this->notification->getContent();
    }

    void setNotification(INotification* newNotification){
        if(this->notification) delete this->notification;
        this->notification = newNotification;
        this->notify();
    }
    
};


//concrete observer - I

class Logger : public IObserver{
public:
    INotificationObservable *notificationobservable;
    Logger(INotificationObservable* notificationobservable){
        this->notificationobservable = notificationobservable;
    }
    void update(){
        cout<<" Logging new Notification : "<<notificationobservable->getNotificationContent()<<endl;
    }
};


//nofication strategy
class NotificationStrategy{
public:
    virtual void sendNotification() = 0;
};

class EmailStrategy :public NotificationStrategy{
private:
    string email;
public:
    EmailStrategy(string mailid){
        this->email = mailid;
    }

    void sendNotification() override{
        cout<<"Sending to email : "<<this->email<<endl;
    }

};

class SMSStrategy : public NotificationStrategy{
private:
    string mobileNum;
public:
    SMSStrategy(string num){
        this->mobileNum=num;
    }

    void sendNotification() override{
        cout<<"Sending SMS notification on +91-"<<this->mobileNum<<endl;
    }
};

class PopupStrategy : public NotificationStrategy{
public:
    void sendNotification() override{
        cout<<"Sending Pop up notification ."<<endl;
    }
};


// concrete observer - II

class NotificationEngine{
public:
    INotificationObservable* notificationObservable;
    vector<NotificationStrategy*> strategies;
    NotificationEngine(INotificationObservable* observable){
        this->notificationObservable = observable;
    }

    void addStrategy(NotificationStrategy* st){
        this->strategies.push_back(st);
    }

    void update(){
        for(auto strategy : strategies){
            strategy->sendNotification();
        }
    }
};


// notification server
class NotificationServer{
private:
    static NotificationServer* serverInstance;
    INotificationObservable* observable;
    vector<INotification*> notifications;

    NotificationServer(){
        this->observable = new INotificationObservable();
    }
public:
    static NotificationServer* getInstance(){
        if(serverInstance==nullptr) {
            serverInstance= new NotificationServer();
        }
        return serverInstance;
    }

    INotificationObservable* getObservable(){
        return this->observable;
    }

    void sendNotification(INotification* notification){
        notifications.push_back(notification);
        observable->setNotification(notification);
    }

    ~NotificationServer(){
        delete observable;
    }

};

NotificationServer* NotificationServer::serverInstance=nullptr;


int main(){

    NotificationServer* serverInstance = NotificationServer::getInstance();
    INotificationObservable* observable = serverInstance->getObservable();

    Logger* log = new Logger(observable);
    NotificationEngine* notifyEngine = new NotificationEngine(observable);
    notifyEngine->addStrategy(new EmailStrategy("vivek.patel.1057@gmail.com"));
    notifyEngine->addStrategy(new SMSStrategy("9818813195"));
    notifyEngine->addStrategy(new PopupStrategy());

   

    INotification* notification = new SimpleNotification("Hello world");
    notification =  new TimeStampDecorator(notification);
    notification = new WaterMark(notification);

    observable->setNotification(notification);
    log->update();
    notifyEngine->update();



    return 0;
}



