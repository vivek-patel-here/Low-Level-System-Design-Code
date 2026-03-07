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


// Composite Design Pattern : It is used to compose object in a tree like heirarchy.
//We are going to implement a file system using this composite design pattern

class FileSystemItem{
protected:    
    string name;
    int size;
public:
    virtual int getSize() = 0;
    virtual string getName() = 0;
    virtual void OpenAll(int indent = 0) = 0;
};

class File : public FileSystemItem{
public:
    File(string nm , int sz){
        this->name = nm;
        this->size = sz;
    }

    int getSize()override{
       return this->size;
    }

    string getName()override{
        return this->name;
    }

    void OpenAll(int indent=0)override{
        string s(indent,' ');
        s+='-';
        cout<<s<<getName()<<endl;
    }


};


class Folder :public FileSystemItem{
private:
    vector<FileSystemItem*> itemList;
public:
    Folder(string nm){
        this->name=nm;
    }

    int getSize()override{
        int totalSize = 0;
        for(auto elem : itemList){
            totalSize+=elem->getSize();
        }
        this->size = totalSize;
        return totalSize;
    }

    string getName()override{
        return this->name;
    }

    void OpenAll(int indent=0)override{
        string s(indent,' ');
        s+='-';
        cout<<s<<getName()<<endl;
        for(auto child : this->itemList){
            child->OpenAll(indent+1);
        }
    }   

    void addItem(FileSystemItem* newItem){
        this->itemList.push_back(newItem);
    }

    void removeItem(FileSystemItem* item){
        this->itemList.erase(remove(this->itemList.begin(),this->itemList.end(),item),this->itemList.end());
    }
};


int main(){
    Folder* root = new Folder("root");
    File* file1 = new File("file1.txt",12);
    File* file2 = new File("file2.txt",24);
    Folder* folder1 = new Folder("folder1");
    Folder* folder2 = new Folder("folder2");
    Folder* folder3 = new Folder("folder3");
    File* file3 = new File("file3.txt",30);
    File* file4 = new File("file4.txt",40);
    File* file5 = new File("file5.txt",55);
    File* file6 = new File("file6.txt",97);
    File* file7 = new File("file7.txt",695);

    root->addItem(file1);
    root->addItem(file2);
    folder1->addItem(file3);
    folder2->addItem(file4);
    folder3->addItem(file5);
    folder3->addItem(file6);
    folder2->addItem(folder3);
    root->addItem(folder1);
    root->addItem(folder2);
    root->addItem(file7);

    root->OpenAll();

    return 0;
}