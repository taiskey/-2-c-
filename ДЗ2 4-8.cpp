#include <iostream>
#include <vector>

/*Task 4*/
void FilltheArray(int **array, int rows, int columns) { // Функция для заполнения массива
    for (int i = 0; i < rows; i++) { //перебором по строкам и столбцам, помешаем число на каждое место в массиве
        for (int j = 0; j < columns; j++) {
            // генерируем случайные числа 
            array[i][j] = rand() % 41 + 10;  
        }
    }
}
void ShowArray(int **array, int rows, int columns) { // функция для заполнения массива
    for (int i = 0; i < rows; i++) { //перебором по строкам и столбцам, выводим каждый элемент
        for (int j = 0; j < columns; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl; //после прохода по одной строке, делаем перенос на новую, для вывода ввиде двумерного массива
    }
}

/*Task 5*/
int summa(int a, int b) {  // Функция сложения
    return a + b; // возвращает сумму двух целых чисел
}

int subtract(int a, int b) { // Функция вычитания
    return a - b; // возвращает разность двух целых чисел
}

int multiply(int a, int b) { // Функция умножения
    return a * b; // возвращает произведение двух целых чисел
}

int divide(int a, int b) { // Функция деления
    return a / b; // возвращает частное двух целых чисел
}

/*Task 6*/
void BubbleSort(int *array, int length) { //функция сортировки bubble 
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (*(array + j) > *(array + j + 1)) {
                int temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}
int TheMinDifference(int *nums, int k) { // минимальная разница
    int max = 0;  //задаем переменные для минимального и максимального числа из k
    int min = 1000000;
    for (int count = 0; count < k; count++) { //перебором сравниваем k первых элементов
        if (nums[count] < min) 
            min = nums[count];
        else if (nums[count] > max) 
            max = nums[count];
    }
    return (max - min); //возвращаем разницу
}

/*Task 7*/
int findLucky(std::vector<int>& arr) { //  поиск счастливого числа
    std::vector<int> frequency(arr.size() + 1, 0); 


    //  Проходим по элементам массива и увеличиваем соответствующий счетчик
    for (int num : arr) {
        if (num >= 1 && num <= arr.size()) { // Проверяем, что число входит в нужный диапазон
            frequency[num]++; // Увеличиваем счетчик 
        }
    }


    for (int i = arr.size(); i >= 1; i--) {  // Проходим по счетчикам, начиная с конца
        if (frequency[i] == i) { // Если счетчик равен его индексу, то это счастливое число
            return i; // Возвращаем счастливое число
        }
    }

    return -1; // Если нет счастливого числа, возвращаем -1
}


/*Task 8*/
int TheMajorityElement(int *array, int length) { //функция для нахождения элемента
    int number = 0; //переменная для подсчета количества появлений определенного элемента
    for (int i = 0; i < length; i++) { //перебором по i берем элемент, поялвения которого будем считать
        number = 0; 
        for (int j = 0; j < length; j++) { //считаем сколько раз появился элемент под i, сравнивая его с каждым элементом в массиве
            if (array[i] == array[j]) //если они равны, количество прибалвяется
                number += 1;
        }
        if (number >= (length / 2)) //если количество элемента под i превысело половину или равно ей, то выводим значение элемента под i 
            return array[i];
    }
}

int main()
{
    /*Task 4*/
    int row = 0; //иницилизируем перемнные для количества строк и столбцов
    int column = 0;
    std::cout << "Enter the number of rows: ";
    std::cin >> row; //вводим количество строк
    std::cout << "Enter the number of columns: ";
    std::cin >> column; //вводим количество столбцов

    int **array4 = new int*[row];  // выделяем память для массива из количества строк
    for (int count = 0; count < row; count++) {
        array4[count] = new int[column];  // массив для столбцов
    }

    FilltheArray(array4, row, column);  // заполняем массив случайными числами через функцию
    std::cout << "Array:" << std::endl;
    ShowArray(array4, row, column);  // прказываем массив через функцию

    for (int count = 0; count < row; count++) { // освобождаем память
        delete[] array4[count];
    }
    delete[] array4;


    //Task 5//
    int num1, num2; //Объявление переменных типа int
    char operation; //Объявление переменной типа  char
    int (*funcPtr)(int, int); // Объявление указателя на функцию

    do {
        std::cout << "Enter two numbers and the operation (+, -, *, /) separated by a space (Ex: 4 5+) : ";
        std::cin >> num1; //ввод первого пареметра 
        std::cin >> num2; //ввод второго пареметра 
        operation = getchar(); //Операция вводится с помощью getchar() и сохраняется в переменной operation

        std::cout << "To complete the work at the site of the operation, enter a space \n";

        // Установка указателя на нужную функцию в зависимости от знака операции
        switch (operation) { //оператор выводит на экран результат конкретной операции в зависимости от введенного символа
            case '+':
              funcPtr = summa;
              break;
             case '-':
                funcPtr = subtract;
                break;
             case '*':
                funcPtr = multiply;
                break;
             case '/':
                funcPtr = divide;
                break;

              default:
                if (operation!=' ')
                 std::cout << "Invalid value" << std::endl;
                 continue;
                    }
    std::cout << "Result: " << funcPtr(num1, num2) << std::endl;// Выводится результат выполнения операции

    } 
    while (operation != ' '); //Цикл продолжается до тех пор, пока операция не будет равна пробелу
    



    /*Task 6*/
    int length6 = 0;
    int k6 = 0;
    std::cout << "Enter the length of array: ";
    std::cin >> length6; //вводим количество элементов массива
    std::cout << "Enter the k: ";
    std::cin >> k6; //вводим количество элементов для поиска разницы

    int *nums6 = new int[length6];  //выделяем массив
    std::cout << "Enter the numbers of array: ";  //заполняем массив перебором
    for (int count = 0; count < length6; count++) {
        std::cin >> nums6[count];
    }
    BubbleSort(nums6, length6); //сортируем массив по возрастанию
    std::cout << "The minimum differences: " << TheMinDifference(nums6, k6); //выводим разницу

    delete[] nums6;

     /*Task 7*/
     int n; // Переменная для хранения размера массива
     std::cout << "Enter the size of the array: ";
     std::cin >> n;  // Вводим размер массива
    
     std::vector<int> arr(n); // Создаем вектор для хранения элементов массива
     std::cout << "Enter the array elements: ";
     for (int i = 0; i < n; i++) { // Цикл для ввода элементов массива
         std::cin >> arr[i]; // Вводим элементы массива
     }
    
    int luckyNum = findLucky(arr); // Вызываем функцию поиска счастливого числа
    if (luckyNum != -1) {
         std::cout << "Lucky Number: " << luckyNum; // Выводим счастливое число, если оно найдено
     }
     else {
         std::cout << "No lucky number found."; // Выводим сообщение, если счастливое число не найдено
     }


    /*Task 8*/
    int n8 = 0; //переменная для количества элементов массива
    std::cout << "Enter the length of array: ";
    std::cin >> n8; //вводим количество элементов массива

    int* nums8 = new int[n8];  //выделяем массив
    std::cout << "Enter the numbers of array: ";  //заполняем массив перебором
    for (int count = 0; count < n8; count++) {
        std::cin >> nums8[count];
    }

    std::cout << "The majority element: " << TheMajorityElement(nums8, n8); //выводим искомый элемент
    delete[] nums8;

    return 0;
}