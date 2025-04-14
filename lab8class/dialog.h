#pragma once
#include "vector.h"
#include <iostream>
using namespace std;
const int evNothing = 0;    // Нет события
const int evMessage = 100;  // Есть событие
const int cmAdd = 1;        // Добавить объект
const int cmDel = 2;        // Удалить объект
const int cmGet = 3;        // Вывести названия групп (z)
const int cmShow = 4;       // Вывести всю группу (s)
const int cmMake = 6;       // Создать группу (m)
const int cmQuit = 101;     // Выход (q)

struct Event {
    int what;      
    int command;   
};

class Dialog : public Vector {
    int state; 
public:
    Dialog():state(0){}
    ~Dialog(){}              
    void GetEvent(Event& e){
    string op = "m+-szq";
    char code;
    cout << ">";
    cin >> code;
    if (op.find(code) != string::npos) {
        e.what = evMessage;
        switch (code) {
            case 'm': e.command = cmMake; break;
            case '+': e.command = cmAdd; break;
            case '-': e.command = cmDel; break;
            case 's': e.command = cmShow; break;
            case 'z': e.command = cmGet; break;
            case 'q': e.command = cmQuit; break;
        }
    } else {
        e.what = evNothing;
    }
    }
    int Execute(){
         Event e;
    do {
        state = 0;
        GetEvent(e);
        Handle(e);
    } while (!IsValid());
    return state;
    }            
    void Handle(Event& e){
    if (e.what == evMessage) {
        switch (e.command) {
            case cmMake:
                cout << "Enter size: ";
                cin >> size;
                beg = new object*[size];
                cur = 0;
                Clear(e);
                break;
            case cmAdd:
                add();
                Clear(e);
                break;
            case cmDel:
                del();
                Clear(e);
                break;
            case cmShow:
                show();
                Clear(e);
                break;
            case cmQuit:
                End();
                Clear(e);
                break;
            default:
                get();
        }
    }
    }  
    void Clear(Event& e){
        e.what=evNothing;
    }    
    int IsValid(){
        return state!=0;
    }            
    void End(){
        state=1;
    }            

};



