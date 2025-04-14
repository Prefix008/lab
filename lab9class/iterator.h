#pragma once
#include "error.h"
using namespace std;
struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    int data;
};
class Iterator {
    friend class List;
    Node* elem;
public:
    Iterator() {
        elem = nullptr;
    }
    
    Iterator(const Iterator& it) {
        elem = it.elem;
    }
    
    Iterator& operator=(const Iterator& a) {
        elem = a.elem;
        return *this;
    }
    
    bool operator==(const Iterator& it) const {
        return elem == it.elem;
    }
    
    bool operator!=(const Iterator& it) const {
        return elem != it.elem;
    }
    
    Iterator& operator++() {
        if(elem==nullptr) throw Error_Iterator();
        elem = elem->next;
        return *this;
    }
    
    Iterator& operator--() {
        if(elem==nullptr) throw Error_Iterator();
        elem = elem->prev;
        return *this;
    }
    
    
    Iterator operator+(int a) const {
        Iterator temp = *this;
        for (int i = 0; i < a; ++i) {
            if (temp.elem == nullptr) throw Error_Iterator();
            temp.elem = temp.elem->next;
        }
        return temp;
    }
    
    Iterator operator-(int a) const {
        Iterator temp = *this;
        for (int i = 0; i < a; ++i) {
            if (temp.elem == nullptr) throw Error_Iterator();
            temp.elem = temp.elem->prev;
        }
        return temp;
    }
    
    int& operator*() const {
        if (elem == nullptr) throw Error_Iterator();
        return elem->data;
    }
    
};