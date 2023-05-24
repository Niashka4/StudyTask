#include <map>  //  Подключаем нужные библиотеки
#include <set>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string str_tolower(string text) {  //  Функция, преобразующая текст в нижний регистр
	for (int i = 0; i < text.length(); i++)  //  Проходимся по всем элементам текста
		text[i] = tolower(text[i]);  //  Преобразуем элемент текста в нижний регистр
	return text;  //  Возвращаем текст
}

set <string> words(string text) {  //  Функция, создающая сет из слов предложения 
	set <string> predl;  //  Создаем сет из предложений
	if (text[text.length() - 1] != ' ')  //  Если последний элемент текста не равен нулю, то...
		text += " ";  //  Добавляем в конец пробел
	while (text != "") {  //  Пока мы не дойдем до конца текста...
		predl.insert(str_tolower(text.substr(0, text.find(' '))));  //  Добавляем в сет слов из предложений подстроку от 0 до найденного пробела
		text.erase(0, text.find(' ') + 1);  //  Удаляем эту подстроку
	}
	return predl;  //  Возвращаем этот сет
}
int main() {  
	setlocale(LC_ALL, "RUS");  //  Подключаем русский язык
	string text, predl;  //  Создаём строки для текста и предложения
	cout << "Введите текст: ";  //  Выводим текст
	getline(cin, text);  //  Вводим текст
	set <string> result, povest, voskl, vopr, help;  //  Создаём все необходимые сеты
	while (text != "") {  //  Пока не дойдём до конца текста...
		int pos = text.find_first_of(".!?");  //  Находим номер позиции точки, вопросительного или восклицательного знака
		predl = text.substr(0, pos);  //  Находим предложение
		help = words(predl);  //  Получаем сет из его предложений
		if (text[pos] == '.') povest.insert(help.begin(), help.end());  //  Если в конце предложения точка, добавляем слова в сет с повествовательным предложением
		if (text[pos] == '!') voskl.insert(help.begin(), help.end());  //  Если в конце предложения восклицательный знак, добавляем слова в сет с восклицательным предложением
		if (text[pos] == '?') vopr.insert(help.begin(), help.end());  //  Если в конце предложения вопросительный знак, добавляем слова в сет с вопросительным предложением
		text.erase(0, pos + 2);  //  Удаляем всё предложение
	}
	cout << "Слова из повествовательных предложений: ";  //  Выводим текст
	for (set <string> ::iterator it = povest.begin(); it != povest.end(); it++)  //  Проходим по сету с повествовательным словами
		cout << *it << " ";  //  Выводим слово
	cout << endl;
	cout << "Слова из восклицательных предложений: ";  //  Выводим текст
	for (set <string> ::iterator it = voskl.begin(); it != voskl.end(); it++)  //  Проходим по сету с восклицательными словами
		cout << *it << " ";  //  Выводим слово
	cout << endl;
	cout << "Слова из вопросительных предложений: ";  //  Выводим текст
	for (set <string> ::iterator it = vopr.begin(); it != vopr.end(); it++)  //  Проходим по сету с вопросительными словами
		cout << *it << " ";  //  Выводим слово
	cout << endl;
	set_difference(voskl.begin(), voskl.end(), povest.begin(), povest.end(), inserter(result,
		result.begin()));  //  Находим различные слова из восклицательного и повествовательного сета
	set <string> result1;  //  Создаём вспомогательный сет 
	set_difference(vopr.begin(), vopr.end(), povest.begin(), povest.end(), inserter(result1,
		result1.begin()));  //  Находим различные слова из вопросительного и повествовательного сета
	for (set<string>::iterator it = result1.begin(); it != result1.end(); it++) result.insert(*it);  //  Объединяем два результирующих сета
	cout << "Слова, которые встречаются только в вопросительных и восклицательных предложениях: ";  //  Выводим текст
	for (set <string> ::iterator i = result.begin(); i != result.end(); i++)  //  Проходимся по всем словам результирующего сета
		cout << *i << " ";  //  Выводим их
	cout << endl;
	cout << "Общее количество: " << result.size();  //  Выводим текст и количество слов
	return 0;
}

/* Cat is animal? It is pet! I know. It is my favourite pet. Wow! */
