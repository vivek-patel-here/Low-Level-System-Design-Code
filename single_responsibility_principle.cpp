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


class Product{
public:
    int price;
    string name;

    Product(int mrp,string product_name){
        this->price=mrp;
        this->name=product_name;
    }
};


// This class voilates the Single responsibility Principle as , 
// this single class is taking responsibility of addTocart , printInvoice, calculateTotal , saveToDB .
class shopCart_SRP_Voilated{
public:
    vector<Product*> ProductList;

    void addToCart(int product_mrp , string name){
        Product* prod1 = new Product(product_mrp,name);
        this->ProductList.push_back(prod1);
    }

    void PrintInvoice(){
        cout<<"Invoice"<<endl;
        for(auto &elem : this->ProductList) cout<<elem->name<<" "<<elem->price<<endl;
        cout<<"Total Cost (inc all Taxes): "<<this->calculateTotal()<<endl;
    }

    int calculateTotal(){
        int totalCost=0;
        for(auto &elem : this->ProductList) totalCost+=elem->price;
        return totalCost;
    }

    void saveToDB(){
        cout<<"Invoice saved to DB successfully!"<<endl;
    }
};



// Below we have distrubuted the responsibility among multiple classes and each class handles responsibility(s) related to single aspect.
class ShopCart_SRP_Respected{
public:
    vector<Product*> ProductList;

    void addToCart(int product_mrp , string name){
        Product* prod1 = new Product(product_mrp,name);
        this->ProductList.push_back(prod1);
    }

    int calculateTotal(){
        int totalCost=0;
        for(auto &elem : this->ProductList) totalCost+=elem->price;
        return totalCost;
    }
};

class CastInvoice{
public:
    ShopCart_SRP_Respected* cart;

    CastInvoice(ShopCart_SRP_Respected* shopCart){
        this->cart = shopCart;
    }

    void printInvoice(){
        cout<<"Invoice"<<endl;
        for(auto &elem : this->cart->ProductList) cout<<elem->name<<" "<<elem->price<<endl;
        cout<<"Total Cost (inc all Taxes): "<<this->cart->calculateTotal()<<endl;
    }
};

class DB_Actions{
public:
    ShopCart_SRP_Respected* cart;
    DB_Actions(ShopCart_SRP_Respected* shopCart){
        this->cart = shopCart;
    }

    void saveToDB(){
        cout<<"Saved to DB successfully!"<<endl;
    }
};


int main(){

    return 0;
}