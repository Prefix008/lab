#include <queue>
#include <vector>
#include <iostream>
using namespace std;

void print_pqueue(priority_queue<double>& pq) {
    priority_queue<double> temp = pq;
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
    cout << endl;
}

void DobSrAr(priority_queue<double>& pq) {
    if (pq.empty()) return;
    
    double sum = 0;
    int kol = pq.size();
    priority_queue<double> temp = pq;
    
    while (!temp.empty()) {
        sum += temp.top();
        temp.pop();
    }
    
    pq.push(sum / kol);
}

void remove_key(priority_queue<double>& pq, double a, double b) {
    priority_queue<double> new_pq;
    while (!pq.empty()) {
        double val = pq.top();
        pq.pop();
        if (val < a || val > b) {
            new_pq.push(val);
        }
    }
    pq = new_pq;
}

void dob(priority_queue<double>& pq) {
    if (pq.empty()) return;
    priority_queue<double> temp = pq;
    double max_val = temp.top();
    double min_val = max_val;
    while (!temp.empty()) {
        min_val = temp.top();
        temp.pop();
    }
    double sum = max_val + min_val;
    priority_queue<double> new_pq;
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
    
    priority_queue<double> pq;
    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i << " : ";
        double h;
        cin >> h;
        pq.push(h);
    }
    print_pqueue(pq);
    
    DobSrAr(pq);
    print_pqueue(pq);
    
    double a, b;
    cout << "Введите a: "; cin >> a;
    cout << "Введите b: "; cin >> b;
    remove_key(pq, a, b);
    print_pqueue(pq);
    
    dob(pq);
    print_pqueue(pq);
    
    return 0;
}