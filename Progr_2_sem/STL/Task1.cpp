#include <vector>  // Подключаем необходимые библиотеки 
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

int a, b;  //  Создаем глобальные переменные для концов отрезка

bool odd(int x) {  // Функция определения находится ли элемент в отрезке
    return (x >= a) && (x <= b);
}

int main()
{
    int x, n;
    cout << "Enter A and B: "; cin >> a >> b; cout << endl;  //  Выводим текст и переходим на новую строку, вводим концы отрезка
    cout << "Enter length: "; cin >> n; cout << endl;  //  Выводим текст и переходим на новую строку, вводим размер последовательности
    vector<int> vec;  // Создаем вектор
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> x;  //  Вводим элемент
        vec.push_back(x);  //  Добавляем его в конец вектора
    }

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";  //  Выводим элемент вектора
    cout << endl;

    cout << "Replace elements in [a,b]:" << endl;  //  Выводим текст и переходим на новую строку
    vector<int> temp(vec);  //  Копируем вектор
    replace_if(temp.begin(), temp.end(), odd, 0);  //  Если элемент находится внутри отрезка, меняем его значение на ноль

    for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
        cout << *iter << " ";  //  Выводим элемент вектора
    cout << endl;

    cout << "Summa of elements = " << accumulate(temp.begin(), temp.end(), 0) << endl;  //  Выводим текст и переходим на новую строку, выводим сумму нужных элементов вектора




    return 0;
}