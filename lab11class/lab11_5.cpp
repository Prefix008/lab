#include "list.h"
#include <iostream>
#include <queue>
using namespace std;
template <class T>
List<T> copy_pqueue_to_list(priority_queue<T> pq) {
    List<T> lst;
    while (!pq.empty()) {
        lst.pushback(pq.top());
        pq.pop();
    }
    return lst;
}

void print_pqueue(priority_queue<double>& pq) {
    priority_queue<double> temp = pq;
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
    cout << endl;
}

template <class T>
priority_queue<T> copy_list_to_pqueue(List<T> lst) {
    priority_queue<T> pq;
    for(auto it=lst.first();it!=lst.last();++it){
        pq.push(*it);
    }
    return pq;
}
void DobSrAr(priority_queue<double>& pq) {
    if (pq.empty()) return;
    List<double> lst = copy_pqueue_to_list(pq);
    double sum = 0;
    for(auto it=lst.first();it!=lst.last();++it){
        sum+=*it;
    }
    double average = sum / lst();
    lst.pushback(average);
    pq = copy_list_to_pqueue(lst);
}
void remove_key(priority_queue<double>& pq, double a, double b) {
    List<double> lst = copy_pqueue_to_list(pq);
    auto it = lst.first();
    while (it != lst.last()) {
        if (*it >= a && *it <= b) {
            it = lst.erase(it);  
        } else {
            ++it;
        }
    }
    pq = copy_list_to_pqueue(lst);
}
void dob(priority_queue<double>& pq) {
    if (pq.empty()) return;
    
    List<double> lst = copy_pqueue_to_list(pq);
    
    double max_val = lst.front(); 
    double min_val = lst.back();
    double sum=max_val+min_val;
    for(auto it=lst.first();it!=lst.last();++it){
        *it+=sum;
    }
    pq = copy_list_to_pqueue(lst);
}

int main(){
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