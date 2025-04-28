#include <list>
#include <iostream>
#include "pair.h"
using namespace std;
list<Pair> make_list(int n){
    list<Pair> lst;
    for(int i=0;i<n;i++){
        cout<<"Элемент списка "<<i<<" : ";
        Pair h;
        cin>>h;
        lst.push_back(h);
    }
    return lst;
}
void print_list(list<Pair>& lst){
    for(const Pair& x:lst){
        cout<<x<<endl;
    }
    cout<<endl;
}
void DobSrAr(list<Pair>& lst){
    Pair sum(0,0);
    for(const Pair& x:lst){
        sum=sum+x;
    }
    Pair sum2;
    sum2.setx(sum.getx()/lst.size());
    sum2.sety(sum.gety()/lst.size());
    lst.push_back(sum2);
}
void remove_key(list<Pair>& lst,Pair a,Pair b){
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it >= a && *it <= b) {
            it = lst.erase(it);  
        } else {
            ++it;
        }
    }
}
void dob(list<Pair>& lst){
    Pair max=lst.front();
    Pair min=lst.front();
    for(Pair& x:lst){
        if (x.getx() > max.getx() || (x.getx() == max.getx() && x.gety() > max.gety())) {
            max = x;
        }
        if (x.getx() < min.getx() || (x.getx() == min.getx() && x.gety() < min.gety())) {
            min = x;
        }
    }
    Pair sum=max+min;
    for(auto it=lst.begin();it!=lst.end();++it){
        *it=*it+sum;
    }
}
int main(){
    int n;
    cout<<"Размер списка = ";
    cin>>n;
    list<Pair> lst;
    lst=make_list(n);
    print_list(lst);
    DobSrAr(lst);
    print_list(lst);
    Pair a,b;
    cout<<"Введите a: "; cin>>a;
    cout<<"Введите b: "; cin>>b;
    remove_key(lst,a,b);
    print_list(lst);
    dob(lst);
    print_list(lst);

    
    return 0;
}