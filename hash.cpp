#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string names[30] = {  
    "Артём", "Кирилл", "Степан", "Григорий", "Павел",  
    "Роман", "Фёдор", "Олег", "Вячеслав", "Константин",  
    "Станислав", "Юрий", "Валентин", "Глеб", "Захар",  
    "Игорь", "Леонид", "Платон", "Родион", "Святослав",  
    "Тимур", "Всеволод", "Ян", "Богдан", "Арсений",  
    "Марк", "Давид", "Герман", "Эдуард", "Семён"  
};  

string patronymic[30] = {  
    "Артёмович", "Богданович", "Валерьевич", "Геннадиевич", "Данилович",  
    "Егорович", "Жанович", "Захарович", "Ильич", "Константинович",  
    "Львович", "Маркович", "Натанович", "Олегович", "Петрович",  
    "Робертович", "Семёнович", "Тарасович", "Умарович", "Филиппович",  
    "Харитонович", "Цезаревич", "Чеславович", "Шамильевич", "Эльдарович",  
    "Юхимович", "Янович", "Ярославович", "Витальевич", "Денисович"  
};  

string surnames[30] = {  
    "Поляков", "Комаров", "Дмитриев", "Тихонов", "Филиппов",  
    "Жуков", "Савельев", "Романов", "Давыдов", "Белов",  
    "Гусев", "Титов", "Крылов", "Анисимов", "Мельников",  
    "Щербаков", "Блинов", "Кудрявцев", "Трофимов", "Лукин",  
    "Ермаков", "Горбунов", "Сысоев", "Ефимов", "Терентьев",  
    "Колесников", "Широков", "Фомин", "Дорофеев", "Назаров"  
};  

int ID[30] = {  
    17890123, 28901234, 39012345, 40123456, 51234567,  
    62345678, 73456789, 84567890, 95678901, 106789012,  
    117890123, 128901234, 139012345, 140123456, 151234567,  
    162345678, 173456789, 184567890, 195678901, 206789012,  
    217890123, 228901234, 239012345, 240123456, 251234567,  
    262345678, 273456789, 284567890, 295678901, 306789012  
};

string dates[30] = {  
    "12.08.1995", "23.09.1996", "05.10.1997", "17.11.1998", "28.12.1999",  
    "09.01.2000", "20.02.2001", "01.03.2002", "12.04.2003", "23.05.2004",  
    "04.06.2005", "15.07.2006", "26.08.2007", "07.09.2008", "18.10.2009",  
    "29.11.2010", "10.12.2011", "21.01.2012", "02.02.2013", "13.03.2014",  
    "24.04.2015", "05.05.2016", "16.06.2017", "27.07.2018", "08.08.2019",  
    "19.09.2020", "30.10.2021", "11.11.2022", "22.12.2023", "03.01.2024"  
};  
struct student{
    string f;
    string i;
    string o;
    string datar;
    int id=-1;
};
int summ(string str)
{
    return stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
}
void hash1(student*& a,int n,int& khash)
{
    for(int i=0;i<n;i++){
    double h = (sqrt(2) / 2) * summ(dates[i]);
    double drob = h - static_cast<int>(h);
    int b= static_cast<int>(n*drob);
    if((a[b].id)==-1){
        a[b].datar=dates[i];
        a[b].i=names[i];
        a[b].f=surnames[i];
        a[b].o=patronymic[i];
        a[b].id=ID[i];
    }
    else{
        int copyb=b;
       ++b;
       while((a[b].id)!=-1&&b<=n-1){
        ++khash;
        ++b;
       }
        if(b==n){
            b=0;
            while((a[b].id)!=-1&&b<=copyb-1){
            ++khash;
            ++b;
            }
        }
            a[b].datar=dates[i];
            a[b].i=names[i];
            a[b].f=surnames[i];
            a[b].o=patronymic[i];
            a[b].id=ID[i];
    }
    }
}
void hash2(student**& f,int n,int& khash,int*& d)
{
    for(int i=0;i<n;i++){
    double h = (sqrt(2) / 2) * summ(dates[i]);
    double drob = h - static_cast<int>(h);
    int b= static_cast<int>(n*drob);
    bool flag=true;
    for(int g=0;g<n&&flag;g++){
       if(f[b][g].id==-1){
        f[b][g].datar=dates[i];
        f[b][g].i=names[i];
        f[b][g].f=surnames[i];
        f[b][g].o=patronymic[i];
        f[b][g].id=ID[i];
        flag=false;
        ++d[b];
       } 
       else{
        ++khash;
       }
    }
    
    }
}
int main(){
    int n=30;
    int khash=0;
    student* a=new student[n];
    hash1(a,n,khash);
    for(int i=0;i<n;i++){
        cout<<i<<":"<<a[i].f<<" "<<a[i].i<<" "<<a[i].o<<" "<<a[i].datar<<" "<<a[i].id<<endl;
    }
    cout<<khash<<endl;
    delete[] a;
    khash=0;
    student** f=new student*[n];
    int* d=new int[n];
    for(int i=0;i<n;i++){
        d[i]=0;
        f[i]=new student[n];
    }
    hash2(f,n,khash,d);
    bool flag;
    for(int i=0;i<n;i++){
        flag=true;
        for(int j=0;j<d[i];j++){
            cout<<i<<":"<<f[i][j].f<<" "<<f[i][j].i<<" "<<f[i][j].o<<" "<<f[i][j].datar<<" "<<f[i][j].id<<" ";
            flag=false;
        }
        if(flag){
            cout<<i<<": нет элементов";
        }
        cout<<endl;
    }
    cout<<khash<<endl;
    for(int i=0;i<n;i++){
        delete[] f[i];
    }
    delete[]f;
    delete[] d;
    return 0;
}
