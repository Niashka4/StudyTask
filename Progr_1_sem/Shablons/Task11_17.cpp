#include <iostream>
#include <cmath>  //  Подключаем библиотеку с математическими функциями
using namespace std;

template < typename X>
X** create(X c, int n, int m) {  //  создание
	X** a = new X * [n]; //  выделение памяти
	for (int i = 0; i < n; i++)  //  Проходим по рядам
		a[i] = new X[m];  //  Создаем столбцы
	for (int i = 0; i < n; i++) //  ввод массива
		for (int j = 0; j < m; j++)  //  Проходим по стобцам
			cin >> a[i][j];  //  Вводим элемент массива
	return a;  //  Выводим массив
}

template < typename X>
void print(X** a, int n, int m) { //  печать
	for (int i = 0; i < n; i++, cout << endl)  //  Проходим по рядам
		for (int j = 0; j < m; j++)  //  Проходим по стобцам
			cout << a[i][j] << " ";  //  Выводим элемент массива
}

template < typename X>
void change10(X ** a, int n, int m, X* x, int b) {  //  замена
	int count = 0;  // Переменная счетчик
	int A = 1; 
	for (int i = 0; i < n; i++, count = 0)  //  Проходим по рядам
		for (int j = 0; j < m; j++) {  //  Проходим по столбцам
			A = a[i][j];  //  Переприсваиваем элемент массива
			if ((A % 2) == 1) count += 1;  //  Если элемент нечетный, то счетчик +1
			if (count == m) {  //  Если все нечетные, то...
				for (int j1 = 0; j1 < m; j1++)  //  Проходим по столбцам
					a[i][j1] = x[j1];  //  Производим замену
			}
		}
}

template < typename X>
X* create_x(X c, int n) {  //  создание
	X* x = new X[n]; //  выделение памяти
	for (int i = 0; i < n; i++)  //  Проходимся по элементам массива
		cin >> x[i];  //  Вводим элемент массива
	return x;  //  Возвращаем одномерный массив
}


int main() {
	char g;  //  Создаем переменную для повторения задания
	int n = 0, m = 0;  //  Создаем переменные для размера массива
	cout << "Input dimension\n";  //  Выводим текст
	cin >> n >> m;  //  Вводим размеры массива
	do {
		cout << "Enter type:\n1 - int\n2 - double\n3 - float\n";  //  Выводим текст
		int k;  // Создаем переменную для типа
		cin >> k;  //  Вводим тип
		switch (k) {  //  вызываем различные типы
		case 1: {  //  Для Int
			int c = 1;  //  Int переменная
			int** a = create(c, n, m);  //  Создаем двумерный массив
			cout << "INT:\n";  //  Выводим текст
			print(a, n, m);  //  Выводим массив
			int* x = create_x(c, m);  //  Создаем одномерный массив
			change10(a, n, m, x, 1);  //  Производим замену
			cout << "New:\n";  //  Выводим текст
			print(a, n, m);  //  Выводим измененный массив
			break;  
		}
		case 2: {  //  Для Double
			double c1 = 1;  //  Double переменная
			double** a1 = create(c1, n, m);  //  Создаем двумерный массив
			cout << "DOUBLE:\n";  //  Выводим текст
			print(a1, n, m);  //  Выводим массив
			double *x1 = create_x(c1, m);  //  Создаем одномерный массив
			change10(a1, n, m, x1, 2);  //  Производим замену
			cout << "New:\n";  //  Выводим текст
			print(a1, n, m);  //  Выводим измененный массив
			break;
		}
		case 3: {  //  Для Float
			float c3 = 1;  //  Float переменная
			float** a3 = create(c3, n, m);  //  Создаем двумерный массив
			cout << "FLOAT:\n";  //  Выводим текст
			print(a3, n, m);  //  Выводим массив
			float *x3 = create_x(c3, m);  //  Создаем одномерный массив
			change10(a3, n, m, x3, 3);   //  Производим замену
			cout << "New:\n";  //  Выводим текст
			print(a3, n, m);  //  Выводим измененный массив
			break;
		}
		default: cout << "Error! \n";  //  Если данные введены неверно
		}
		cout << "Again? Y - yes, N - no\n";  //  Выводим текст
		cin >> g; // повторяем запуск программы пока не введем N
	} while (g != 'N');
	return 0;
}