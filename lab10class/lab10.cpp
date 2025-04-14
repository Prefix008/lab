#include "pair.h"
#include "file_work.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string filename="C:/Users/Artem Loginov/Desktop/laboratorki/lab10class/F0.txt";
    int code;
    int k;
    ofstream fout(filename,ios::trunc);
do{
    cout << endl << "1. Создать файл" << endl;
    cout << "2. Вывод в консоль" << endl;
    cout << "3. Удаление меньше заданного" << endl;
    cout << "4. Прибавить целое число" << endl;
    cout << "5. Прибавить вещественное число" << endl;
    cout << "6. Добавить К элементов после заданного номера" << endl;
    cout << "0. Выход" << endl;
    cout << '>'; cin >> code; cin.ignore(1);

switch (code)
{
case 1:
    k = make_file(filename);
    if (k < 0) cout << "Невозможно создать файл\n";
    break;
case 2:
    k = print_file(filename);
    if (k < 0) cout << "Невозможно прочитать файл\n";
    if (k == 0) cout << "Файл пустой\n";
    break;
case 3:
    k = del_fewer(filename);
    if (k < 0) cout << "Невозможно прочитать файл\n";
    if (k== 0) cout << "Файл пустой\n";
    break;
case 4:
    k = add_int(filename);
    if (k < 0) cout << "Невозможно прочитать файл\n";
    if (k == 0) cout << "Файл пустой\n";
    break;
case 5:
    k= add_double(filename);
    if (k < 0) cout << "Невозможно прочитать файл\n";
    if (k == 0) cout << "Файл пустой\n";
    break;
case 6:
    k = add_file(filename);
    if (k < 0) cout << "Невозможно прочитать файл\n";
    if (k == 0) cout << "Файл пустой\n";
    break;
}
}
while(code!=0);

    return 0;
}