#pragma once
#include<string>
#include "person.h"
using namespace std;
class Student:public Person{
    int mark;
    string subject;
    public:
    Student();
    Student(string,int,int,string);
    Student(const Student&);
    ~Student();
    void set_subject(string);
    void set_mark(int);
    int get_mark();
    string get_subject();
    Student& operator=(const Student&);
    friend ostream& operator<<(ostream&,const Student&);
    friend istream& operator>>(istream&,Student&);
    void printinfo();
};