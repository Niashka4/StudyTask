﻿#include <iostream>  //  Подключаем нужные библиотеки
#include <fstream>
#include <string>
#include <vector> 
#include <iomanip>
#include <algorithm>

using namespace std;

ifstream in("C:/Users/savelevdv/Downloads/Sort/info.txt");  //  Открываем файл
ofstream out("C:/Users/savelevdv/Downloads/Sort/out.txt");  //  Выводим список в другой файл

struct date {  //  Создаем структуру даты
	int dd, mm, yy;
};

struct people {  //  Структура человека
	string Name;  // Фамилия
	string Doljnost;  //  Должность
	date DataRojdeniya{};  //  Дата рождения
	int Staje{};  //  Стаж
	int Zarplata{};  //  Зарплата
};

date Str_to_Date(const string& str) {  //  Переводим дату из строки в структуру
	date x{};  //  Создаем экземпляр даты
	string temp;
	temp = str.substr(0, 2);  //  Получаем день
	x.dd = atoi(temp.c_str());  //  Переводим в Int
	temp = str.substr(3, 2);  //  Получаем месяц
	x.mm = atoi(temp.c_str());  //  Переводим в Int
	temp = str.substr(6, 4);  // Получаем год
	x.yy = atoi(temp.c_str());  //  Переводим в Int
	return x;  //  Возвращаем дату
}

vector<people> inFile() {  //  Функция ввода из файла
	vector<people> x;  //  Создаем вектор людей
	people temp;
	while (in.peek() != EOF) {  //  Пока не дойдём до конца файла
		in >> temp.Name;  //  Вводится имя
		in >> temp.Doljnost;  //  Вводится должность
		string tmp;
		in >> tmp;  //  Вводится дата рождения
		temp.DataRojdeniya = Str_to_Date(tmp);  //  Переводим строку в дату
		in >> temp.Staje;  //  Вводится стаж работы
		in >> temp.Zarplata;  //  Вводится зарплата
		x.push_back(temp);  //  Заносим человека в вектор людей
	}
	return x;  //  Возвращаем этот вектор
}

void print(const people& x) {  //  Вывод в файл
	out << setw(21) << left << x.Name;  //  Делаем отступ для имени
	out << setw(24) << left << x.Doljnost;  //  Делаем отступ для должности
	if (x.DataRojdeniya.dd < 10) out << left << '0' << x.DataRojdeniya.dd << '.';  //  Добавляем 0
	else out << left << x.DataRojdeniya.dd << '.';  //  Ничего не добавляем
	if (x.DataRojdeniya.mm < 10) out << '0' << x.DataRojdeniya.mm << '.';  //  Добавляем 0
	else out << x.DataRojdeniya.mm << '.';  //  Ничего не добавляем
	out << left << setw(6) << x.DataRojdeniya.yy;  //  Делаем отступ для года
	out << left << setw(5) << x.Staje;  //  Делаем отступ для стажа
	out << left << setw(8) << x.Zarplata << endl;  //  Делаем отступ для зарплаты
}

bool operator < (const people& a, const people& b) {  //  Переопределяем оператор < в соответствии с условием
    if (a.Name < b.Name) return true;  //  Сортируем по имени
    if (a.Name == b.Name && a.Doljnost < b.Doljnost) return true;  //  Если имена одинаковые, то сортируем по должности
    if (a.Name == b.Name && a.Doljnost == b.Doljnost && a.DataRojdeniya.yy < b.DataRojdeniya.yy) return true;  //  Если и должность одинаковая, то сортируем по году рождения
    return false;
}

void sort_vstavkoy(vector<people>& pip) {  //  Сортировка вставками
    for (int i = 1; i < pip.size() - 1; i++) {  //  Проходимся по всему вектору -1
        int j = i;  //  Запоминаем номер данного элемента массива
        while (j > 0 && pip[j] < pip[j-1]) {  //  До тех пор пока номер данного элемента больше нуля и он больше, чем предыдущий элемент...
            swap(pip[j], pip[j - 1]);  //  Меняем их местами
            j--;  //  Отходим на один шаг назад

        }
    }
}

int main() {
    vector <people> x;  //  Создаем вектор из людей	
    x = inFile();  //  Вводим всех людей из файла через пользовательскую функцию
    cout << " \n" << endl;

    sort_vstavkoy(x);  //  Сортируем вставками

    for (auto& i : x)  //  Проходимся по списку всех людей
        print(i);  //  Выводим отсортированный список в файл через сортировку вставками
    return 0;
}

