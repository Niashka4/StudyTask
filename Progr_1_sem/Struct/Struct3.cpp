//  Реализовать функции для работы с комплексными числами: ввод, вывод в алгебраической и тригонометрической формах, определение модуля и аргумента числа, сложение, вычитание, умножение и деление комплексных чисел, возведение в степень.

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

struct complex_alg  //  Структура алгебраической формы комплексного числа
{
    float Re;  //  Действительная часть
    float Im;  //  Мнимая часть
};
struct complex_trig  //  Структура тригонометрической формы комплексного числа
{
    float Modul;  //  Модуль числа
    float Argum;  //  Аргумент числа
};

complex_alg enter_alg() //  Ввод числа в алгебраической форме
{
    complex_alg a;  //  Создаем экземпляр a
    cout << "Enter the real part of the number: \n";  //  Выводим текст с переносом курсора на новую строку
    cin >> a.Re;  //  Вводим действиетльную часть
    cout << "Enter the imaginary part of a complex number: \n";  //  Выводим текст с переносом курсора на новую строку
    cin >> a.Im;  //  Вводим мнимую часть
    return a;  //  Возвращаем комплексное число в алгебраической форме
}

complex_trig enter_trig()  //  Ввод числа в тригонометрической форме
{
    complex_trig a;  //  Создаем экземпляр a
    cout << "Enter the modul of a complex number: \n ";  //  Выводим текст с переносом курсора на новую строку
    cin >> a.Modul;  //  Вводим модуль числа
    cout << "Enter complex number argument: \n ";  //  Выводим текст с переносом курсора на новую строку
    cin >> a.Argum;  //  Вводим аргумент числа
    return a;  //  Возвращаем комплексное число в тригонометрической форме
}

void print_alg(complex_alg a)  //  Вывод числа в алгебраической форме
{
    cout << a.Re;  //  Выводим действительную часть
    if (a.Im >= 0)  //  Если мнимая часть больше или равна нулю
        cout << " + " << a.Im << "i " << endl;  //  Выводим мниму часть с плюсом
    else  //  Иначе...
        cout << " " << a.Im << "i " << endl;  //  с минусом
}

void print_trig(complex_trig a)  //  Вывод числа в тригонометрической форме
{
    cout << a.Modul << " ( cos ( " << a.Argum << " ) + i * sin ( " << a.Argum << " ) ) " << endl;  //  Выводим число
}


complex_alg perevod_trig_to_alg(complex_trig a)  //  Перевод числа из тригонометрической формы в алгебраическую
{
    complex_alg a_alg;  //  Создаем экземпляр a
    a_alg.Re = a.Modul * cos(a.Argum);  //  Считаем действительную часть
    a_alg.Im = a.Modul * sin(a.Argum);  //  Считаем мнимую часть
    return a_alg;  //  Возвращаем число в алгебраической форме
}


complex_trig perevod_alg_to_trig(complex_alg a) {  //  Перевод числа из алгебраической формы в тригонометрическую

    complex_trig a_trig;  //  Создаем экземпляр a
    const double M_PI = 3.14;  //  Создаем константу ПИ
    a_trig.Modul = sqrt(a.Re * a.Re + a.Im * a.Im);  //  Считаем модуль
    if (((a.Re > 0) && (a.Im > 0)) || ((a.Re > 0) && (a.Im < 0))) {  //  Если тангенс в первой или четвертой четверти...
        a_trig.Argum = atan(a.Im / a.Re);  //  то считаем аргумент так
    }
    if (((a.Re < 0) && (a.Im > 0)) || ((a.Re < 0) && (a.Im < 0))) {  //  Если тангенс во второй или третьей четверти...
        a_trig.Argum = atan(a.Im / a.Re) + M_PI;  //  то считаем аргумент так
    }
    return a_trig;  //  Возвращаем число в тригонометрической форме
}

