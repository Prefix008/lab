#include <queue>
#include <vector>
#include <iostream>
#include "pair.h"
using namespace std;

void print_pqueue(priority_queue<Pair>& pq) {
    priority_queue<Pair> temp = pq;
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
    cout << endl;
}

void DobSrAr(priority_queue<Pair>& pq) {
    if (pq.empty()) return;
    
    Pair sum;
    int kol = pq.size();
    priority_queue<Pair> temp = pq;
    
    while (!temp.empty()) {
        sum =sum+ temp.top();
        temp.pop();
    }
    sum.setx(sum.getx()/kol);
    sum.sety(sum.gety()/kol);
    pq.push(sum);
}

void remove_key(priority_queue<Pair>& pq, Pair a, Pair b) {
    priority_queue<Pair> new_pq;
    while (!pq.empty()) {
        Pair val = pq.top();
        pq.pop();
        if (val < a || val > b) {
            new_pq.push(val);
        }
    }
    pq = new_pq;
}

void dob(priority_queue<Pair>& pq) {
    if (pq.empty()) return;
    priority_queue<Pair> temp = pq;
    Pair max_val = temp.top();
    Pair min_val = max_val;
    while (!temp.empty()) {
        min_val = temp.top();
        temp.pop();
    }
    Pair sum = max_val + min_val;
    priority_queue<Pair> new_pq;
    while (!pq.empty()) {
        new_pq.push(pq.top() + sum);
        pq.pop();
    }
    pq = new_pq;
}

int main() {
    int n;
    cout << "Размер очереди = ";
    cin >> n;
    
    priority_queue<Pair> pq;
    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i << " : ";
        Pair h;
        cin >> h;
        pq.push(h);
    }
    print_pqueue(pq);
    
    DobSrAr(pq);
    print_pqueue(pq);
    
    Pair a, b;
    cout << "Введите a: "; cin >> a;
    cout << "Введите b: "; cin >> b;
    remove_key(pq, a, b);
    print_pqueue(pq);
    
    dob(pq);
    print_pqueue(pq);
    
    return 0;
}