#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Введите два числа x,y: \n"; // Выводим текст с переносом курсора на следующую строку
    float x, y, f; // Создаем три переменные типа float
    cin >> x >> y; // Вводим две переменные
    f = sqrt(log((cos(x+y)*cos(x+y))/(sin((x+y)*(x+y)))) * log((cos(x+y)*cos(x+y))/(sin((x+y)*(x+y)))) + exp(x*x*y)); // Считаем выражение f
    cout << "Число F равно: " << f; // Выводим f

    return 0;
}