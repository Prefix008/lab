#include <iostream>
#include "person.h"
using namespace std;
Person::Person(){
    age=0;
    name="";
}
Person::Person(string b,int a){
    age=a;
    name=b;
}
Person::Person(const Person& p){
    age=p.age;
    name=p.name;
}
Person::~Person(){

}
void Person::set_name(string a){
    name=a;
}
void Person::set_age(int a){
    age=a;
}
string Person::get_name(){
    return name;
}
int Person::get_age(){
    return age;
}
Person& Person::operator=(const Person& p){
    name=p.name;
    age=p.age;
    return *this;
}
void Person::printinfo(){
    cout<<" name= "<<name<<" age= "<<age<<endl;
}