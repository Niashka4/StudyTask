#include <iostream>
#include <cmath>

using namespace std; 

int main()
{
    cout << "Введите два числа x,y: \n"; // Выводим текст с переносом курсора на следующую строку
    float x, y, f; // Создаем три переменные типа float
    cin >> x >> y; // Вводим две переменные
    f = (2./5)*((exp(sqrt(x*y) + sqrt(x+y))+sin(y*x))/(sqrt(cos(x)*cos(x) + sin(x*x)))); // Считаем выражение f
    cout << "Число F равно: " << f; // Выводим f

    return 0;
}