#include"object.h"
#pragma once
#include<string>
using namespace std;
class Person : public Object {
    protected:
    string name;
    int age;
    public:
    Person();
    Person(string,int);
    Person(const Person&);
    ~Person() override;
    void set_name(string);
    void set_age(int);
    string get_name();
    int get_age();
    Person& operator=(const Person&);
    friend ostream& operator<<(ostream&,const Person&);
    friend istream& operator>>(istream&,Person&);
    void show() override;
      
};