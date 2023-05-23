#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main() {
    int x;  //  Создаём переменную для X
    float f;  //  Создаём переменную для X
    cout << "Enter X: \n";  //  Выводим текст с переносом курсора на новую строку
    cin >> x;  //  Вводим значение переменной X
    
    if ((6-x) < 0 || (x*x - 2*x + 1) < 0)  //  Проверка ОДЗ корня
    cout << "The root of a negative number";   //  Выводим ошибку ОДЗ
    else if ((sqrt(x*x - 2*x + 1) == 0) || (exp(x - 5) - 1 == 0))  //  Проверка ОДЗ деления на ноль
    cout << "Division by zero";  //  Выводим ошибку ОДЗ
    else if (x <= 0)  //  Проверка ОДЗ логарифма
    cout << "Logarithm of a non - positive number";  //  Выводим ошибку ОДЗ
    
    
    else {f = ((sqrt(6 - x)) / (sqrt(x*x - 2*x + 1))) + ((log(x)) / (exp(x - 5) - 1));  //  Если X удовлетворяет ОДЗ, считаем значение F
    cout << "Answer F: " << f;  //  Выводим ответ
    }

    return 0;
}