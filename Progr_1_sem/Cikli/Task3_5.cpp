#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main() {
    int n, ans = 1;  //  Создание переменных
    cout << "Enter an integer N: \n";  //  Вывод текста с переносом курсора на новую строку
    cin >> n;  //  Вводим значение переменной n
    for (int i = n; i > 0; i -= 2) {  //  Запускаем цикл
        ans *= i;  //  Считаем N!!
    }
    cout << "N!! = " << ans;  //  Выводим ответ
    return 0;
}