#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, y; // Создаем переменные типа целое для двух чисел 
    int first1, second1, first2, second2, third2, fourth2; // Создаем переменные типа float для двух цифр первого числа и трех цифр второго
    cout << "Введите целое двузначное число x: \n"; // Выводим текст
    cin >> x; // Вводим начальное число x
    first1 = x/10; // Находим цифру десятков числа x
    second1 = x%10; // Находим цифру единиц числа x
    first2 = (first1*second1) % 10; // Находим цифру тысяч числа y
    second2 = second1 % first1; // Находим цифру сотен числа y
    third2 = (first1 + second1)%second1; // Находим цифру десятков числа y
    fourth2 = first1%second1; // Находим цифру единиц числа y
    y = first2 * 1000 + second2 * 100 + third2 * 10 + fourth2; // Собираем число y из четырех цифр
    
    cout << "Полученное число Y: " << y; //Выводим получившееся число y
    
    return 0;
}