#include <iostream>
#include <set>
#include <numeric> 
using namespace std;
multiset<double> make_multiset(int n) {
    multiset<double> ms;
    for (int i = 0; i < n; i++) {
        cout << "Элемент multiset " << i << " : ";
        double h;
        cin >> h;
        ms.insert(h);
    }
    return ms;
}

void print_multiset(multiset<double>& ms) {
    for (auto x : ms) {
        cout << x << endl;
    }
    cout << endl;
}

void DobSrAr(multiset<double>& ms) {
    if (ms.empty()) return;
    double sum=0;
    for (auto x : ms) {
        sum+=x;
    }
    double average = sum / ms.size();
    ms.insert(average);
}

void remove_key(multiset<double>& ms, double a, double b) {
    auto it = ms.begin();
    while (it != ms.end()) {
        if (*it >= a && *it <= b) {
            it = ms.erase(it);  
        } else {
            ++it;
        }
    }
}

void dob(multiset<double>& ms) {
    if (ms.empty()) return;
    
    double min_val = *ms.begin();      
    double max_val = *ms.rbegin();      
    double sum = min_val + max_val;
    
    multiset<double> new_ms;
    for (auto x : ms) {
        new_ms.insert(x + sum);
    }
    ms = new_ms;
}

int main() {
    int n;
    cout << "Размер multiset = ";
    cin >> n;
    
    multiset<double> ms = make_multiset(n);
    

    print_multiset(ms);
    
    DobSrAr(ms);
    print_multiset(ms);
    
    double a, b;
    cout << "Введите a: "; cin >> a;
    cout << "Введите b: "; cin >> b;
    remove_key(ms, a, b);
    print_multiset(ms);
    
    dob(ms);
    print_multiset(ms);
    
    return 0;
}