#include <iostream>
#include "pair.h"
using namespace std;
Pair operator+(int xx, const Pair& p) {
    return p + xx; 
}
Pair operator+(double yy, const Pair& p) {
    return p + yy; 
}
ostream& operator<<(ostream& stream, const Pair& p) {
    stream << '(' << p.x << ':' << p.y << ')';
    return stream;
}
int main(){
    Pair a(39, 32);
    Pair b(10, 6);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Вычитание: " << a - b << endl;
    cout << "a + 10 = " << a + 10 << endl;
    cout << "10 + a = " << 10 + a << endl; 
    cout << "a + 7.5 = " << a + 7.5 << endl;
    cout << "7.5 + a = " << 7.5 + a << endl;

    return 0;
}