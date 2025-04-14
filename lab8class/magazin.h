#pragma once
#include "print.h"
#include <iostream>
using namespace std;
class magazin:public print{
    int count;
    public:
    ~magazin() override{};
    magazin():print(),count(0){}
    magazin(string n,string a,int c):print(n,a),count(c){}
    magazin(const magazin& t):print(t), count(t.count){}
    magazin& operator=(const magazin& t){name=t.name; autor=t.autor; count=t.count; return*this;}
    void set_count(int c){count=c;}
    int get_count(){return count;}
    void show() override{
        cout<<"name= "<<name<<" autor= "<<autor<<" count= "<<count<<endl;
    }
    void input() override{
        cout<<"name= ";
        cin>>name;
        cout<<"autor= ";
        cin>>autor;
        cout<<"count= ";
        cin>>count;
    }

};