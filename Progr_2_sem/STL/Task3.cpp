#include <list>  // Подключаем необходимые библиотеки 
#include <numeric>  
#include <algorithm>
#include <iostream>

using namespace std;

bool odd(int x) {  //  Функция для определения четного элемента
    return x % 2 == 0;  
}

bool nodd(int x) {  //  Функция для определения нечетного элемента
    return x % 2 != 0;
}

int main()
{
    int x, n, m;  
    cout << "Enter length of first posledovatelnosti: "; cin >> n; cout << endl;  //  Выводим текст и переходим на новую строку, вводим размер первой последовательности
    list<int> lis1;  // Создаем первый список
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";  
        cin >> x;  //  Вводим элемент
        lis1.push_back(x);  //  Добавляем его в конец списка
    }

    for (list<int>::iterator iter = lis1.begin(); iter != lis1.end(); iter++) 
        cout << *iter << " ";  //  Выводим элемент списка
    cout << endl;  

    cout << "Enter length of second posledovatelnosti: "; cin >> m; cout << endl;  //  Выводим текст и переходим на новую строку, вводим размер второй последовательности
    list<int> lis2;  //  Создаем второй список
    for (int i = 0; i < m; i++) {  
        cout << "a[" << i << "] = ";  
        cin >> x;  //  Вводим элемент
        lis2.push_back(x);  //  Добавляем его в конец списка
    }

    for (list<int>::iterator iter = lis2.begin(); iter != lis2.end(); iter++)  
        cout << *iter << " ";  //  Выводим элемент списка
    cout << endl;  

    cout << "Delete chetnie elements and sort in first posledovatelnost:" << endl;  //  Выводим текст и переходим на новую строку
    list<int> tlis1(lis1);  //  Копируем список
    tlis1.remove_if(odd);  //  Удаляем четные элементы
    tlis1.sort(); tlis1.unique();  //  Сортируем список и удаляем дубликаты
    
    for (list<int>::iterator iter = tlis1.begin(); iter != tlis1.end(); iter++)  
        cout << *iter << " ";  //  Выводим элемент списка
    cout << endl;  

    cout << "Delete nechetnie elements and sort in second posledovatelnost:" << endl;  //  Выводим текст и переходим на новую строку
    list<int> tlis2(lis2);  //  Копируем список
    tlis2.remove_if(nodd);  //  Удаляем нечетные элементы
    tlis2.sort(); tlis2.unique();  //  Сортируем список и удаляем дубликаты

    for (list<int>::iterator iter = tlis2.begin(); iter != tlis2.end(); iter++)  
        cout << *iter << " ";  //  Выводим элемент списка
    cout << endl;  

    cout << "The combined resulting sequence:" << endl;  //  Выводим текст и переходим на новую строку
    tlis1.merge(tlis2);  //  Объединяем два списка
    tlis1.sort(); tlis1.unique();  //  Сортируем список и удаляем дубликаты

    for (list<int>::iterator iter = tlis1.begin(); iter != tlis1.end(); iter++)    
        cout << *iter << " ";  //  Выводим элемент списка
    cout << endl; 

    return 0;
}