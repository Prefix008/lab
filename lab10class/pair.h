#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
class Pair{
    int x;
    double y;
    public:
    Pair();
    Pair(int xx,double yy);
    Pair(Pair&);
    ~Pair();
    int getx();
    double gety();
    void setx(int xx);
    void sety(int yy);
    Pair operator+(int) const;
    Pair operator+(double) const;
    Pair operator-(const Pair&) const;
    Pair& operator=(const Pair&);
    friend Pair operator+(int,const Pair&) ;
    friend Pair operator+(double y,const Pair&);
    friend istream& operator>>(istream&,Pair&);
    friend ostream& operator<<(ostream&,const Pair&);
    friend ifstream& operator>>(ifstream&,Pair&);
    friend ofstream& operator<<(ofstream&,const Pair&);
    friend fstream& operator>>(fstream&,Pair&);
    friend fstream& operator<<(fstream&,const Pair&);
};
Pair::Pair(){
    x=0;
    y=0;
}
Pair::Pair(int xx,double yy){
    x=xx;
    y=yy;
}
Pair::Pair(Pair& p){
    x=p.x;
    y=p.y;
}
Pair::~Pair(){

}
int Pair::getx(){
    return x;
}
double Pair::gety(){
    return y;
}
void Pair::setx(int xx){
    x=xx;
}
void Pair::sety(int yy){
    y=yy;
}
Pair Pair::operator+(double yy) const
{
    return Pair(x,y+yy);
}
Pair Pair::operator+(int xx) const
{
    return Pair(x+xx,y);
}
Pair Pair::operator-(const Pair& p) const
{
    return Pair(x-p.x,y-p.y);
}
Pair& Pair::operator=(const Pair& p){
    x=p.x;
    y=p.y;
    return *this;
}
Pair operator+(int a,const Pair& p){
    return p+a;
}
Pair operator+(double a,const Pair& p){
    return p+a;
}
istream& operator>>(istream& in,Pair& p){
    cout<<"x= ";
    in>>p.x;
    cout<<"y= ";
    in>>p.y;
    return in;
}
ostream& operator<<(ostream& out,const Pair& p){
    out<<'('<<p.x<<":"<<p.y<<")";
    return out;
}
ifstream& operator>>(ifstream& fin,Pair& p){
    fin>>p.x>>p.y;
    return fin;
}
ofstream& operator<<(ofstream& fout,const Pair& p){
    fout<<p.x<<" "<<p.y;
    return fout;
}
fstream& operator<<(fstream& fout,const Pair& p){
    fout<<p.x<<" "<<p.y;
    return fout;
}
fstream& operator>>(fstream& fin,Pair& p){
    fin>>p.x>>p.y;
    return fin;
}
