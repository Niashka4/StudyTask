//  Дано множество точек на плоскости. Найти все точки, находящиеся внутри прямоугольника с координатами вершин {Xmin, Ymin}, {Xmax, Ymax}

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct point {  //  структура создания точки
	double x, y;  //  Координаты точек
};

point * create(int& n) {  //  функция создания массива точек
	cout << "Enter count of points: \n";  //  Выводим текст и переносим курсор на новую строку
	cin >> n;  //  Вводим количество точек
	point * a = new point[n]; //  Создаем массив точек
	for (int i = 0; i < n; i++) {  //  Прохоим по номерам точек
		cout << "Input " << i + 1 << " point coordinates (x, y): \n";  //  Выводим текст с переносом курсора на новую строку  
		cin >> a[i].x >> a[i].y;  //  Вводим координаты точки
	}
	return a;  //  Возвращаем массив точек
}

void result(point* a, int n, double xmin, double ymin, double xmax, double ymax) {  //  Функция для определения точек внутри прямоугольника
	for (int i = 0; i < n; i++) {  //  Проходим по номерам точек
		if ((a[i].x > xmin) && (a[i].x < xmax) && (a[i].y > ymin) && (a[i].y < ymax)) {  //  Если x координата точки находится в отрезки от xmin до xmax и у координата - от ymin до ymax, то точка находится внутри прямоугольника
			cout << "This point is inside the given rectangle: { " << a[i].x << " ; " << a[i].y << " }" << endl;  //  Выводим текст и подходящую точку
		}
	}
}


int main() {
	int n;  //  Создаем переменную для количества точек
	double xmin, xmax, ymin, ymax;  //  Создаем переменные для координат вершин прямоугольника
	point * a = create(n);  //  Создаем массив точек
	cout << "Input two opposite points of rectangle in format {Xmin, Ymin}, {Xmax, Ymax}: \n";  // Выводим текст с переносом курсора на новую строку 
	cin >> xmin >> ymin >> xmax >> ymax;  //  Вводим координаты двух противоположных вершин прямоугольника
	if ((xmin >= xmax) && (ymin >= ymax)) cout << "Error input!";  //  Если это не противоположные вершины, выводим ошибку
	result(a, n, xmin, ymin, xmax, ymax);  //  Выполняем функцию для нахождения подходящих точек
	return 0;
}