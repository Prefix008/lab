#include <iostream>
#include <fstream>
using namespace std;

void merge(fstream& input, int n,int first,int mid,int last) {
    input.clear();
    input.seekg(0, ios::beg); 
    string firstLine;
    getline(input, firstLine);
    fstream F1("C:\\Users\\Artem Loginov\\Desktop\\laboratorki\\sort2\\estestv\\F1.txt",ios::trunc| ios::in | ios::out);
    fstream F2("C:\\Users\\Artem Loginov\\Desktop\\laboratorki\\sort2\\estestv\\F2.txt",ios::trunc| ios::in | ios::out);
    int a1, a2;
    int i=0;
    bool fl=false;
    while(i<first){
        fl=true;
        input>>a1;
        i++;
        }
    int tell=input.tellg();
    cout<<"F1:";
    for(int i=first;i<=mid;i++){
        input>>a1;
        F1<<a1<<" ";
        cout<<a1<<" ";
    }
    cout<<endl;
    cout<<"F2:";
    for(int i=mid+1;i<=last;i++){
        input>>a1;
        F2<<a1<<" ";
        cout<<a1<<" ";
    }
    cout<<endl;
    F1.seekg(0, ios::beg);
    F2.seekg(0, ios::beg);
    input.seekg(0, ios::beg);
    getline(input, firstLine);
    if(fl) input.seekp(tell+1);
    else input.seekp(tell);
    bool hasA1 = static_cast<bool>(F1 >> a1);
    bool hasA2 = static_cast<bool>(F2 >> a2);
    bool isFirst = true;
    while (hasA1 && hasA2) {
        if (!isFirst) {
            input << " ";
        }
        if (a1 <= a2) {
            input << a1;
            hasA1 = static_cast<bool>(F1 >> a1);
        } else {
            input << a2 ; 
            hasA2 = static_cast<bool>(F2 >> a2); 
        }
        isFirst = false;
    }
    while (hasA1) {
        if (!isFirst) {
            input << " ";
        }
        input << a1;
        hasA1 = static_cast<bool>(F1 >> a1);
        isFirst = false;
    }
    while (hasA2) {
        if (!isFirst) {
            input << " ";
        }
        input << a2;
        hasA2 = static_cast<bool>(F2 >> a2);
        isFirst = false;
    }
    F1.close();
    F2.close();
    
}
void slian(fstream& input,int n,int first,int last){
    input.clear();
    input.seekg(0, ios::beg); 
    string firstLine;
    getline(input, firstLine);
    if (last-first>=1){
    int mid=(last+first)/2;
    cout<<"делим массив на часть с "<<first<<" индекса до "<<mid<<endl;
    int i=0;
    int a1=0;
    while(i<first){
        input>>a1;
        i++;
        }
    for(int i=first;i<=mid;i++){
        input>>a1;
        cout<<a1<<" ";
    }
    cout<<endl;
    slian(input,n,first,mid);
    input.clear();
    input.seekg(0, ios::beg); 
    getline(input, firstLine);
    cout<<"делим массив на часть с "<<mid+1<<" индекса до "<<last<<endl;
    i=0;
    while(i<mid+1){
        input>>a1;
        i++;
        }
    for(int i=mid+1;i<=last;i++){
        input>>a1;
        cout<<a1<<" ";
    }
    cout<<endl;
    slian(input,n,mid+1,last);
    merge(input,n,first, mid, last);
    input.clear();
    input.seekg(0, ios::beg); 
    getline(input, firstLine);
    cout<<"массив отсортировкался с "<<first<<" индекса до "<<last<<endl;
    i=0;
    while(i<first){
        input>>a1;
        i++;
        }
    for(int i=first;i<=last;i++){
        input>>a1;
        cout<<a1<<" ";
    }
    cout<<endl;
    }
}
int main(){
    fstream input("C:\\Users\\Artem Loginov\\Desktop\\laboratorki\\sort2\\estestv\\F0.txt",ios::in | ios::out);
    int n;
    input>>n;
    slian(input,n,0,n-1);
    input.close();
    return 0;
}
//11
//-3849 382 484 728 729 727 844 37 47438 45 10