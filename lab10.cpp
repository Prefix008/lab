#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>

using namespace std;

int main(){

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n,k;
    string str;
    srand(time(NULL));
    cout<<"Ввведите количество строк в массиве: ";
    cin>>n;
    char** a=new char*[n];
    for (int i=0;i<n;i++){
        a[i]=new char[10];
        for(int j=0;j<9;j++){
            a[i][j]=char (65+rand()%26);
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<"Ввведите индекс,куда вы хотите поставить новую строку: ";
    cin>>k;
    cout<<"Ввведите строку(до 9 символов): ";
    cin>>str;
    n++;
    char** d=new char*[n];
    for (int i=0;i<k;i++){
        d[i]=a[i];
    }
    d[k]=new char[str.length()+1];//для \0
    for(int j=0;j<str.length();j++){
        d[k][j]=str[j];

    }

    for(int i=k+1;i<n;i++){
        d[i]=a[i-1];
    }
    int m;
    for(int i=0;i<n;i++){
        
        if(i==k){
            m=str.length();
        }
        else{
            m=9;
        }
        for(int j=0;j<m;j++){
            
            cout<<d[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        delete[] a[i];
        delete[] d[i];
    }
    delete[] d[n];
        
    

    
    
    return 0;
    
}