#pragma once
using namespace std;

int progressive(int n, int a1, int znam, int i) {  //  Функция для геометрической прогрессии
	int an = a1;  //  Первое значение
	if (n == 1) return a1;  //  Если ищем первый член
	if (i == n) return an;  //  Если мы дошли до нужного элемента
	if (i < n) return progressive(n, an * znam, znam, i + 1);  //  Идем до нужного элемента с рекурсией
}

int kubish(int x, int n) {  //  Функция полинома Чебышева
	if (n == 0) return 1;  //  Первое значение
	else if (n == 1) return 2 * x - 1;  //  Второе
	else return 2 * (2 * x - 1) * kubish(x, n - 1) - kubish(x, n - 2);  // Вычисление для остальных n
}

double drob(int i, int n) {  //  Функция цепной дроби
	if (i == n) return (n - 1)/((n - 1) + n);  //  Условие для вычисления о формуле
	if (i < n) return i / (i + drob(i + 1, n));  //  Условие для вычисления с рекурсивной функцией
}

void print(int n, char a) {  //  Функция печати символов
	for (int i = 0; i < n; i++)  //  Запускаем цикл
		cout << a;  //  Печатаем символ
}

void func(int p, int n) {  //  Функция для рисунка
	if (n >= 1) {  //  Условие работы функции
		print(p, ' ');  //  Печатаем пробелы
		print(n, '*');  //  Печатаем звездочки
		cout << endl;  //  Переход на новую строку
		func(p + 1, n - 2);  //  Выолняем следующую функцию
	}
}