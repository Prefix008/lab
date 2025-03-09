#include <iostream>

using namespace std;
void sort(int* a,int n){
    int maxi=a[0];
    int mini=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>maxi){
            maxi=a[i];
        }
        else if(a[i]<mini){
            mini=a[i];
        }
    }
    int raz=maxi-mini+1;
    int* b=new int[raz];
    for(int i=0;i<raz;i++) b[i]=0;
    for(int i=0;i<n;i++){
        b[a[i]-mini]++;
    }
    int k=0;
    for(int i=0;i<raz;i++){
        while (b[i]!=0){
            a[k++]=i+mini;
            b[i]--;
        }
    }
    delete[] b;

}
int main(){
    int n=10;
    int a[10]{-7,10,-3,-33,7,123,4,0,56,-3};
    sort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}