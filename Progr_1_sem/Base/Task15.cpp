#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, y, summ, first, second, third; // Создаем переменные типа целое для двух чисел и трех цифр 
    cout << "Введите целое трехзначное число x: \n"; // Выводим текст
    cin >> x; // Вводим начальное число x
    summ = x/100 + ((x/10)%10) + x%10; // Находим сумму цифр числа x
    first = summ%(x/100); // Находим цифру сотен числа y
    second = summ%((x/10)%10); // Находим цифру десятков y
    third = summ%(x%10); //Находим цифру единиц y
    y = first*100+second*10+third; // Собираем число y из трех цифр
    cout << "Полученное число Y: " << y; //Выводим получившееся число y
    
    return 0;
}