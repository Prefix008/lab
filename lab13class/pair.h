#include <iostream>
#include <sstream>
using namespace std;
class Pair{
    int x;
    double y;
    public:
    Pair();
    Pair(int xx,double yy);
    Pair(const Pair&);
    ~Pair();
    int getx();
    double gety();
    void setx(int xx);
    void sety(double yy);
    Pair operator+(const Pair&) const;
    Pair operator-(const Pair&) const;
    Pair operator/(const Pair&) const;
    Pair operator*(const Pair&) const;
    bool operator<(const Pair&) const;
    bool operator>(const Pair&) const;
     bool operator>=(const Pair& p) const;
    bool operator<=(const Pair& p) const;
    Pair& operator=(const Pair&);
    friend ostream& operator<<(ostream&,const Pair&);
    friend istream& operator>>(istream&,Pair&);
};
Pair::Pair(){
    x=0;
    y=0;
}
Pair::Pair(int xx,double yy){
    x=xx;
    y=yy;
}
Pair::Pair(const Pair& p){
    x=p.x;
    y=p.y;
}
Pair::~Pair(){

}
Pair& Pair::operator=(const Pair& p){
    x=p.x;
    y=p.y;
    return *this;
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
void Pair::sety(double yy){
    y=yy;
}
Pair Pair::operator+(const Pair& p) const
{
    return Pair(x+p.x,y+p.y);
}
Pair Pair::operator-(const Pair& p) const
{
    return Pair(x-p.x,y-p.y);
}
Pair Pair::operator*(const Pair& p) const
{
    return Pair(x*p.x,y*p.y);
}
Pair Pair::operator/(const Pair& p) const
{
    return Pair(x/p.x,y/p.y);
}
istream& operator>>(istream& fin,Pair& p){
    cout<<"x= ";
    fin>>p.x;
    cout<<"y= ";
    fin>>p.y;
    return fin;
}
ostream& operator<<(ostream& out,const Pair& p){
    out<<'('<<p.x<<":"<<p.y<<")";
    return out;
}
bool Pair::operator>=(const Pair& p) const {
    return (x > p.x) || (x==p.x)&& (y >= p.y);
}

bool Pair::operator<=(const Pair& p) const {
    return (x < p.x) || (x==p.x)&& (y <= p.y);
}
bool Pair::operator<(const Pair& p) const{
    return (x < p.x) || (x==p.x)&& (y < p.y);
}
bool Pair::operator>(const Pair& p) const{
    return (x > p.x) || (x==p.x)&& (y > p.y);
}