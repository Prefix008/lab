#include <iostream>
#include <math.h>
#include <vector>

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
    else minpr=sign(mini)*(1+log10(abs(mini)));
    if(maxi==0) maxpr=0;
    else maxpr=sign(maxi)*(1+log10(abs(maxi)));
    int raz=maxpr-minpr+1;
    vector <vector<int>> arr(raz);
    for(int i=0;i<n;i++){
        int dob;
        if (a[i] == 0) {
            dob = 0;
        } else {
            dob = sign(a[i]) * (1 + log10(abs(a[i]))) - minpr;
        }
        arr[dob].push_back(a[i]);
    }
    for (int i = 0; i < raz; i++) {
        if (!arr[i].empty()) {
            sort(arr[i].data(), arr[i].size());
        }
    }
    int k = 0;
    for (int i = 0; i < raz; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            a[k++] = arr[i][j];
        }
    }
    arr.clear();

}
int main(){
    int n=10;
    int a[10]{-7,10,-3,-3389,7,12379,4,353535,5533536,-3};
    sortblock(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}