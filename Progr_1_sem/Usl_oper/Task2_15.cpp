#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main() {
    int year, n1, n2;  //  Создаём переменные для года и подсчёта остатков
    string material, animal;  //  Создаём переменные для материала и его животного
    cout << "Enter year: \n";  //  Выводим текст с переносом курсора на новую строку
    cin >> year;  //  Вводим значение года
    n1 = year % 10;  // Посчет остатка для материала
    n2 = (year + 8) % 12;  // Посчет остатка для животного
    switch (n1) {  // Switch для нохаждения материала
    case(0):case(1): material = "metal"; break;  //  Условие последней цифры для металла
    case(2):case(3): material = "water"; break;  //  Условие последней цифра для воды
    case(4):case(5): material = "wood"; break;  //  Условие последней цифры для дерева
    case(6):case(7): material = "fire"; break;  //  Условие последней цифры для огня
    case(8):case(9): material = "earth"; break;  //  Условие последней цифры для земли

    }

    switch(n2) {  // Switch для нохаждения животного
        case(0): animal = "rat"; break;  //  Условие остатка для крысы
        case(1): animal = "bull"; break;  //  Условие остатка для быка
        case(2): animal = "tiger"; break;  //  Условие остатка для тигра
        case(3): animal = "rabbit"; break;  //  Условие остатка для кроллика
        case(4): animal = "dragon"; break;  //  Условие остатка для дракона
        case(5): animal = "snake"; break;  //  Условие остатка для змеи
        case(6): animal = "horse"; break;  //  Условие остатка для лошади
        case(7): animal = "goat"; break;  //  Условие остатка для козы
        case(8): animal = "monkey"; break;  //  Условие остатка для обезьяны
        case(9): animal = "rooster"; break;  //  Условие остатка для петуха
        case(10): animal = "dog"; break;  //  Условие остатка для собаки
        case(11): animal = "boar"; break;  //  Условие остатка для кабана
    }
 
        

    cout << "It is a year of " << material << " " << animal;  //  Выводим полную информацию о годе

    return 0;
}