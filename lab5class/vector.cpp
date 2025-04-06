#include "vector.h"
#include "object.h"
Vector::Vector(): beg(nullptr), size(0), cur(0) {};
Vector::Vector(int n):beg(new Object* [n]),size(n), cur(0){};
Vector::~Vector(){};
void Vector::add(Object* o){
    beg[cur]=o;
    cur++;
}
