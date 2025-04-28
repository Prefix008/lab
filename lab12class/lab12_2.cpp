#include <iostream>
#include <set>
#include "pair.h"
using namespace std;
multiset<Pair> make_multiset(int n) {
    multiset<Pair> ms;
    for (int i = 0; i < n; i++) {
        cout << "Элемент multiset " << i << " : ";
        Pair h;
        cin >> h;
        ms.insert(h);
    }
    return ms;
}

void print_multiset(multiset<Pair>& ms) {
    for (auto x : ms) {
        cout << x << endl;
    }
    cout << endl;
}

void DobSrAr(multiset<Pair>& ms) {
    if (ms.empty()) return;
    Pair sum;
    for (auto x : ms) {
        sum=sum+x;
    }
    sum.setx(sum.getx()/ms.size());
    sum.sety(sum.gety()/ms.size());
    ms.insert(sum);
}

void remove_key(multiset<Pair>& ms, Pair a, Pair b) {
    auto it = ms.begin();
    while (it != ms.end()) {
        if (*it>=a && *it <= b) {
            it = ms.erase(it);  
        } else {
            ++it;
        }
    }
}

void dob(multiset<Pair>& ms) {
    if (ms.empty()) return;
    
    Pair min_val = *ms.begin();      
    Pair max_val = *ms.rbegin();      
    Pair sum = min_val + max_val;
    
    multiset<Pair> new_ms;
    for (auto x : ms) {
        new_ms.insert(x + sum);
    }
    ms = new_ms;
}

int main() {
    int n;
    cout << "Размер multiset = ";
    cin >> n;
    
    multiset<Pair> ms = make_multiset(n);
    

    print_multiset(ms);
    
    DobSrAr(ms);
    print_multiset(ms);
    
    Pair a, b;
    cout << "Введите a: "; cin >> a;
    cout << "Введите b: "; cin >> b;
    remove_key(ms, a, b);
    print_multiset(ms);
    
    dob(ms);
    print_multiset(ms);
    
    return 0;
}