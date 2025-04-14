#pragma once
#include "pair.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int make_file(string filename){
    ofstream fout(filename);
    fout.seekp(0,ios::beg);
    if(!fout.is_open()) return -1;
    int n;
    cout<<"Введите количество пар: ";
    cin>>n;
    Pair p;
    for(int i=0;i<n;i++){
        cin>>p;
        fout<<p<<endl;
    }
    fout.close();
    fout.clear();
    return n;
}
int print_file(string filename) {
    ifstream fin(filename);
    fin.seekg(0,ios::beg);
    if (!fin.is_open()) {
        return -1;
    }
    Pair p;
    int count = 0;
    cout << "Содержимое файла " << filename << ":\n";
    while (fin >> p) {
        cout << p << endl;
        count++;
    }

    fin.close();
    fin.clear();
    return count;
}
int del_fewer(string filename) {
    fstream fin(filename);
    if (!fin.is_open()) {
        return -1;
    }
    fstream temp("C:/Users/Artem Loginov/Desktop/laboratorki/lab10class/temp.txt",ios::out|ios::in|ios::trunc);
    if (!temp.is_open()) {
        return -1;
    }
    fin.seekg(0,ios::beg);
    temp.seekp(0,ios::beg);
    int min_x;
    double min_y;
    cout << "Введите минимальное x: ";
    cin >> min_x;
    cout << "Введите минимальное y: ";
    cin >> min_y;

    Pair p;
    int count = 0;
    while (fin >> p) {
        if (p.getx() >= min_x && p.gety() >= min_y) {
            temp<< p << endl;
            count++;
        }
    }
    fin.close();
    fin.clear();
    temp.clear();
    fin.open(filename,ios::out|ios::in|ios::trunc);
    fin.seekp(0,ios::beg);
    temp.seekg(0,ios::beg);
    while (temp >> p) {
        fin<< p << endl;
    }
    
    fin.close();
    temp.close();
    fin.clear();
    temp.clear();


    return count;
}
int add_int(string filename) {
    fstream fin(filename);
    if (!fin.is_open()) {
        return -1;
    }
    fstream temp("C:/Users/Artem Loginov/Desktop/laboratorki/lab10class/temp.txt",ios::out|ios::in|ios::trunc);
    if (!temp.is_open()) {
        return -1;
    }
    fin.seekg(0,ios::beg);
    temp.seekp(0,ios::beg);

    int target_x, add_value;
    cout << "Введите искомое x: ";
    cin >> target_x;
    cout << "Введите прибавляемое число: ";
    cin >> add_value;

    Pair p;
    int count = 0;
    while (fin >> p) {
        if (p.getx() == target_x) {
            p.setx(p.getx() + add_value);
        }
        temp<< p << endl;
        count++;
    }
    fin.close();
    fin.clear();
    temp.clear();
    fin.open(filename,ios::out|ios::in|ios::trunc);
    fin.seekp(0,ios::beg);
    temp.seekg(0,ios::beg);
    while (temp >> p) {
        fin<< p << endl;
    }
    
    fin.close();
    temp.close();
    fin.clear();
    temp.clear();
   
    return count;
}
int add_double(string filename) {
    fstream fin(filename);
    if (!fin.is_open()) {
        return -1;
    }
    fstream temp("C:/Users/Artem Loginov/Desktop/laboratorki/lab10class/temp.txt",ios::out|ios::in|ios::trunc);
    if (!temp.is_open()) {
        return -1;
    }
    fin.seekg(0,ios::beg);
    temp.seekp(0,ios::beg);

    double target_y, add_value;
    cout << "Введите искомое y: ";
    cin >> target_y;
    cout << "Введите прибавляемое число: ";
    cin >> add_value;

    Pair p;
    int count = 0;
    while (fin >> p) {
        if (p.gety() == target_y) {
            p.sety(p.gety() + add_value);
        }
        temp<< p << endl;
        count++;
    }
    fin.close();
    fin.clear();
    temp.clear();
    fin.open(filename,ios::out|ios::in|ios::trunc);
    fin.seekp(0,ios::beg);
    temp.seekg(0,ios::beg);
    while (temp >> p) {
        fin<< p << endl;
    }
    
    fin.close();
    temp.close();
    fin.clear();
    temp.clear();
    
    return count;
}
int add_file(string filename) {
    fstream fin(filename);
    if (!fin.is_open()) {
        return -1;
    }

    fstream temp("C:/Users/Artem Loginov/Desktop/laboratorki/lab10class/temp.txt",ios::out|ios::in|ios::trunc);
    if (!temp.is_open()) {
        return -1;
    }

    int position, k;
    cout << "Введите номер, после которого нужно вставить: ";
    cin >> position;
    cout << "Введите количество добавляемых элементов: ";
    cin >> k;

    Pair p;
    int count = 0;
    while (fin >> p) {
        temp<< p << endl;
        count++;
        if (count == position) {
            for (int i = 0; i < k; i++) {
                cin >> p;
                temp<< p << endl;
                count++;
            }
        }
    }
    fin.close();
    fin.clear();
    temp.clear();
    fin.open(filename,ios::out|ios::in|ios::trunc);
    fin.seekp(0,ios::beg);
    temp.seekg(0,ios::beg);
    while (temp >> p) {
        fin<< p << endl;
    }
    
    fin.close();
    temp.close();
    fin.clear();
    temp.clear();

    return count;
}