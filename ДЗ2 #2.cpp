
#include <iostream>
using namespace std;


double* allocateMemory(int size) {// Функция для выделения памяти для массива
    return new double[size];
}

// Функция для заполнения массива данными
void fillArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Введите значение для ячейки " << i << ": ";
        cin >> arr[i];
    }
}

// Функция для вывода данных массива на экран
void displayArray(double* arr, int size) {
    cout << "Данные массива:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция для освобождения памяти, занимаемой массивом
void freeMemory(double* arr) {
    delete[] arr;
}

int main() {
    char choice;
    do {
        int size;
        cout << "Введите размер массива: ";
        cin >> size;

        // Выделение памяти для массива
        double* array = allocateMemory(size);

        // Заполнение массива данными
        fillArray(array, size);

        // Вывод данных на экран
        displayArray(array, size);

        // Освобождение памяти
        freeMemory(array);

        cout << "Хотите продолжить работу? (y/n)";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}