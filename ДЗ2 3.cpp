#include <iostream>

void swapValues(int* arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

int main() {
    int* arr = new int[12]; // выделение памяти для массива из 12 элементов
    // инициализация массива, например, значениями от 1 до 12
    for (int i = 0; i < 12; i++) {
        arr[i] = i + 1;
    }

    swapValues(arr, 12); // вызов функции для обмена значений четных и нечетных ячеек

    // вывод измененного массива на экран
    for (int i = 0; i < 12; i++) {
        std::cout << arr[i] << " ";
    }

    delete[] arr; // освобождение выделенной памяти

    return 0;
}