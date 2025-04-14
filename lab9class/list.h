#pragma once
#include <iostream>
#include "iterator.h"
#include "error.h"
using namespace std;
class List {
private:
    int size=0;
    Node* head = nullptr;
    Node* tail = nullptr;
    Iterator beg;
    Iterator end;
public:
    List(int s);
    List(const List& a);
    ~List();
    void pushback(int data);
    void pushfront(int data);
    void popback();
    void popfront();
    bool empty();
    List& operator=(const List& a);
    int& operator[](int index);
    int& operator()();
    List operator*(List& a);

    friend ostream& operator<<(ostream& out, const List& a);
    friend istream& operator>>(istream& in, List& a);
    Iterator first(){
        return beg;
    }
    Iterator last(){
        return end;
    }
};

List::List(int s) {
    if (s<1) throw Error_Size();
    size = s;
    Node* node = new Node;
    node->data = 0;
    head = node;
    tail = node;
    for (int i = 1; i <= size - 1; ++i) {
        Node* node = new Node;
        node->data = i;
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    tail->next = nullptr;
    beg.elem=head;
    end.elem=nullptr;
}

List::List(const List& a) {
    Node* node = a.head;
    while (node != nullptr) {
        pushback(node->data);
        node = node->next;
    }
    beg=a.beg;
    end=a.end;
}

List::~List() {
    Node* currentNode = head;
    while (currentNode != nullptr) {
        head = currentNode->next;
        delete currentNode;
        currentNode = head;
    }
}

void List::pushback(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        ++size;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        ++size;
    }
}

void List::pushfront(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        ++size;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        ++size;
    }
    beg.elem=head;
}

void List::popback() {
    if (head == nullptr) {
        throw Error_Empty_List();
    }
    
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* currentNode = tail;
        tail = currentNode->prev;
        tail->next = nullptr;
        delete currentNode;
    }
    --size;
}

void List::popfront() {
    if (head == nullptr) {
        throw Error_Empty_List();
    }
    
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
        Node* currentNode = head;
        head = currentNode->next;
        delete currentNode;
        head->prev = nullptr;
        
    }
    beg.elem=head;
    --size;
}

bool List::empty() {
    return size == 0;
}

int& List::operator()() {
    return size;
}

List& List::operator=(const List& a) {
    cout << "Оператор присваивания вызван" << endl;
    if (this == &a) {
        return *this;
    }
    Node* node = head;
    while (node != nullptr) {
        head = node->next;
        delete node;
        node = head;
        --size;
    }
    Node* currentNode = a.head;
    while (currentNode != nullptr) {
        pushback(currentNode->data);
        currentNode = currentNode->next;
    }
    beg=a.beg;
    end=a.end;
    return *this;
}

int& List::operator[](int index) {
    if (index < size && index >= 0) {
        Node* current = head;
        for (int i = 0; i != index; ++i) {
            current = current->next;
        }
        return current->data;
    } else {
        if (index >= size) {
            throw Error_Index_Max();
        } else {
            throw Error_Index_Min();
        }
    }
}

List List::operator*(List& a) {
    int size_temp = ((size > a.size) ? a.size : size);
    List temp(size_temp);
    for (int i = 0; i < size_temp; ++i) {
        temp[i] = (*this)[i] * a[i];
    }
    return temp;
}

ostream& operator<<(ostream& out, const List& a) {
    out << endl << "-------Вывод элементов списка-------" << endl;
    Node* current = a.head;
    while (current != nullptr) {
        out << current->data << ' ';
        current = current->next;
    }
    out << endl << "-------Вывод элементов списка завершён-------" << endl;
    return out;
}

istream& operator>>(istream& in, List& a) {
    cout << endl << "---Ввод элементов списка---" << endl;
    Node* current = a.head;
    while (current != nullptr) {
        in >> current->data;
        current = current->next;
    }
    cout << "---Ввод элементов списка завершён---" << endl;
    return in;
}


