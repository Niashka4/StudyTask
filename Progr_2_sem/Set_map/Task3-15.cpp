#include <fstream>  //  Подключаем нужные библиотеки
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool is_number(string text) {  //  Функция определения является элемент числом или словом
	for (int i = 0; i < text.length(); i++)  //  Проходимся по тексту
		if (isdigit(text[i])) return true;  //  Если элемент текста число, возвращаем true
	return false;  //  Иначе false
}
int main() {
	setlocale(LC_ALL, "RUS");  //  Подключаем русский язык
	string el;  //  Создаём строку элемента
	map<string, int> numbers;  //  Создаём мап из элемента и количества его вхождения в текст
	ifstream in("text.txt");  //  Считываем файл
	int k = 0, fl = 0;  //  Создаём переменную k и флаг
	cout << "Введите число k: "; cin >> k;  //  Выводим текст и вводим значение k
	while (in.peek() != EOF) {  //  Пока не дойдём до конца файла
		in >> el;  //  Считываем элемент
		if (is_number(el))  //  Если элемент - число, то...
			numbers[el] ++;  //  Добавляем его в мап numbers и увеличиваем число его вхождений в текст на 1
	}
	cout << "Все числа, встречающиеся ровно k раз: ";  //  Выводим текст
	for (map <string, int> ::iterator i = numbers.begin(); i != numbers.end(); i++) {  //  Проходим по всем числам
		if (i->second == k) { //  Если число вхождений равно k, то...
			cout << i->first << " ";  //  Выводим сам элемент
			fl = 1;
		}
	}
	if (fl == 0) cout << "таких чисел нет";  //  Если таких чисел нет, выводим текст
	return 0;
}