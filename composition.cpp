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


// Composition : It is a type of relation in which one class contains the object of another class as its property;

class Book{
public:
    string code;
    string author;
    string title;
    string publisher;

    Book(string code,string author,string title ,string publisher){
        this->code = code;
        this->author = author;
        this->title = title;
        this->publisher = publisher;
    }
};

class Library{
public:
    vector<Book*> bookList;

    Library(){
        Book* b1 = new Book("COCSC110","Vivek Kurmi","basic Programming Paradigms","TCP Publications");
        Book* b2 = new Book("COCSC111","Vivek Kurmi","Intermediate Programming Idiology","TCP Publications");
        Book* b3 = new Book("COCSC112","Vivek Kurmi","Advanced Programming Techniques","TCP Publications");
        this->bookList.push_back(b1);
        this->bookList.push_back(b2);
        this->bookList.push_back(b3);
    }

    void availableBooks(){
        cout<<endl<<endl<<"Available Books :"<<endl<<endl;
        for(auto elem : this->bookList){
            cout<<"Code : "<<elem->code<<endl<<"Author : "<<elem->author<<endl<<"Title : "<<elem->title<<endl<<"Publisher : "<<elem->publisher<<endl<<endl;
        }
    }

};


int main(){

    Library lib;
    lib.availableBooks();
    return 0;
}