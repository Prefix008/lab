#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
using namespace std;
template <typename Type>
double dlina(Type x1,Type y1,Type x2,Type y2){
    double x3 = pow(abs(x2-x1),2);
    double y3 = pow(abs(y2-y1),2);
    return pow(x3+y3,0.5);
}
template <typename Type1>
double square(Type1 x1,Type1 y1,Type1 x2,Type1 y2,Type1 x3,Type1 y3){
    double a = dlina(x1,y1,x2,y2);
    double b = dlina(x2,y2,x3,y3);
    double c = dlina(x3,y3,x1,y1);
    double pol=(a+b+c)/2;
    return pow(pol*(pol-a)*(pol-b)*(pol-c),0.5);

}
double square1(int k,...){
    int* a=new int[k*2];
    double maxi=-1;
    double sq=0;
    va_list b;
    va_start(b,k);
    
    for(int i=0;i<k*2;i++){
        a[i]=va_arg(b,int);
       
    }
    int i=0;
    while (i+5<k*2){
        if(dlina(a[i],a[i+1],a[i+4],a[i+5])>maxi){
            maxi=dlina(a[i],a[i+1],a[i+4],a[i+5]);
            sq=square(a[i],a[i+1],a[i+4],a[i+5],a[i+2],a[i+3]);
        }
        i=i+2;
    }
    if(dlina(a[0],a[1],a[k*2-4],a[k*2-3])>maxi){
            maxi=dlina(a[0],a[1],a[k*2-4],a[k*2-3]);
            sq=square(a[0],a[1],a[k*2-4],a[k*2-3],a[k*2-2],a[k*2-1]);
        }
    if(dlina(a[2],a[3],a[k*2-2],a[k*2-1])>maxi){
            maxi=dlina(a[2],a[3],a[k*2-2],a[k*2-1]);
            sq=square(a[2],a[3],a[0],a[1],a[k*2-2],a[k*2-1]);
        }
    va_end(b);
    return sq;
}

int main(){
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<square(x1,y1,x2,y2,x3,y3);//например, 0 3 2 3 1 6;10 7 5 2 1.5 6 =(18.75)
    cout<<endl<<square1(5,0,0,4,0,4,3,2,5,0,3);//координаты заданы по часовой стрелке или против


    
    return 0;
    
}
