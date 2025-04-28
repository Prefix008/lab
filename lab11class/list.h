#pragma once
#include <iostream>
#include "iterator.h"
using namespace std;
template <typename T>
class List {
private:
    int size;
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    List(int s=0,T k=T());
    List(const List<T>& a);
    ~List();
    T front();
    T back();
    void pushback(T data);
    void pushfront(T data);
    void popback();
    void popfront();
    bool empty();
    List<T>& operator=(const List<T>& a);
    T& operator[](int index);
    int& operator()();
    Iterator<T> first() { return Iterator<T>(head); }
    Iterator<T> last() { return Iterator<T>(nullptr); }
    Iterator<T> erase(Iterator<T> it){
        if (it.elem == nullptr) return it;
        Node<T>* temp=it.elem;
        Node<T>* temp1=temp->next;
        if (temp->prev) temp->prev->next=temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev=temp->prev;
        else tail = temp->prev;
        delete temp;
        size--;
        return temp1;
    }
    
    friend ostream& operator<<(ostream& out, const List<T>& a) {
        out << endl << "---Вывод элементов списка---" << endl;
        Node<T>* current = a.head;
        while (current != nullptr) {
            out << current->data << ' ';
            current = current->next;
        }
        out << endl << "---Вывод элементов списка завершён---" << endl;
        return out;
    }

    friend istream& operator>>(istream& in, List<T>& a) {
        cout << endl << "---Ввод элементов списка---" << endl;
        Node<T>* current = a.head;
        while (current != nullptr) {
            in >> current->data;
            current = current->next;
        }
        cout << "---Ввод элементов списка завершён---" << endl;
        return in;
    }
};
template <typename T>
List<T>::List(int s, T k) {
    size = s;
    if (size > 0) {
        Node<T>* node = new Node<T>;
        node->data = k;
        head = node;
        tail = node;
        for (int i = 1; i < size; ++i) {
            Node<T>* newNode = new Node<T>;
            newNode->data = k;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        tail->next = nullptr;
    }
}
template <typename T>
List<T>::List(const List<T>& a) {
    Node<T>* node = a.head;
    while (node != nullptr) {
        pushback(node->data);
        node = node->next;
    }
}

template <typename T>
List<T>::~List() {
    while (head != nullptr) {
        popfront();
    }
}

template <typename T>
void List<T>::pushfront(T data) {
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void List<T>::pushback(T data) {
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void List<T>::popback() {
    if (tail != nullptr) {
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
    }
}

template <typename T>
void List<T>::popfront() {
    if (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;

    }
}

template <typename T>
T List<T>::front() {
    if (head != nullptr) {
        return head->data;
    }
}

template <typename T>
T List<T>::back() {
    if (tail != nullptr) {
        return tail->data;
    }
}

template <typename T>
int& List<T>::operator()() {
    return size;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& a) {
    if (this != &a) {
        while (head != nullptr) {
            popfront();
        }
        Node<T>* current = a.head;
        while (current != nullptr) {
            pushback(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
T& List<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        exit(1);
    }
    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}