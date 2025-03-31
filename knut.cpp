#include <iostream>
#include <string>
using namespace std;
void prefix(int a[2][26],string podstr){
    for(int i=0;i<podstr.length();i++){
        a[1][i]=0;
    }
    for (int i = 1; i < podstr.length(); i++) {
        int j = a[1][i - 1];
        while (j > 0 && podstr[i] != podstr[j]) {
            j = a[1][j - 1];
        }
        if (podstr[i] == podstr[j]) {
            j++;
        }
        a[1][i] = j;
    }
}
void searchWithPrefix(const string str, const string podstr, int a[2][26]) {
    int n = str.length();
    int m = podstr.length();
    int j = 0;
    for (int i = 0; i < n; i++) {
        cout<<str<<endl;
        for(int k=0;k<i-j;k++) cout<<" ";
        cout<<podstr<<endl;
        while (j > 0 && str[i] != podstr[j]) {
            j =a[1][j - 1];
            cout << str << endl;
            for(int k = 0; k < i - j; k++) cout << " ";
            cout << podstr << endl;
        }
        if (str[i] == podstr[j]) {
            j++; 
        }
        
        if (j == m) {
            cout << "Подстрока найдена на позиции: " << i - m + 1 << endl;
            j = a[1][j - 1];
        }
    }
}

int main(){
    string str="abcabceabcabcd";
    string podstr="abcabcd";
    int a[2][26];
    for(int i=0;i<podstr.length();i++){
        a[0][i]=podstr[i];
    }
    prefix(a,podstr);
    searchWithPrefix(str, podstr, a);
    return 0;
}
