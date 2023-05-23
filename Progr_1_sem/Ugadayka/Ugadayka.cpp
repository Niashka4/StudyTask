#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, step, num, flag, count; // Переменная n это максимальное число, которое можно загадать.
    flag = 1; //Показатель работы программы
    count = 0; //Количество шагов
    cout << "Введите число N: ";
    cin >> n;
    num = n / 2;
    if ((num % 2) == 0) step = num / 2; //выбираем удобный первый шаг
    else step = num / 2 + 1;
    while (flag){ //Цикл с поиском числа
        cout << "Число " << num << ":\n 0.Равно \n 1.Больше \n 2.Меньше \n Загаданного числа \n Ответ: ";
        cin >> flag;
        
        if (flag == 1) num -= step;
        else num += step;
        
        if ((num % 2) == 0) step = step / 2; //выбираем удобный шаг
        else step = step / 2 + 1;
        count += 1;
    }
    
    cout << "Очередная победа искусственного интеллекта совершилась за " << count << " шагов";
    
    return 0;
}