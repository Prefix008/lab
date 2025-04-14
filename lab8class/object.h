#pragma once
#include <string>
using namespace std;
class object{
    public:
    virtual void show()=0;
    virtual void input()=0;
    virtual ~object(){}
    virtual string get_name()=0;
};