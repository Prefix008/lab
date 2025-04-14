#pragma once
#include <string>
#include <iostream>
using namespace std;
class Error{
    protected:
    string message;
    public:
    Error(){message="Error";}
    void what(){cout<<message<<endl;}
};
class Error_Index_Min : public Error {
public:
    Error_Index_Min() { 
        message = "Error: индекс отрицательный"; 
    }
};

class Error_Index_Max : public Error {
public:
    Error_Index_Max() { 
        message = "Error: индекс больше макисмально возможного"; 
    }
};

class Error_Empty_List : public Error {
public:
    Error_Empty_List() { 
        message = "Error: список пуст"; 
    }
};

class Error_Iterator : public Error {
public:
    Error_Iterator() { 
        message = "Error: проблема с итератором"; 
    }
};

class Error_Size : public Error {
public:
    Error_Size() { 
        message = "Error: длина не может быть меньше 1"; 
    }
};