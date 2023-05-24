#include <map>  //  Подключаем нужные библиотеки
#include <set>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n, x, x1, x2, count = 0;  //  Создаём необходимые переменные
    cout << "Enter count of numbers: ";  //  Выводим текст
    cin >> n;  //  Вводим количество чисел
    multimap<int, int> a;  //  Создаем мультимап для всех чисел, где ключ - это количество цифр в числе
    set <int> b, c, d, f;  //  Создаем нужные сеты
    for (int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "] = "; cin >> x;  //  Выводим текст и вводим число 
        x1 = x;  //  Переприсваиваем число
        while (x1 > 0) { x2 = x1 % 10; x1 /= 10; count++; b.insert(x2); }  //  Добавляем в сет b цифры, введённого числа
        a.insert(make_pair(count, x));  //  Добавляем в мультимап, введённое число
        for (set<int>::iterator it = b.begin(); it != b.end(); it++) {  //  Проходим по элементам сета b
            if (count == 3) d.insert(*it); else c.insert(*it);  //  Если число трёхзначное - добавляем его в сет d, иначе в сет c
        }
        count = 0;  //  Обнуляем количество цифр
        b.clear();  //  Очищаем сет b
    }

    cout << "Digits in not three digits: " << endl;  //  Выводим текст
    for (set<int>::iterator iter = c.begin(); iter != c.end(); iter++)
        cout << *iter << " ";  //  Выводим цифры не в трёхзначных числах
    cout << endl;

    cout << "Digits in three digits: " << endl;  //  Выводим текст
    for (set<int>::iterator iti = d.begin(); iti != d.end(); iti++)
        cout << *iti << " ";  //  Выводим цифры из трёхзначных чисел
    cout << endl;

    for (set<int>::iterator iteri = c.begin(); iteri != c.end(); iteri++) {
        if (d.find(*iteri) == d.end()) f.insert(*iteri);  //  Если цифры из сета c нет в сете d, то добавляем её в сет f
    }
    cout << "All numbers that are not occur in three - digit numbers: " << endl;  //  Выводим текст
    for (set<int>::iterator ito = f.begin(); ito != f.end(); ito++)
        cout << *ito << " ";  //  Выводим получившиеся цифры
    cout << endl;

    return 0;
}