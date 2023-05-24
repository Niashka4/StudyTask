#include <vector>  // Подключаем необходимые библиотеки
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

int X;  //  Создаем глобальную переменную для числа

bool krat(int x) {  //  Функция определения кратен ли элемент числу
    return x % X != 0;
}

bool odd(int x) {  //  Функция определения четности числа
    return x % 2 == 0;
}

int main()
{
    int x, n;
    cout << "Enter X: "; cin >> X; cout << endl;  //  Выводим текст и переходим на новую строку, вводим число X
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

    cout << "Replace elements ne kratnie X:" << endl;  //  Выводим текст и переходим на новую строку
    vector<int> temp(vec);  //  Копируем вектор
    replace_if(temp.begin(), temp.end(), krat, 0);  //  Если элемент кратен X, заменяем его на 0

    for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
        cout << *iter << " ";  //  Выводим элемент вектора
    cout << endl;


    cout << "Summa of elements kratnih X = " << accumulate(temp.begin(), temp.end(), 0) << endl;  //  Выводим текст и переходим на новую строку, выводим сумму нужных элементов

    vector<int>::iterator iter = min_element(vec.begin(), vec.end());  //  Ищем минимальный элемент

    cout << "Minimal element = " << *iter << endl;  //  Выводим текст и переходим на новую строку, выводим минимальный элемент

    vector<int> last(vec);  //  Копируем вектор
    vector<int>::iterator iteri = max_element(vec.begin(), vec.end());  //  Ищем максимальный элемент
    cout << "Replace chetnie elements to max element: " << endl;  //  Выводим текст и переходим на новую строку
    replace_if(last.begin(), last.end(), odd, *iteri);  //  Если элемент четный, заменяем его на максимальный элемент

    for (vector<int>::iterator it = last.begin(); it != last.end(); it++)
        cout << *it << " ";  //  Выводим элемент вектора
    cout << endl;

    return 0;
}