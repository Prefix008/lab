#include <list>
#include <iostream>
using namespace std;
list<double> make_list(int n){
    list<double> lst;
    for(int i=0;i<n;i++){
        cout<<"Элемент списка "<<i<<" : ";
        double h;
        cin>>h;
        lst.push_back(h);
    }
    return lst;
}
void print_list(list<double>& lst){
    for(auto x:lst){
        cout<<x<<endl;
    }
    cout<<endl;
}
void DobSrAr(list<double>& lst){
    double sum=0;
    int kol=lst.size();
    for(auto x:lst){
        sum+=x;
    }
    lst.push_back(sum/kol);
}
void remove_key(list<double>& lst,double a,double b){
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it >= a && *it <= b) {
            it = lst.erase(it);  
        } else {
            ++it;
        }
    }
}
void dob(list<double>& lst){
    int max=lst.front();
    int min=lst.front();
    for(auto x:lst){
        if(x>max){
            max=x;
        }
        if(x<min){
            min=x;
        }
    }
    int sum=max+min;
    for(auto it=lst.begin();it!=lst.end();++it){
        *it+=sum;
    }
}
int main(){
    int n;
    cout<<"Размер списка = ";
    cin>>n;
    list<double> lst;
    lst=make_list(n);
    print_list(lst);
    DobSrAr(lst);
    print_list(lst);
    double a,b;
    cout<<"Введите a: "; cin>>a;
    cout<<"Введите b: "; cin>>b;
    remove_key(lst,a,b);
    print_list(lst);
    dob(lst);
    print_list(lst);

    
    
    return 0;
}