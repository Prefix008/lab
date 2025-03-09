#include <iostream>
#include <math.h>
using namespace std;
int sign(int a){
    if (a>0) return 1;
    else return -1;
}
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
void newdinam(int*& b,int dob,int k){
    int* f=new int[k+1];
    f[k]=dob;
    for(int i=0;i<k;i++) f[i]=b[i];
    delete[] b;
    b=f;
}
void sortblock(int* a,int n){
    int maxi=a[0];
    int mini=a[0];
    int minpr,maxpr;
    for(int i=0;i<n;i++){
        if(a[i]>maxi){
            maxi=a[i];
        }
        else if(a[i]<mini){
            mini=a[i];
        }
    }
    if(mini==0) minpr=0;
    else minpr=sign(mini)*(1+static_cast<int>(log10(abs(mini))));
    if(maxi==0) maxpr=0;
    else maxpr=sign(maxi)*(1+static_cast<int>(log10(abs(maxi))));
    int raz=maxpr-minpr+1;
    int** b=new int* [raz];
    int* h=new int[raz];
    for(int i=0;i<raz;i++) {
        b[i]=new int[0];
        h[i]=0;
    }
    for(int i=0;i<n;i++){
        int dob;
        if (a[i] == 0) {
            dob = 0-minpr;
        } else {
            dob = sign(a[i]) * (1 + static_cast<int>(log10(abs(a[i])))) - minpr;
        }
        newdinam(b[dob],a[i],h[dob]);
        h[dob]++;
    }
    for(int i=0;i<raz;i++) {
        sort(b[i],h[i]);
        cout<<i+minpr<<":"<<endl;
        for(int j=0;j<h[i];j++){
            
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    } 
    int g = 0;
    for (int i = 0; i < raz; i++) {
        for (int j = 0; j < h[i]; j++) {

            a[g++] = b[i][j];
        }
        delete[] b[i];
    }
    delete[] b;
    

}
int main(){
    int n=10;
    int a[10]{-7,10,-3,-3389,7,12379,4,353535,0,-3};
    sortblock(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    
    return 0;
}