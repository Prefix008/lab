#pragma once
#include "object.h"
#include "print.h"
#include "magazin.h"
#include <iostream>
using namespace std;
class Vector{
    protected:
    object** beg;
    int size;
    int cur;
    public:
    Vector(){
        beg=nullptr; size=0; cur=0;
    }
    Vector(int a){
        beg=new object* [a];
        size=a;
        cur=0;
    }
    void add(){
        cout<<"1.print"<<endl;
        cout<<"2.magazin"<<endl;
        int y;
        cin>>y;
        if(y==1){
            print* a=new print;
            a->input();
            beg[cur]=a;
            cur++;

        }
        else{
            magazin* a=new magazin;
            a->input();
            beg[cur]=a;
            cur++;
        }
    }
    void show(){
        object** d=beg;
        for(int i=0;i<cur;i++){
            (*d)->show();
            d++;

        }
    }
    void del(){
        cur--;
    }
    void get(){
        object** d=beg;
        for(int i=0;i<cur;i++){
            cout<<(*d)->get_name()<<endl;
            d++;
        }
    }
};