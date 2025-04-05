#include "salary.h"
#include <iostream>
using namespace std;
Salary make(){
    string str;
    double salary;
    int bonus;
    cout<<"ФИО: ";
    getline(cin,str);
    cout<<"З/П: ";
    cin>>salary;
    cout<<"Бонус: ";
    cin>>bonus;
    Salary temp(str,salary,bonus);
    return temp;

    
}
void print(Salary temp){
    temp.show();
}
int main(){
    Salary s;
    s.show();
    Salary s1("Denis",2000,10);
    s1.show();
    Salary s2;
    s2=s1;
    s2.set_fio("Sergey");
    s2.set_salary(2500);
    s2.set_bonus(20);
    print(s2);

    s1=make();
    s1.show();

    return 0;
}