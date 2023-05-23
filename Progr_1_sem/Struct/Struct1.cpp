 //  Создать структуру Hotel, содержащую следующие данные: ФИО туриста, дату прибытия и дату отъезда. Определить сколько дней каждый турист проведет в отеле. Необходима проверка на корректность ввода дат.

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct Hotel {  //  Создаем структуру Hotel
	string name;  //  Параметр ФИО
	string priezd;  //  Дата приезда
	string otezd;  //  Дата отъезда
};

struct date {  //  Создаем структуру даты
	int day;  //  День
	int month;  //  Месяц
	int year;  //  Год
};

date STR_date(string str) {  //  Функция перевода из строки в дату
	date data;  //  Создаем объект даты

	string str1 = str.substr(0, 2);  //  Строка дня  
	const char* sd = str1.c_str();  //  Переводим в char
	int dd = atoi(sd);  //  Переводим из char в int
	data.day = dd;  //  Заносим в data день

	str1 = str.substr(3, 2);  //  Строка месяца
	sd = str1.c_str();  //  Переводим в char
	dd = atoi(sd);  //  Переводим из char в int
	data.month = dd;  //  Заносим в data месяц

	str1 = str.substr(6, 4);  //  Строка года
	sd = str1.c_str();  //  Переводим в char
	dd = atoi(sd);  //  Переводим из char в int
	data.year = dd;  //  Заносим в data год
	return data;  //  Возвращаем дату с int параметрами
}

bool vis(int y) {  //  Определение високосного года
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;  //  Если выполняется условие високосного года, то год високосный
}

int EndOfMonth(int m, int y) {  //  Определение конца месяца
	switch (m) {  //  Свитч по номеру месяцв
	case 1: case 3: case 5:  
	case 7: case 8: case 10: case 12: return 31;  //  В этих месяцах 31 день
	case 4: case 6: case 9: case 11: return 30;  //  В этих месяцах 30 дней
	case 2: if (vis(y)) return 29;  //  В вискосном году в феврале 29 дней
		  else return 28;  //  Иначе 28 дней
	default: return 0;
	}
}

int correct(string str) {  //  Функция проверки корректности данных
	if (str.length() != 10) return -1;  //  Если введена не полностью дата
	for (string::size_type i = 0; i < str.length(); i++)  //  Проходим по длине строки
		if (i != 2 && i != 5) {  //  Если эти символы...
			if (!isdigit(str[i])) return -1;  //  не цифры, возвращаем -1
	}
	date data = STR_date(str);  //  Переводим дату из строки в int
	if (data.day <= 0 || data.day > EndOfMonth(data.month, data.year)) return -2;  //  Если день набран неправильно
	if (data.month <= 0 || data.month > 12) return -3;  //  Если неправильно набран месяц
	if (data.year == 0) return -4;  //  Если неправильно набран год
	return 1;  //  Все верно
}

int days(string priezd, string otezd) {  //  Функция подсчета количества дней
	int count = 0;  //  Обнуляем количество
	date npriezd = STR_date(priezd);  // Переводим дату приезда из строки в int 
	date notezd = STR_date(otezd);  //  Переводим дату отъезда из строки в int
	date data, data1;  //  Создаем экземпляры даты
	data.day = npriezd.day;  //  Присваиваем день
	data.month = npriezd.month;  //  Присваиваем месяц
	data.year = npriezd.year;  //  Присваиваем год
	while ((data.day < notezd.day) || (data.month < notezd.month) || (data.year < notezd.year)) {   //  Пока день, месяц и год не будут равны дате отъезда
		data1.day = data.day;  //  Присваиваем день
		data1.month = data.month;  //  Присваиваем месяц
		data1.year = data.year;  //  Приваиваем год 
		if (data.day < EndOfMonth(data.month, data.year)) data1.day = data.day + 1;  //  Если не конец месяца
		else if (data.month < 12) {  //  Если конец месяца, но не конец года
			data1.day = 1;  //  День 1
			data1.month = data.month + 1;  //  Увеличиваем месяц на один
		}
		else {  //  31 декабря
			data1.day = 1;  //  День 1
			data1.month = 1;  //  Месяц 1
			data1.year = data.year + 1;  //  Год на один больше  
		}
		count++;  //  Увеличиваем количество дней на 1
		data.day = data1.day;  //  Переприсваиваем день
		data.month = data1.month;  //  Переприсваиваем месяц
		data.year = data1.year;  //  Переприсваиваем год
	}
	return count;  //  Возвращаем количество дней
}

Hotel* create(int &n) {  //  
	cout << "How much tourist? \n";  //  Выводим текст с переносом строки на новую
	cin >> n;  //  Вводим количество туристов
	int fl1 = 0, fl2 = 0, k = 0;  //  Создаем переменные для проверки
	string name, surname, patronymic, str;  //  Создаем строки для имени, фамилии, отчества
	Hotel* a = new Hotel[n];  //  Создаем массив туристов
	for (int i = 0; i < n; i++) {  //  Проходим по всем туриста
		cout << "Enter " << i + 1 << " tourist name: \n";  //  Выводим текст с переносом строки на новую
		if (i == 0) getline(cin, str);  
		getline(cin, name);  //  Вводим имя
		cout << "Enter " << i + 1 << " tourist surname: \n";  //  Выводим текст с переносом строки на новую
		getline(cin, surname);  //  Вводим фамилию
		cout << "Enter " << i + 1 << " tourist patronymic: \n";  //  Выводим текст с переносом строки на новую
		getline(cin, patronymic);  //  Вводим отчество
		a[i].name = name + " " + surname + " " + patronymic;  //  Создаем ФИО туриста
		cout << "FIO - " + a[i].name << endl;  //  Выводим ФИО туриста
		cout << "Input date of arriving " << i + 1 << " tourist: \n";  //  Выводим текст с переносом строки на новую
		getline(cin, a[i].priezd);  //  Вводим дату приезда

		fl1 = correct(a[i].priezd);  //   Проверяем дату приезда на корректность
		if (fl1 == -1) cout << "Error input\n";  //  Если ввели неправильно дату
		else if (fl1 == -2) cout << "Error day\n";  //  Неправильно введен день
		else if (fl1 == -3) cout << "Error month\n";  //  Неправильно введен месяц 
		else if (fl1 == -4) cout << "Error year\n";  //  Неправильно введен год

		cout << "Input date of leaving " << i + 1 << " tourist: \n";  //  Выводим текст с переносом строки на новую
		getline(cin, a[i].otezd);  //  Вводим дату отъезда
		
		fl2 = correct(a[i].otezd);  //  Проверяем дату отъезда на корректность
		if (fl2 == -1) cout << "Error input\n";  //  Если ввели неправильно дату
		else if (fl2 == -2) cout << "Error day\n";   //  Неправильно введен день
		else if (fl2 == -3) cout << "Error month\n";  // Неправильно введен месяц 
		else if (fl2 == -4) cout << "Error year\n";  //  Неправильно введен год

		if ((fl1 == 1) && (fl2 == 1)) {  //  Если мы прошли все проверки дат, то...
			cout << i + 1 << " tourist spend at the hotel - " << days(a[i].priezd, a[i].otezd) << " days." << endl;  //  Выводим текст и считаем количество дней
		}
	
	}
	return a;  //  Возвращаем массив жильцов
}

int main() {
	int n;  //  Создаем переменную для количества жильцов
	Hotel* a = create(n);  //  Создаем массив жильцов

	return 0;
}