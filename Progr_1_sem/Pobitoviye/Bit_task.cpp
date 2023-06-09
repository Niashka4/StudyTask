#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");  // Подключаем русский язык в программу
    int choose;  // Создаем переменную для выбора номера задания
    cout << "Enter number or task: \n";  // Выводим текст с переносом курсора на новую строку
    cin >> choose;  // Вводим номер задания
    int n,i;  // Создаем целочисленные переменные для чисел n и i
    if (choose == 1) {  // Код для задачи номер 1
        n = 1;  // Задаем значение для переменной n
        cout << "Enter number i: \n";  // Выводим текст с переносом курсора на новую строку
        cin >> i;  // Вводим значение для переменной i
        cout << "Resulting number: " << (n << i);  //  Выводим текст и ответ на задачу
    } else if (choose == 2) {  // Код для задачи номер 2
        cout << "Enter number n: \n";  // Выводим текст с переносом курсора на новую строку
        cin >> n;  // Вводим значение для переменной n
        cout << "Enter a number of bit (number i): \n";  // Выводим текст с переносом курсора на новую строку
        cin >> i;  // Вводим значение для переменной i
        cout << "Resulting number: " << (n | (1 << i));  //  Выводим текст и ответ на задачу
    } else if (choose == 3) {  // Код для задачи номер 3
        cout << "Enter number n: \n";  // Выводим текст с переносом курсора на новую строку
        cin >> n;  // Вводим значение для переменной n
        cout << "Enter a number of bit (number i): \n";  // Выводим текст с переносом курсора на новую строку
        cin >> i;  // Вводим значение для переменной i
        cout << "Resulting number: " << (~ ((~ n) | (1 << i)));  //  Выводим текст и ответ на задачу
    } else if (choose == 4) {  // Код для задачи номер 4
        cout << "Enter number n: \n";  // Выводим текст с переносом курсора на новую строку
        cin >> n;  // Вводим значение для переменной n
        cout << "Enter a number of bit (number i): \n";  // Выводим текст с переносом курсора на новую строку
        cin >> i;  // Вводим значение для переменной i
        cout << "Resulting number: " << (n ^ (1 << i));  //  Выводим текст и ответ на задачу
    } else if (choose == 5) {  // Код для задачи номер 5
        cout << "Enter number n: \n";  // Выводим текст с переносом курсора на новую строку
        cin >> n;  // Вводим значение для переменной n
        if ((n & 1) == 0) {  // Проверка на четность
            cout << "Number n is even (n % 2 == 0)";  //Выводим ответ на задачу текстом, если число четное
        } else {
            cout << "Number n is odd (n & 2 != 0)";  //  Выводим ответ на задачу текстом, если число нечетное
        }
    }
    return 0;
}