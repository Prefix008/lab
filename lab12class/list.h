#pragma once
#include <iostream>
#include <set>
using namespace std;
template <typename T>
class List {
private:
    int size;
    multiset<T> ms;
public:
    List():size(0){};
    List(int n);
    ~List(); 
    void Print();
    void make_multiset(int n);
    void DobSrAr();
    void remove_key(T,T);
    void dob();
};
template <typename T>
List<T>::List(int n) {
    size=n;
}
template <typename T>
List<T>::~List() {
}
template <typename T>
void List<T>:: Print(){
    for (auto x : ms) {
        cout << x << endl;
    }
    cout << endl;
}
template <typename T>
void List<T>::make_multiset(int n) {
    for (int i = 0; i < n; i++) {
        cout << "Элемент multiset " << i << " : ";
        T h;
        cin >> h;
        ms.insert(h);
    }
}
template <typename T>
void List<T>::DobSrAr() {
    if (ms.empty()) return;
    double sum=0;
    for (auto x : ms) {
        sum+=x;
    }
    double average = sum / ms.size();
    ms.insert(average);
}
template <typename T>
void List<T>::remove_key(T a, T b) {
    auto it = ms.begin();
    while (it != ms.end()) {
        if (*it >= a && *it <= b) {
            it = ms.erase(it);  
        } else {
            ++it;
        }
    }
}
template <typename T>
void List<T>::dob() {
    if (ms.empty()) return;
    T min_val = *ms.begin();      
    T max_val = *ms.rbegin();      
    T sum = min_val + max_val;
    multiset<T> new_ms;
    for (auto x : ms) {
        new_ms.insert(x + sum);
    }
    ms = new_ms;
}