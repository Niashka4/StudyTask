#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main() {
    float a, b, h;  //  Создаем переменные типа double для a,b и с
    float ans;  //   Создаем переменную типа float для ответа
    cout << "Enter a, b and h: \n";  //  Выводим текст с переносом курсора на новую строку
    cin >> a >> b >> h;  //  Вводим значение переменных a, b, h
    for (a; a <= b; a += h) {  //  Запускаем цикл от a до b с циклом h
        if (abs(1 - sqrt(a-3)) < 0.0001) cout << "Division by zero" << endl;  //  Проверка ОДЗ на деление на ноль
        else if ((a*a - 3*a + 1) < 0) cout << "logarithm of a non-positive number" << endl;  //  Проверка ОДЗ на логарифм из неположительного числа
        else if ((a - 3) < 0) cout << "The sqrt of a negative number" << endl;  //  Проверка ОДЗ на корень из отрицательного числа
        else {ans = (log(a*a - 2*a + 1))/(1 - sqrt(a - 3));  //  Иначе, считаем значение функции
        cout << "Function( " << a << " ) = " << ans << endl;}  //  Выводим ответ
    }
    return 0;
}