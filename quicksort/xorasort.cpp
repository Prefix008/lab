#include <iostream>

using namespace std;
void quicksort(int* a,int indexwall,int indexwall1,int n){
    if(indexwall1-indexwall>=1){
    int copyw=indexwall;
    int copyw1=indexwall1;
    int mid=a[(indexwall1+indexwall)/2];
    while(copyw1>=copyw){
        while(a[copyw]<mid){
            copyw++;
        }
        while(a[copyw1]>mid){
            copyw1--;
        }
        if(copyw1>=copyw){
        int sw=a[copyw];
        a[copyw]=a[copyw1];
        a[copyw1]=sw;
        copyw++;
        copyw1--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quicksort(a,indexwall,copyw1,n);
    quicksort(a,copyw,indexwall1,n);
    }
}
int main(){
    int a[10]{1,-11,23,1783,0,10,-7,8 ,4,193};
    int n=10;
    quicksort(a,0,9,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}