void module_trig(complex_trig a) {  //  Нахождение модуля
    double module;  //  Создаем переменную модуля
    module = a.Modul;  //  Находим модуль
    cout << "Module of this trigonometric complex number is " << module << endl;  //  Выводим текст с переносом курсора на новую строку и модуль
}

void argum_trig(complex_trig a) {  //  Нахождение аргумента
    double argum = a.Argum;  //  Находим аргумент
    cout << "Module of this trigonometric complex number is " << argum << endl;  //  Выводим текст с переносом курсора на новую строку и аргумент
}


complex_alg summa(complex_alg a, complex_alg b)  //  Функция сложения двух чисел в алгебраической форме
{
    complex_alg c;  //  Создаем экземпляр c
    c.Re = a.Re + b.Re;  //  Находим сумму действительных частей
    c.Im = a.Im + b.Im;  //  Находим сумму мнимых частей
    return c;  //  Возвращаем сумму
}

complex_alg razn(complex_alg a, complex_alg b)  //  Функция вычитания двух чисел в алгебраической форме
{
    complex_alg c;  //  Создаем экземпляр c
    c.Re = a.Re - b.Re;  //  Находим разность действительных частей
    c.Im = a.Im - b.Im;  //  Находим разность мнимых частей
    return c;  //  Возвращаем разность
}

complex_alg proizv(complex_alg a, complex_alg b)  //  Функция умножения двух чисел в алгебраической форме,
{
    complex_alg c;  //  Создаем экземпляр c
    c.Re = a.Re * b.Re - a.Im * b.Im;  //  Находим произведение действительных частей
    c.Im = a.Im * b.Re + a.Re * b.Im;  //  Находим произведение мнимых частей
    return c;  //  Возвращаем произведение
}

complex_alg delenie(complex_alg a, complex_alg b)  //  Функция деления двух чисел в алгебраической форме,
{
    complex_alg c;  //  Создаем экземпляр c
    c.Re = (a.Re * b.Re + a.Im * b.Im) / (b.Re * b.Re + b.Im * b.Im);  //  Находим частное действительных частей
    c.Im = (a.Im * b.Re - a.Re * b.Im) / (b.Re * b.Re + b.Im * b.Im);  //  Находим частное мнимых частей
    return c;  //  Возвращаем частное
}

complex_alg step(complex_alg a, int n) {  //  Функция возведения комплексного числа в алгебраической форме в степень
    complex_alg c;  //  Создаем экземпляр c в алгебраической форме
    complex_trig c_trig;  //  Создаем экземпляр c в геометрической форме
    float p = 1; 
    c_trig = perevod_alg_to_trig(a); //  Перевод числа в тригонометрическую форму.
    for (int i = 1; i <= n; p *= c_trig.Modul, i++);  //  Запускаем цикл по степеням
    c.Re = p * cos(n * c_trig.Argum);  //  Находим действительную часть
    c.Im = p * sin(n * c_trig.Argum);  //  Находим мнимую часть
    return c;  //  Возвращаем полученное число
}

