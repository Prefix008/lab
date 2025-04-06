#include"person.h"
#include "student.h"
#include "student.h"
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
int main(){
    Person p1;
    cin >> p1;
    cout << p1 << endl;

    Student s1;
    cin >> s1;
    cout << s1 << endl;
     
    Student s3("Alice", 20, 4, "Physics");
    Student s4 = s3;
    cout<<s4<<endl;
    

    Student s2("Ivan", 20, 5, "Math");
    s2.printinfo();

    Person* personPtr = new Student("Anna", 19, 4, "Physics");
    personPtr->printinfo();
    delete personPtr;

    return 0;
}
