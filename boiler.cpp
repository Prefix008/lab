#include <iostream>
#include <string>
#include <set>
using namespace std;
void tabl_smesh(string str,string podstr,int& n,int a[2][26]){
    bool flag;
    bool flag1=true;
    for(int i=podstr.length()-2;i>=0;i--){
        flag=true;
        if(podstr[i]==podstr[podstr.length()-1]){
            flag1=false;
        }
        for(int j=0;j<n&&flag;j++){
            if(static_cast<char>(a[0][j])==podstr[i]){
                flag=false;
                if(a[1][j]==0){
                    a[1][j]=podstr.length()-i-1;
                }
            }
        }
    }
    if(flag1){
        flag=true;
        for(int j=0;j<n&&flag;j++){
            if(static_cast<char>(a[0][j])==podstr[podstr.length()-1]){
                flag=false;
                a[1][j]=podstr.length();
            }
        }
    }

}
void podchet(string str,set<char>& f,int a[2][26],int& n,string podstr){
    f.clear();
    for(int i=0;i<podstr.length();i++){
        f.insert(podstr[i]);
    }
    int i=0;
    for (char ch : f) {
        a[0][i]=static_cast<int>(ch);
        a[1][i]=0;
        ++i;
    }
     n=i;
}
void search(string str,string podstr,int a[2][26],int n){
    int h=podstr.length()-1;
    bool flag=true;
    bool flag1;
    bool flag2;
    int copy;
    while(h<=str.length()-1&&flag){
        flag2=true;
        cout<<str<<endl;
        for(int l=0;l<h+1-podstr.length();l++){
            cout<<" ";
        }
        cout<<podstr<<endl;
        int copy=h;
        for(int j=podstr.length()-1;j>=0&&flag2;j--){
            if(str[copy]==podstr[j]){
                --copy;
                if(j==0){
                    flag=false;
                    cout<<"подстрока найдена"<<endl;
                }
            }
            else{
                flag1=true;
                for(int i=0;i<n&&flag1;i++){
                    if(static_cast<char>(a[0][i])==str[h]){
                        flag1=false;
                        h+=a[1][i];
                  
                    }
                }
                if (flag1){
                    h+=podstr.length();
                }
                flag2=false;
            }
            

        }
    }
}
int main(){
    string str="abbdkaabcd";
    string podstr="abc";
    set<char> f;
    int a[2][26];
    int n;
    podchet(str,f,a,n,podstr);
    for(int i=0;i<n;i++){
        cout<<static_cast<char>(a[0][i])<<" ";
    }
    cout<<endl;
    tabl_smesh(str,podstr,n,a);
    for(int i=0;i<n;i++){
        cout<<a[1][i]<<" ";
    }
    cout<<endl;
    search(str,podstr,a,n);
    return 0;
}
