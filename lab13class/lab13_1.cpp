#include <list>
#include <iostream>
#include "pair.h"
#include <algorithm>
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
    Pair sum;
    for_each(lst.begin(),lst.end(),[&sum](Pair& p){sum=sum+p;});
    sum.setx(sum.getx()/lst.size());
    sum.sety(sum.gety()/lst.size());
    lst.push_back(sum);
}
void remove_key(list<Pair>& lst,Pair a,Pair b){
    list<Pair>::iterator it=remove_if(lst.begin(),lst.end(),[a,b](Pair& p){return p>=a && p<=b;});
    lst.erase(it,lst.end());
}
void dob(list<Pair>& lst){
    list<Pair>::iterator it=min_element(lst.begin(),lst.end());
    list<Pair>::iterator it1=max_element(lst.begin(),lst.end());
    Pair sum=(*it)+(*it1);
    for_each(lst.begin(),lst.end(),[sum](Pair& p){p=p+sum;});
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