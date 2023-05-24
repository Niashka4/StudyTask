#include <iostream>  //  Подключаем нужные библиотеки
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

bool operator < (const people& a, const people& b) {  //  переопределяем оператор < в соотвествии с условием
	if (a.DataRojdeniya.yy < b.DataRojdeniya.yy) return true;  //  Сортируем по году рождения
	if ((a.DataRojdeniya.yy == b.DataRojdeniya.yy) && (a.Staje < b. Staje)) return true;  //  Если год один и тот же, сортируем по стажу
	return false;  //  Иначе ложь
}

void comb_sort(vector<people>& pip) {  //  Функция сортировки расчёской
	int gap = pip.size();  //  Изначально gap равен размеру вектора
	while (gap != 1) {  //  Пока gap не равен 1 - сортируем
		gap = gap / 1.247;  //  Делим нацело gap на фиксированное значение 1.247
		if (gap < 1) gap = 1;  //  Если gap стал меньше 1, то переприсваиваем его как 1, чтобы закончить цикл
		for (int i = 0; i < pip.size() - gap; i++) {  //  Проходимся от первого элемента до размера вектора минус gap
			if (pip[i + gap] < pip[i]) {  //  Если два элемента стоят не по возрастанию, то...
				swap(pip[i + gap], pip[i]);  //  Меняем их местами
			}
		}
	}
}

int main() {
	vector <people> x;  //  Создаем вектор из людей	
	x = inFile();  //  Вводим всех людей из файла через пользовательскую функцию
	cout << " \n" << endl;
	
	comb_sort(x);  //  Сортируем расческой

	for (auto& i : x)  //  Проходимся по списку всех людей
		print(i);  //  Выводим отсортированный список в файл через сортировку расческой
	return 0;
}

