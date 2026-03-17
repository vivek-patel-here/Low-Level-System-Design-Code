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

// Template Design Pattern provides a template method that executes the pipeline step in specific order
// the various steps involved in the pipeline executes in the desired order only.

class ModelTrainer{
public:
    virtual void loadData(string Path) = 0;
    virtual void preprocessDataset() = 0;
    virtual void trainModel() = 0;
    virtual void Evaluate() = 0;
    virtual void save() = 0;

    // pipeline method : This method must not change by the child classes.
    const void templateModel(string path){
        loadData(path);
        preprocessDataset();
        trainModel();
        Evaluate();
        save();
    }
};


// CNN model class
class CNN : public ModelTrainer {
public:
    void loadData(string Path) override{
        cout<<"CNN Dataset has Loaded from the path :"<<Path<<endl;
    }

    void preprocessDataset()override{
        cout<<"Data preprocessing done"<<endl;
        cout<<"Dataset is ready to train CNN model"<<endl;
    }

    void trainModel()override{
        cout<<"CNN training started ..."<<endl;
        cout<<"CNN training done"<<endl;
    }

    void Evaluate() override{
        cout<<"Model has evaluated and validated on test dataset"<<endl;
        cout<<"Model accuracy : 99.99%"<<endl;
    }

    void save()override{
        cout<<"Your CNN model has been successfully saved on cloud"<<endl;
    }
};

// Ml model class 
class ML : public ModelTrainer {
public:
     void loadData(string Path) override{
        cout<<"ML Dataset has Loaded from the path :"<<Path<<endl;
    }

    void preprocessDataset()override{
        cout<<"Data preprocessing done"<<endl;
        cout<<"Dataset is ready to train your ML model"<<endl;
    }

    void trainModel()override{
        cout<<"ML training started ..."<<endl;
        cout<<"ML training done"<<endl;
    }

    void Evaluate() override{
        cout<<"Model has evaluated and validated on test dataset"<<endl;
        cout<<"Model accuracy : 96.97%"<<endl;
    }

    void save()override{
        cout<<"Your ML model has been successfully saved on your device"<<endl;
    }
};


// Both the model cannot change the order of the pipeline steps.

int main(){

    ModelTrainer* machine_learning = new ML();
    ModelTrainer* deep_learning = new CNN();

    machine_learning->templateModel("C:/user/desktop/ML_project/data/train");
    deep_learning->templateModel("C:/user/desktop/CNN_project/data/train");

    return 0;
}