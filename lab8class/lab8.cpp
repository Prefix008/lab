
#include "dialog.h"
#include <iostream>
using namespace std;
int main(){
    cout << "Доступные команды:" << endl;
    cout << "  m - создать новую группу" << endl;
    cout << "  + - добавить элемент в группу" << endl;
    cout << "  - - удалить элемент из группы" << endl;
    cout << "  s - показать информацию о членах группы" << endl;
    cout << "  z - показать названия групп" << endl;
    cout << "  q - завершить работу программы" << endl;
    Dialog d;
    d.Execute();
    
    return 0;
}
