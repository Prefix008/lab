#include <queue>
#include <vector>
#include <iostream>
#include "pair.h"
#include <map>
using namespace std;

void print_m(map<int,Pair>& m) {
    map<int,Pair> temp = m;
    for(auto it=m.begin();it!=m.end();++it){
        cout << "Key: " << it->first << " Value: " << it->second << endl;
    }
    cout << endl;
}

void DobSrAr(map<int,Pair>& m) {
    if (m.empty()) return;
    Pair sum;
    for(auto it=m.begin();it!=m.end();++it){
        sum=sum+it->second;
    }
    sum.setx(sum.getx()/m.size());
    sum.sety(sum.gety()/m.size());
    m.insert(make_pair(m.size(),sum));
}

void remove_key(map<int,Pair>& m, Pair a, Pair b) {
    map<int,Pair> m1;
    for(auto it=m.begin();it!=m.end();++it){
        if (it->second < a ||it->second> b) {
            m1.insert(*it);
        }
    }
    m = m1;
}

void dob(map<int,Pair>& m) {
    Pair min=m.begin()->second;
    Pair max=m.begin()->second;
    for(auto it=m.begin();it!=m.end();++it){
        if (it->second >max) {
            max=it->second;
        }
        if (it->second <min) {
            min=it->second;
        }
    }
    map<int,Pair> m1; 
    for(auto it=m.begin();it!=m.end();++it){
      m1.insert(make_pair(it->first,it->second+max+min));
    }
    m = m1;
}

int main() {
    int n;
    cout << "Размер словаря = ";
    cin >> n;
    
    map<int,Pair> m;
    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i << " : ";
        Pair h;
        cin >> h;
        m.insert(make_pair(i,h));
    }
    print_m(m);
    
    DobSrAr(m);
    print_m(m);
    
    Pair a, b;
    cout << "Введите a: "; cin >> a;
    cout << "Введите b: "; cin >> b;
    remove_key(m, a, b);
    print_m(m);
    
    dob(m);
    print_m(m);
    
    return 0;
}