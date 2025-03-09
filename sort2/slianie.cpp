#include <iostream>
using namespace std;


void merge(int* a,int first,int mid,int last){
    int b[6];
    int ind1=first;
    int ind2=mid+1;
    int k=first;
    while(ind1<=mid && ind2<=last){
        if(a[ind1]<a[ind2]){
            b[k++]=a[ind1];
            ind1++;
        }
        else{
            b[k++]=a[ind2];
            ind2++;
        }
    }
    while(ind2<=last){
        b[k++]=a[ind2];
        ind2++;
    }
    while (ind1<=mid){
        b[k++]=a[ind1];
        ind1++;
    }
    for (int i = first; i <= last; i++) {
        a[i] = b[i];
    }
}
void slian(int* a,int first,int last){
    if (last-first>=1){
    int mid=(last+first)/2;

    slian(a,first,mid);
    slian(a,mid+1,last);
    merge(a, first, mid, last);
    }
}
int main(){
    int a[6]{-7,10,-3,-3389,7,12379};
    int b[6];
    slian(a,0,5);
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    return 0;
}