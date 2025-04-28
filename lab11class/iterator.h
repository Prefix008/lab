#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    T data;
};

template <typename T>
class Iterator {
public:
    Node<T>* elem;
    Iterator(Node<T>* node = nullptr) : elem(node) {}
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
        elem = elem->next;
        return *this;
    }

    Iterator& operator--() {
        elem = elem->prev;
        return *this;
    }

    Iterator operator+(int a) const {
        Iterator temp = *this;
        for (int i = 0; i < a; ++i) {
            temp.elem = temp.elem->next;
        }
        return temp;
    }

    Iterator operator-(int a) const {
        Iterator temp = *this;
        for (int i = 0; i < a; ++i) {
            temp.elem = temp.elem->prev;
        }
        return temp;
    }

    T& operator*() const {
        return elem->data;
    }
};
