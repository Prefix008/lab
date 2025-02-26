#include <iostream>
using namespace std;
void removeEvenRows(int** matrix, int& rows, int cols) {
    int n=0;
    for (int i = 0; i < rows; i++) {
        if (i % 2 != 0) { 
            matrix[n++]=matrix[i];
        }
    }
    rows=n;
}
void removeElementsBetweenZeros(int*& array, int& size) {
    int n=1;
    int* newarray = new int[size];
    newarray[0]=array[0];
    for (int i = 1; i < size-1; ++i) {
        if(array[i-1]==array[i+1]&&array[i+1]==0){
        }
        else{
            newarray[n++]=array[i];
        }
    }
    newarray[n]=array[size-1];
    delete[] array;
    array=newarray;
    size=n+1;
}
void processArray(int** matrix, int& rows, int cols) {
    removeEvenRows(matrix, rows, cols);
}

void processArray(int*& array, int& size) {
    removeElementsBetweenZeros(array, size);
}
int main() {
    int rows = 4;
    int cols = 3;
    int** matrix = new int*[rows];
    int k=0;
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            k=k+1;
            matrix[i][j] = k;
        }
    }

    cout << "Исходный двумерный массив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    processArray(matrix, rows, cols);

    cout << "Двумерный массив после удаления четных строк:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int size = 10;
    int* array = new int[size] {1, 2, 0, 3, 4, 5, 0, 6, 0, 7};
    processArray(array, size);
    cout << "Одномерный массив после удаления элементов между нулями:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] array;
    return 0;
}
