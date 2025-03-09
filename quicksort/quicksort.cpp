#include <iostream>

using namespace std;
void quicksort(int* a,int indexmain,int indexwall,int n){
    if(indexmain>indexwall){
    int copyw=indexwall;
    for(int i=indexwall;i<=indexmain;i++){
        if(a[i]<=a[indexmain]){
            int sw=a[i];
            a[i]=a[copyw];
            a[copyw]=sw;
            copyw++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quicksort(a,copyw-2,indexwall,n);
    quicksort(a,indexmain,copyw,n);
    }
}
int main(){
    int a[10]{1,-11,23,1783,0,10,-7,8 ,4,193};
    int n=10;
    int indm=n-1;
    int indw=0;
    quicksort(a,indm,indw,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}