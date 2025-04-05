#include <iostream>
#include "pair.h"
using namespace std;
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
void Pair::getx(){
    cout<<"x = "<<x<<endl;
}
void Pair::gety(){
    cout<<"y = "<<y<<endl;
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