#include "list.h"
#include <iostream>
using namespace std;
List<double> make_List(int n){
    List<double> lst;
    for(int i=0;i<n;i++){
        cout<<"Элемент списка "<<i<<" : ";
        double h;
        cin>>h;
        lst.pushback(h);
    }
    return lst;
}
void print_List(List<double>& lst){
    for(auto it=lst.first();it!=lst.last();++it){
        cout<<*it<<endl;
    }
    cout<<endl;
}
void DobSrAr(List<double>& lst){
    double sum=0;
    int kol=lst();
    for(auto it=lst.first();it!=lst.last();++it){
        sum+=*it;
    }
    lst.pushback(sum/kol);
}
void remove_key(List<double>& lst,double a,double b){
    auto it = lst.first();
    while (it != lst.last()) {
        if (*it >= a && *it <= b) {
            it = lst.erase(it);  
        } else {
            ++it;
        }
    }
}
void dob(List<double>& lst){
    double max=lst.front();
    double min=lst.front();
    for(auto it=lst.first();it!=lst.last();++it){
        if(*it>max){
            max=*it;
        }
        if(*it<min){
            min=*it;
        }
    }
    int sum=max+min;
    for(auto it=lst.first();it!=lst.last();++it){
        *it+=sum;
    }
}
int main(){
    int n;
    cout<<"Размер списка = ";
    cin>>n;
    List<double> lst;
    lst=make_List(n);
    print_List(lst);
    DobSrAr(lst);
    print_List(lst);
    double a,b;
    cout<<"Введите a: "; cin>>a;
    cout<<"Введите b: "; cin>>b;
    remove_key(lst,a,b);
    print_List(lst);
    dob(lst);
    print_List(lst);

    
    
    return 0;
}