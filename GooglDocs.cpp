#include <iostream>
#include <fstream>
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

// This project shows the implementation of the Google Docs using Oops and SOLID principle.


// Bad Design
class Docs{
private:
    string renderedDocument;
    vector<string> docs_Element;
public:
    Docs(){
        renderedDocument="";
        docs_Element.resize(0);
    }

    void addText(string text){
        docs_Element.push_back(text);
    }

    void addImage(string path){
        docs_Element.push_back(path);
    }

    string renderDoc(){
        if(renderedDocument.empty()){
            string result;
            for(auto element : docs_Element){
                if((element.size() > 4) && (element.substr(element.size()-4)==".jpg")|| (element.substr(element.size()-4)==".png")){
                    result+="[Image Path : "+element+" ]\n";
                }else result+=element+'\n';
            }
            renderedDocument=result;
        }

        return renderedDocument;
    }

    void saveTofile(){
        ofstream file("console.txt");
        if(file.is_open()){
            file<<renderDoc();
            file.close();
            cout<<"Document Saved to file"<<endl;
        }else{
            cout<<"Error in saving the Document"<<endl;
        }
    }
};


/*
Reason why the above design Is bad :
    - It is voilating Single responsibility Priciple 
        - One single class is handling multiple task , accepting text and file , rendering document , saving to file .
    - It is voilating Open close principle.
        - The class is not scalable if we want to add new feature like addTabSpace , addShapes , addColors or saveToDB() etc.. ,
            we need to madify the same class
        - Hence It is voilating the open close principle.
    - It is also voilating LSP , ISP and DIP as well.
*/



//Better Design

// Docs Element Module
class DocsElement{
public:
    virtual string render() = 0;
};

class TextElement : public DocsElement{
private:
    string content ;
public:
    TextElement(string text){
        this->content = text;
    }

    string render() override{
        return content;
    }
};

class ImageElement : public DocsElement{
private:
    string content ;
public:
    ImageElement(string ImgPath){
        this->content  = "[ Image Path : " + ImgPath + " ]";
    }

    string render() override{
        return content;
    }
};

class NewLineElement : public DocsElement{
private:
    string content ;
public:
    NewLineElement(){
        this->content = "\n";
    }
    string render() override{
        return content;
    }
};

class TabElement : public DocsElement{
private:
    string content ;
public:
    TabElement(){
        this->content = "\t";
    }
    string render() override{
        return content;
    }
};


// DB module
class Persistance{
public:
    virtual void save(string docs) = 0;
};

class SaveTofile : public Persistance{
public:
    void save(string docs) override{
        ofstream f("Output.txt");
        f<<docs;
        f.close();
    }
};

class SaveToSQL : public Persistance{
public:
    void save(string docs) override{

    }
};

class SaveToMongo : public Persistance{
public:
    void save(string docs) override{

    }
};


// Document Sheet Interface Module
class Document{
private:
    vector<DocsElement*> docs;
public:
    void addElement(DocsElement* elem){
        this->docs.push_back(elem);
    }

    string render(){
        string docsContent = "";
        for(auto &elem : docs){
            docsContent+=elem->render();
        }
        return docsContent;
    }
};

// Actuall High level Module 
class Docs_Scalable{
private:
    Document* dc;
    Persistance* db;
public:
    Docs_Scalable(Document* dc , Persistance* db){
        this->dc = dc;
        this->db = db;
    }

    void addText(string text){
        dc->addElement(new TextElement(text));
        dc->addElement(new NewLineElement());
    }

    void addImage(string Path){
        dc->addElement(new TabElement());
        dc->addElement(new ImageElement(Path));
        dc->addElement(new NewLineElement());
    }

    string render(){
        return dc->render();
    }

    void save(){
        db->save(dc->render());
    }
};

/*
Why this design is good : 
    - Above code is modular , scalable and maintainable.
    - It is following Single responsibility principle.
    - It is following Open Close Principle :
        - New Document element , new Persistance method can be add easily without modifying the old code.
    - It is following Liskov Substitution Principle , Interface Substitution Priciple and dependency Inversion principle .
*/

int main(){
    // Client Code for Bad Design
    Docs d;
    d.addText("Hello world");
    d.addImage("profile.jpg");
    cout<<d.renderDoc();
    d.saveTofile();


    // Client code for good Design
    Docs_Scalable d2(new Document(),new SaveTofile());
    d2.addImage("Profile.jpg");
    d2.addText("hello world");
    cout<<d2.render();
    d2.save();

    return 0;
}