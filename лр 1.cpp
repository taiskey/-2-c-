#include <iostream>

/*QuickSort*/
template <typename T>
void QuickSort(T *arr, int size) { 
    
    int begin = 0; 
    int end = size - 1; 
    
    int indexPivot = rand() % (end - begin + 1) + begin; 
    T pivot = arr[indexPivot]; 
    
    do { 

        while (arr[begin] < pivot) { 
            begin++;
        }
        while (arr[end] > pivot) { 
            end--;
        }
        if (begin <= end) { 
            std::swap(arr[begin], arr[end]); 
            begin++;
            end--;
        }

    } while (begin <= end); 


    //QuickSort 
    if (end > 0) { 
        QuickSort(arr, end + 1);
    }
    if (begin < size) { 
        QuickSort(&arr[begin], size - begin);
    }
}

/*BubbleSort*/

template <typename T>
void BubbleSort(T *arr, int size) { 
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { 
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}


/*InsertionSort*/
template <typename T>
void InsertionSort(T *arr, int size) { 
    for (int i = 1; i < size; i++) { 
        T key = arr[i]; 
        int j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        }
        arr[j + 1] = key; 
    }
}

int main() 
{
    /*QuickSort*/
    int IntArray[] = {52, 93, 9, 48, 5, 78, 43, 8};
    int SizeOfIntArray = sizeof(IntArray) / sizeof(IntArray[0]);
    std::cout << "Start array: ";
    for (int i = 0; i < SizeOfIntArray; i++) {
        std::cout << IntArray[i] << " ";
    }
    std::cout << std::endl;
    QuickSort(IntArray, SizeOfIntArray);
    std::cout << "Final array: ";
    for (int i = 0; i < SizeOfIntArray; i++) {
        std::cout << IntArray[i] << " ";
    }
    std::cout << std::endl;

    /*InsertionSort*/
    double DoubleArray[] = { 52.3, 93.7, 9.3, 48.3, 523.4, 78.3, 43.0, 8.4 };
    int SizeOfDoubleArray = sizeof(DoubleArray) / sizeof(DoubleArray[0]);
    std::cout << "Start array: ";
    for (int i = 0; i < SizeOfDoubleArray; i++) {
        std::cout << DoubleArray[i] << " ";
    }
    std::cout << std::endl;
    InsertionSort(DoubleArray, SizeOfDoubleArray);
    std::cout << "Final array: ";
    for (int i = 0; i < SizeOfDoubleArray; i++) {
        std::cout << DoubleArray[i] << " ";
    }
    std::cout << std::endl;

    /*BubbleSort*/
    char CharArray[] = { 'C', 'a', 'A', 'c', 'b', 'f', 'F', 'a' };
    int SizeOfCharArray = sizeof(CharArray) / sizeof(CharArray[0]);
    std::cout << "Start array: ";
    for (int i = 0; i < SizeOfCharArray; i++) {
        std::cout << CharArray[i] << " ";
    }
    std::cout << std::endl;
    BubbleSort(CharArray, SizeOfCharArray);
    std::cout << "Final array: ";
    for (int i = 0; i < SizeOfCharArray; i++) {
        std::cout << CharArray[i] << " ";
    }

    return 0;
}