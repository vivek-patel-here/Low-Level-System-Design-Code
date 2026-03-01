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
Observer design pattern defines a one - to many relationship between an observable/subject class and the observer class.
Whenever the state of observable is changed , observer should be notified and updated automatically.
Examples of observer design pattern are youtube , notification system , event-handling on frontend etc..
*/

// We are going to implement Youtube to under the observer design pattern better

class ISubscriber{
public:
    virtual void update() = 0 ;
};


class IYtChannel{
public:
    virtual void subscribe(ISubscriber* sub)=0;
    virtual void unSubscribe(ISubscriber* sub)=0;
    virtual void notify()=0;
};


class Channel : public IYtChannel{
private:
    string latest_video;
    unordered_set<ISubscriber*> subscribersList;
public:
    string channel_name;
    Channel(string nm){
        this->channel_name=nm;
    }

    void subscribe(ISubscriber* sub) override{
        this->subscribersList.insert(sub);
    }

    void unSubscribe(ISubscriber* sub) override{
        this->subscribersList.erase(sub);
    }

    void notify() override{
        for(auto subscriber : this->subscribersList){
            subscriber->update();
        }
    }

    void uploadVideo(string videoTitle){
        this->latest_video=videoTitle;
        cout<<"Video Uploaded Successfully : "<<videoTitle<<endl;
        this->notify();
    }

    string getLatestVideoInfo(){
        return this->latest_video;
    }
};


class Subscriber : public ISubscriber{
public:
    string name;
    Channel* channel;
    Subscriber(string nm,Channel* ch){
        this->name=nm;
        this->channel=ch;
    }

    void update() override{
        cout<<"Hi "<<this->name<<" !"<<endl;
        cout<<"Check out "<<this->channel->channel_name<<"'s latest video : "<<this->channel->getLatestVideoInfo()<<endl;
    }
};






int main(){
    Channel* myChannel = new Channel("Mr Beast");
    Subscriber* sub1 = new Subscriber("Amit",myChannel);
    Subscriber* sub2 = new Subscriber("Durgesh",myChannel);
    myChannel->subscribe(sub1);
    myChannel->subscribe(sub2);
    myChannel->uploadVideo("100 zombie vs 100 humans");
    myChannel->unSubscribe(sub2);
    myChannel->uploadVideo("200 Day in a dungeon");
    return 0;
}