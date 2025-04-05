#include <string>
#pragma once
using namespace std;
class Salary{
    string fio;
    double salary;
    int bonus;
    public:
    Salary();
    Salary(string,double,int);
    Salary(Salary&);
    ~Salary();
    string get_fio();
    double get_salary();
    int get_bonus();
    void set_fio(string str);
    void set_salary(double sal);
    void set_bonus(int bon);
    void show();

};