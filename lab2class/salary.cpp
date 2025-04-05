#include <iostream>
#include <string>
#include "salary.h"
using namespace std;
Salary::Salary()
{
    fio = "";
    salary = 0;
    bonus = 0;
    cout << "Вызван конструктор без параметров " <<endl;
}
Salary::Salary(string str, double sal, int bon)
{
    fio = str;
    salary = sal;
    bonus = bon;
    cout << "Вызван конструктор с параметрами" <<endl;
}

Salary::Salary(Salary& t)
{
    fio = t.fio;
    salary = t.salary;
    bonus = t.bonus;
    cout << "Вызван конструктор копирования" <<endl;
}
Salary::~Salary()
{
    cout << "Вызван деструктор" << endl;
}
string Salary::get_fio()
{
    return fio;
}
double Salary::get_salary()
{
    return salary;
}
int Salary::get_bonus()
{
    return bonus;
}
void Salary::set_fio(string str)
{
    fio = str;
}

void Salary::set_salary(double sal)
{
    salary = sal;
}

void Salary::set_bonus(int bon)
{
    bonus = bon;
}
void Salary::show()
{
    cout << "ФИО: " << fio << endl;
    cout << "З/П: " << salary << endl;
    cout << "Премия: " << bonus<< endl;
}