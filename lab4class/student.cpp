
#include <iostream>
#include "student.h"
#include "person.h"
using namespace std;
Student::Student(): Person(),mark(0),subject("")
{}
Student::Student(string a, int b, int c, string d) 
    : Person(a, b), mark(c), subject(d) {}
Student::Student(const Student& s) 
    : Person(s), mark(s.mark), subject(s.subject) {}
Student::~Student(){
}
void Student::set_mark(int m) { 
    mark = m; 
}
void Student::set_subject(string s) { 
    subject = s; 
}
int Student::get_mark(){
    if (mark <= 3) {
        cout << "Плохая оценка!";
    }
    return mark;
}
string Student::get_subject() { 
    return subject; 
}
Student& Student::operator=(const Student& s) {
    name=s.name;
    age=s.age;
    subject = s.subject;
    mark = s.mark;
    return *this;
}
void Student::printinfo(){
    Person::printinfo();
    cout<<" subject= "<<subject<<" mark= "<<mark<<endl;
}