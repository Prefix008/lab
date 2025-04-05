#include <iostream>
#include <sstream>
using namespace std;
class Pair{
    int x;
    double y;
    public:
    Pair();
    Pair(int xx,double yy);
    Pair(Pair&);
    ~Pair();
    void getx();
    void gety();
    void setx(int xx);
    void sety(int yy);
    Pair operator+(int) const;
    Pair operator+(double) const;
    Pair operator-(const Pair&) const;
    friend Pair operator+(int,const Pair&) ;
    friend Pair operator+(double y,const Pair&);
    friend ostream& operator<<(ostream&,const Pair&);
};