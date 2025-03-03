#include <iostream>
#include <string.h>
#include <stdio.h>
#include<cstring>
using namespace std;
struct Student{
    char f[50];
    char i[50];
    char o[50];
    char datr[50];
    char adress[50];
    int reit;
};
void sdvig(Student*& arr, int& n, int index)
{
    n--;
    int k=index;
    for(int i=index;i<n;i++){
        arr[k++]=arr[i+1];
    } 
}
int main(){
    int n;
    FILE* input=fopen("c:\\Users\\Artem Loginov\\Desktop\\laboratorki\\lab8\\10.txt","r");
    FILE* output=fopen("c:\\Users\\Artem Loginov\\Desktop\\laboratorki\\lab8\\11.txt","w");
    if(input==nullptr || output==nullptr){
        cout<<"как минимум одного файла нет по указаному пути"<<endl;
        return 1;
    }
    bool flag = true;
    fscanf(input,"%d",&n);
    fgetc(input); 
    char line[200];
    Student* students=new Student[n];
    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), input);
        sscanf(line, "%s %s %s %s %s %d", students[i].f, students[i].i, students[i].o, students[i].datr, students[i].adress, &students[i].reit);
    }
    for (int i = 0; i < n; i++) {
        cout << students[i].f << " " << students[i].i << " " << students[i].o << " " << students[i].datr << " " << students[i].adress << " " << students[i].reit <<endl;
    }
    for (int i=0;i<n-1;i++){
        flag=true;
        for (int j=i+1;j<n;j++){
        if (strcmp(students[i].datr,students[j].datr)==0)
        {
            flag=false;
            sdvig(students,n,j);
            j--;
        }
    }
    if(!flag){ sdvig(students,n,i);
    i--;}
    }
    cout<<endl;
    for (int i=0;i<n;i++){
        cout<<students[i].f<<" "<<students[i].i<<" "<<students[i].o<<" "<<students[i].datr<<" "<<students[i].adress<<" "<<students[i].reit<<endl;
    }
    cout<<"введите фамилию,перед которой хотите добавить человека"<<endl;
    char fam[50];
    cin>>fam;
    bool fl=true;
    for(int i=0;i<n&&fl;i++){
        if(strcmp(students[i].f,fam)==0){
            Student temp=students[i];
            for (int g=i;g<n;g++){
                Student temp1=students[g+1];
                students[g+1]=temp;
                temp=temp1;      
            }
            cout<<"введите данные человека"<<endl;
            cin>>students[i].f>>students[i].i>>students[i].o>>students[i].datr>>students[i].adress>>students[i].reit;
            fl=false;
            
        }
    }
     for (int i = 0; i < n+1; i++) {
        fprintf(output, "%s %s %s %s %s %d\n", students[i].f, students[i].i, students[i].o, students[i].datr, students[i].adress, students[i].reit);
    }
    delete[] students;
    fclose(input);
    fclose(output);
    return 0;
}
//5
//Ivanov Ivan Ivanovich 2000 Moscow 90
//Petrov Petr Petrovich 2001 Petersburg 85
//Ivanov Ivan Ivanovich 2000 Moscow 95
//Sidorov Sidor Sidorovich 2002 NewYork 80
//Ivanov Ivan Ivanovich 2000 Moscow 88 
//Sidorov
//Kuznetsov Kuzma Kuzmich 1999 Kyiv 75