#include <iostream>
#include <string>
#include <exception>
#include "list.h"
using namespace std;
void my_unexpected(){
    cout<<"Вызвалось неожиданное исключение"<<endl;
    throw;
}
void my_terminate(){
    cout<<"Программа аварийно завершилась"<<endl;
    exit(1);
}
void V() {
    throw 3.14f;
}
int main() {
    set_unexpected(my_unexpected);
    set_terminate(my_terminate);
    try{
    int size;
    cout << "Введите количество элементов: ";
    cin>>size;
    if(size<=0) {
        V(); 
    }
    
    List list(size);
    cout << list << endl;
    cin>>list;

    int index;
    cout << "Введите индекс элемента: ";
    cin >> index;
    cout << "List[" << index << "] = " << list[index] << endl << endl;

    Iterator it = list.first();
    cout << "Введите индекс элемента для обращения через итератор: ";
    cin >> index;
    cout << "*(it + " << index << ") = " << *(it + index) << endl << endl;


    }
    catch (Error& e) {
        e.what();
    }
    catch (...) {
        cerr << "Неизвестная ошибка" << endl;
        my_unexpected();
    }

    return 0;
}