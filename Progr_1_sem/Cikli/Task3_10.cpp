#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main() {
    int n, g;  //  Создаем переменные
    cout << "Enter an integer N: \n";  //  Выводим текст с переносом на следующую строку
    cin >> n;  //  Вводим значение переменной n
    for (int i = 1;i <= n;i++) {  //  Запускаем цикл для первого слагаемого
        for (int j = 1;j <= n;j++)  {  //  Запускаем цикл для второго слагаемого
            g = n - i - j;  //  Находим третье слагаемое
                if ((g > 0) && (i >= j) && (j >= g)) cout << "N = " << i << " + " << j << " + " << g << endl;   //  Проверяем, что третье слагаемое больше нуля, и это разбиение. После выводим ответ
        }
        
    }
    return 0;
}