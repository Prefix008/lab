#pragma once
#include "object.h"
#include <iostream>
using namespace std;
class Vector{
    Object** beg;
    int size;
    int cur;
    public:
    Vector();
    Vector(int);
    ~Vector();
    void add(Object*);
    friend ostream& operator<<(ostream&,const Vector&);
};