#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main() {
    int n;  //  Создаём переменную n типа int
    float yn = 0, yn1 = 1, yn2 = 2;  // Создаём переменные для y(n), y(n-1) и y(n-2)
    cout << "Enter n: "; cin >> n;  //  Выводим текст и вводим значение переменной n
    for (int i = 1; i <= n; ++i) {  //  Запускаем цикл от 1 до n
        if (i == 1) {  //  Условие для n = 1
            yn = 2; yn2 = 2; cout << "n = " << i << "; " << "y(n) = " << yn << endl;  //  Выводим y(1)
        }
        else if (i == 2) {  //  Условие для n = 2
            yn = 1; yn1 = 1; cout << "n = " << i << "; " << "y(n) = " << yn << endl;  //  Выводим y(2)
        }
        else {  //  Условие для n > 2
            yn = (yn1 / 6) + (yn2 / 9);  //  Cчитаем y(n), где n > 2

            cout << "n = " << i << "; " << "y(n) = " << yn << endl;  //  Выводим получившийся y(n)
            yn2 = yn1;  //  Переприсваиваем для n = n + 1 y(n-2) как y(n-1)
            yn1 = yn;  //  Переприсваиваем для n = n + 1 y(n-1) как y(n)
        }
    }
    return 0;
}