#include <iostream>
using namespace std;


void shell(int* a,int n,int step){
    if(step>=1){
    for(int i=0;i+step<=n-step;i++){
        for(int j=i;j>=0 && a[j]>a[j+step];j=j-step){
            int sw=a[j];
            a[j]=a[j+step];
            a[j+step]=sw;
        }
    }
    step/=2;
    shell(a,n,step);
    }

}
int main(){
    int a[10]{15,-17,18,8,-14,-10,16,12,-6,-9};
    shell(a,10,10/2);
    for(int i=0;i<10;i++) cout<<a[i]<<" ";
    
    return 0;
}