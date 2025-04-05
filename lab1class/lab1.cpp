#include "fraction.h"
#include <iostream>
using namespace std;
fraction make(double f, int s) {
    fraction temp;
    temp.init(f, s);
    return temp;
}
int main(){
    fraction a;
    a.init(0.5,2);
    a.show();
    cout<<a.element(3)<<endl;
    fraction b;
    b.read();
    cout<<b.element(2)<<endl;
    fraction* g=new fraction;
    g->init(0.2,2);
    cout<<g->element(3)<<endl;
    fraction arr[3];
    for (int i = 0; i < 3; i++) {
        arr[i].read();
    }
     for (int i = 0; i < 3; i++) {
        cout << arr[i].element(3) << endl;
    }
    fraction* arr1=new fraction[3];
    for (int i = 0; i < 3; i++) {
        arr1[i].read();
    }
     for (int i = 0; i < 3; i++) {
        cout << arr1[i].element(3) << endl;
    }
    double y;
    int z;
    cin >> y>>z;
    fraction f = make(y, z);
    f.show();
    cout << f.element(3) << endl;
    return 0;
}