int main()
{
    int choose = 1, fl = 0, n = 0, fl2 = 0;  
    complex_alg a_alg, a2_alg, c_alg; complex_trig a_trig, a2_trig, c_trig;

    while (choose != 0) {
        cout << "Enter 1 to input algebraic complex number \n";  //  Выводим текст с переносом курсора на новую строку
        cout << "Enter 2 to input trigonometic complex number \n";  //  Выводим текст с переносом курсора на новую строку
        cin >> choose;  //  Вводим действие
        if (choose == 1) {
            fl = 1;
            a_alg = enter_alg();  //  Вводим алгебраическую форму числа
            a_trig = perevod_alg_to_trig(a_alg);  //  Находим тригонометрическую форму
        }
        if (choose == 2) {
            fl = 2;
            a_trig = enter_trig();  //  Вводим тригонометрическую форму
            a_alg = perevod_trig_to_alg(a_trig);  //  Находим алгебраическую форму
        }
        cout << "Enter 1 to print complex number \n";  //  Выводим текст с переносом курсора на новую строку
        cout << "Enter 2 to raise to a power complex number \n";  //  Выводим текст с переносом курсора на новую строку
        cout << "Enter 3 to conversion to another form complex number \n";  //  Выводим текст с переносом курсора на новую строку
        cout << "Enter 4 to input another complex \n";  //  Выводим текст с переносом курсора на новую строку
        cin >> choose;  //  Вводим действие
        if ((choose == 1) && (fl == 1)) print_alg(a_alg);  //  Если ввели алгебраическую форму, то выводим ее
        else if ((choose == 1) && (fl == 2)) print_trig(a_trig);  //  Если ввели тригонометрическую форму, то выводим ее
        else if (choose == 2) { cout << "Enter degree: "; cin >> n; a_alg = step(a_alg, n); print_alg(a_alg); a_trig = perevod_alg_to_trig(a_alg); print_trig(a_trig); }  //  Возводим число в степень n и выводим обе его формы
        else if ((choose == 3) && (fl == 1)) print_trig(a_trig); //  Переводим число в противоположную форму
        else if ((choose == 3) && (fl == 2)) print_alg(a_alg); //  Переводим число в противоположную форму
        else if (choose == 4) {
            cout << "Enter 1 to input algebraic complex number \n";  //  Выводим текст с переносом курсора на новую строку
            cout << "Enter 2 to input trigonometic complex number \n";  //  Выводим текст с переносом курсора на новую строку
            cin >> choose;  //  Вводим действие
            if (choose == 1) {
                fl2 = 1;
                a2_alg = enter_alg();  //  Вводим алгебраическую форму числа
                a2_trig = perevod_alg_to_trig(a2_alg);  //  Находим тригонометрическую форму
            }
            else if (choose == 2) {
                fl2 = 2;
                a2_trig = enter_trig();  //  Вводим тригонометрическую форму
                a2_alg = perevod_trig_to_alg(a2_trig);  //  Находим алгебраическую форму
            }
            cout << "Enter 1 to find a summ of complex number \n";  //  Выводим текст с переносом курсора на новую строку
            cout << "Enter 2 to find a difference of complex number \n";  //  Выводим текст с переносом курсора на новую строку
            cout << "Enter 3 to find a product of complex number \n";  //  Выводим текст с переносом курсора на новую строку
            cout << "Enter 4 to find a quotient of complex number \n";  //  Выводим текст с переносом курсора на новую строку
            cin >> choose;  //  Вводим действие
            if (choose == 1) {
                c_alg = summa(a_alg, a2_alg);  //  Находим сумму
                c_trig = perevod_alg_to_trig(c_alg);  // Переводим ее в тригонометрическую форму
                print_alg(c_alg);  //  Выводим сумму в алгебраической форме
                print_trig(c_trig);  // Выводим сумму в тригонометрической форме 
            }
            else if (choose == 2) {
                c_alg = razn(a_alg, a2_alg);  //  Находим разность
                c_trig = perevod_alg_to_trig(c_alg);  // Переводим ее в тригонометрическую форму
                print_alg(c_alg);  //  Выводим разность в алгебраической форме
                print_trig(c_trig);   // Выводим разность в тригонометрической форме 
            }
            else if (choose == 3) {
                c_alg = proizv(a_alg, a2_alg);  //  Находим произведение
                c_trig = perevod_alg_to_trig(c_alg);  // Переводим ее в тригонометрическую форму
                print_alg(c_alg);  //  Выводим произведение в алгебраической форме
                print_trig(c_trig);   // Выводим произведение в тригонометрической форме 
            }
            else if (choose == 4) {
                c_alg = delenie(a_alg, a2_alg);  //  Находим частное
                c_trig = perevod_alg_to_trig(c_alg);  // Переводим ее в тригонометрическую форму
                print_alg(c_alg);  //  Выводим частное в алгебраической форме
                print_trig(c_trig);   // Выводим частное в тригонометрической форме 
            }
        }
    }
    return 0;
}