#include <iostream>
#include "list.h"
using namespace std;

int main() {
    int n;
    cout << "Размер multiset = ";
    cin >> n;
    List<double> lst(n);
    
    lst.make_multiset(n);
    lst.Print();
    
    lst.DobSrAr();
    lst.Print();
    
    double a, b;
    cout << "Введите a: "; cin >> a;
    cout << "Введите b: "; cin >> b;
    lst.remove_key(a, b);
    lst.Print();
    
    lst.dob();
    lst.Print();
    
    return 0;
}