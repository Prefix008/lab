#include "fraction.h"
#include <iostream>
using namespace std;
void fraction::init(double f, int s){
    first=f;
    second=s;
}
void fraction::read() {
  cin >> first;
  cin >> second;
}
void fraction::show(){
    cout << first << endl;
    cout << second << endl;
}
double fraction::element(int j){
    return first+second*(j-1);
}