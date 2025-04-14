#pragma once
#include "object.h"
#include <iostream>
using namespace std;
class print:public object{
    protected:
    string name;
    string autor;
    public:
    ~print() override{};
    print():name(""),autor(""){}
    print(string n,string a):name(n),autor(a){}
    print(const print& t){name=t.name; autor=t.autor;}
    string get_name() override {return name;}
    string get_autor(){return autor;}
    print& operator=(const print& t){name=t.name; autor=t.autor; return *this;}
    void set_name(string n){name=n;}
    void set_autor(string a){autor=a;}
    void show() override{
        cout<<"name= "<<name<<" autor= "<<autor<<endl;
    }
    void input() override{
        cout<<"name= ";
        cin>>name;
        cout<<"autor= ";
        cin>>autor;
    }
};