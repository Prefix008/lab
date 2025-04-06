#include"person.h"
#include "student.h"
#include "vector.h"
#include <iostream>
using namespace std;
ostream& operator<<(ostream& st,const Person& p){
    st<<" name= "<<p.name<<" age= "<<p.age;
    return st;
}
istream& operator>>(istream& st,Person& p){
    cout<<" name = ";
    st>>p.name;
    cout<<" age = ";
    st>>p.age;
    return st;
}
ostream& operator<<(ostream& st,const Student& p){
    st<<" name= "<<p.name<<" age= "<<p.age<<" subject= "<<p.subject<<" mark= "<<p.mark;
    return st;
}
istream& operator>>(istream& st,Student& p){
    Person* ptr=&p;
    st>>*ptr;
    cout<<" subject = ";
    st>>p.subject;
    cout<<" mark = ";
    st>>p.mark;
    return st;
}
ostream& operator<<(ostream& st,const Vector& p){
    Object** a=p.beg;
    for(int i=0;i<p.size;i++){
        (*a)->show();
        ++a;
    }
    return st;
}
int main(){
    Person* personPtr = new Student("Anna", 19, 4, "Physics");
    personPtr->show();
    delete personPtr;

    Vector v(2);
    v.add(new Person("Test", 30));
    v.add(new Student("TestStudent", 20, 5, "Math"));
    cout << v;

    return 0;
}
