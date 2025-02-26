#include <iostream>
#include <string.h>
#include <math.h>
#include <windows.h>

using namespace std;
double f(int y){
    return pow(y,0.3333);
}
int main(){
    
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string str;
    getline(cin,str);
    double cop,b;
    int d=str.length()-1;
    int kof=20;
    if(str.length()%2==0){
        b=str.length()/2-0.5;  
    } 
    else{
        b=static_cast<int>(str.length()/2);
    }
    cop=b;
    while (b>=0){
        for (int j=0;j<20;j++){
            cout<<" ";
        }
        
        for (int j=0;j<static_cast<int>(f(b*kof));j++){
            cout<<" ";
        }
        cout<<str[d];
        d--;
        b--;
        cout<<endl;
    }
    while(b>=-cop){
        for (int j=0;j<20-static_cast<int>(f(-b*kof));j++){
            cout<<" ";
        }
        cout<<str[d];
        d--;
        b--;
        cout<<endl;
    }
    return 0;
    
}