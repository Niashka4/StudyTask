 //  ������� ��������� Hotel, ���������� ��������� ������: ��� �������, ���� �������� � ���� �������. ���������� ������� ���� ������ ������ �������� � �����. ���������� �������� �� ������������ ����� ���.

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct Hotel {  //  ������� ��������� Hotel
	string name;  //  �������� ���
	string priezd;  //  ���� �������
	string otezd;  //  ���� �������
};

struct date {  //  ������� ��������� ����
	int day;  //  ����
	int month;  //  �����
	int year;  //  ���
};

date STR_date(string str) {  //  ������� �������� �� ������ � ����
	date data;  //  ������� ������ ����

	string str1 = str.substr(0, 2);  //  ������ ���  
	const char* sd = str1.c_str();  //  ��������� � char
	int dd = atoi(sd);  //  ��������� �� char � int
	data.day = dd;  //  ������� � data ����

	str1 = str.substr(3, 2);  //  ������ ������
	sd = str1.c_str();  //  ��������� � char
	dd = atoi(sd);  //  ��������� �� char � int
	data.month = dd;  //  ������� � data �����

	str1 = str.substr(6, 4);  //  ������ ����
	sd = str1.c_str();  //  ��������� � char
	dd = atoi(sd);  //  ��������� �� char � int
	data.year = dd;  //  ������� � data ���
	return data;  //  ���������� ���� � int �����������
}

bool vis(int y) {  //  ����������� ����������� ����
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;  //  ���� ����������� ������� ����������� ����, �� ��� ����������
}

int EndOfMonth(int m, int y) {  //  ����������� ����� ������
	switch (m) {  //  ����� �� ������ ������
	case 1: case 3: case 5:  
	case 7: case 8: case 10: case 12: return 31;  //  � ���� ������� 31 ����
	case 4: case 6: case 9: case 11: return 30;  //  � ���� ������� 30 ����
	case 2: if (vis(y)) return 29;  //  � ��������� ���� � ������� 29 ����
		  else return 28;  //  ����� 28 ����
	default: return 0;
	}
}

int correct(string str) {  //  ������� �������� ������������ ������
	if (str.length() != 10) return -1;  //  ���� ������� �� ��������� ����
	for (string::size_type i = 0; i < str.length(); i++)  //  �������� �� ����� ������
		if (i != 2 && i != 5) {  //  ���� ��� �������...
			if (!isdigit(str[i])) return -1;  //  �� �����, ���������� -1
	}
	date data = STR_date(str);  //  ��������� ���� �� ������ � int
	if (data.day <= 0 || data.day > EndOfMonth(data.month, data.year)) return -2;  //  ���� ���� ������ �����������
	if (data.month <= 0 || data.month > 12) return -3;  //  ���� ����������� ������ �����
	if (data.year == 0) return -4;  //  ���� ����������� ������ ���
	return 1;  //  ��� �����
}

int days(string priezd, string otezd) {  //  ������� �������� ���������� ����
	int count = 0;  //  �������� ����������
	date npriezd = STR_date(priezd);  // ��������� ���� ������� �� ������ � int 
	date notezd = STR_date(otezd);  //  ��������� ���� ������� �� ������ � int
	date data, data1;  //  ������� ���������� ����
	data.day = npriezd.day;  //  ����������� ����
	data.month = npriezd.month;  //  ����������� �����
	data.year = npriezd.year;  //  ����������� ���
	while ((data.day < notezd.day) || (data.month < notezd.month) || (data.year < notezd.year)) {   //  ���� ����, ����� � ��� �� ����� ����� ���� �������
		data1.day = data.day;  //  ����������� ����
		data1.month = data.month;  //  ����������� �����
		data1.year = data.year;  //  ���������� ��� 
		if (data.day < EndOfMonth(data.month, data.year)) data1.day = data.day + 1;  //  ���� �� ����� ������
		else if (data.month < 12) {  //  ���� ����� ������, �� �� ����� ����
			data1.day = 1;  //  ���� 1
			data1.month = data.month + 1;  //  ����������� ����� �� ����
		}
		else {  //  31 �������
			data1.day = 1;  //  ���� 1
			data1.month = 1;  //  ����� 1
			data1.year = data.year + 1;  //  ��� �� ���� ������  
		}
		count++;  //  ����������� ���������� ���� �� 1
		data.day = data1.day;  //  ��������������� ����
		data.month = data1.month;  //  ��������������� �����
		data.year = data1.year;  //  ��������������� ���
	}
	return count;  //  ���������� ���������� ����
}

Hotel* create(int &n) {  //  
	cout << "How much tourist? \n";  //  ������� ����� � ��������� ������ �� �����
	cin >> n;  //  ������ ���������� ��������
	int fl1 = 0, fl2 = 0, k = 0;  //  ������� ���������� ��� ��������
	string name, surname, patronymic, str;  //  ������� ������ ��� �����, �������, ��������
	Hotel* a = new Hotel[n];  //  ������� ������ ��������
	for (int i = 0; i < n; i++) {  //  �������� �� ���� �������
		cout << "Enter " << i + 1 << " tourist name: \n";  //  ������� ����� � ��������� ������ �� �����
		if (i == 0) getline(cin, str);  
		getline(cin, name);  //  ������ ���
		cout << "Enter " << i + 1 << " tourist surname: \n";  //  ������� ����� � ��������� ������ �� �����
		getline(cin, surname);  //  ������ �������
		cout << "Enter " << i + 1 << " tourist patronymic: \n";  //  ������� ����� � ��������� ������ �� �����
		getline(cin, patronymic);  //  ������ ��������
		a[i].name = name + " " + surname + " " + patronymic;  //  ������� ��� �������
		cout << "FIO - " + a[i].name << endl;  //  ������� ��� �������
		cout << "Input date of arriving " << i + 1 << " tourist: \n";  //  ������� ����� � ��������� ������ �� �����
		getline(cin, a[i].priezd);  //  ������ ���� �������

		fl1 = correct(a[i].priezd);  //   ��������� ���� ������� �� ������������
		if (fl1 == -1) cout << "Error input\n";  //  ���� ����� ����������� ����
		else if (fl1 == -2) cout << "Error day\n";  //  ����������� ������ ����
		else if (fl1 == -3) cout << "Error month\n";  //  ����������� ������ ����� 
		else if (fl1 == -4) cout << "Error year\n";  //  ����������� ������ ���

		cout << "Input date of leaving " << i + 1 << " tourist: \n";  //  ������� ����� � ��������� ������ �� �����
		getline(cin, a[i].otezd);  //  ������ ���� �������
		
		fl2 = correct(a[i].otezd);  //  ��������� ���� ������� �� ������������
		if (fl2 == -1) cout << "Error input\n";  //  ���� ����� ����������� ����
		else if (fl2 == -2) cout << "Error day\n";   //  ����������� ������ ����
		else if (fl2 == -3) cout << "Error month\n";  // ����������� ������ ����� 
		else if (fl2 == -4) cout << "Error year\n";  //  ����������� ������ ���

		if ((fl1 == 1) && (fl2 == 1)) {  //  ���� �� ������ ��� �������� ���, ��...
			cout << i + 1 << " tourist spend at the hotel - " << days(a[i].priezd, a[i].otezd) << " days." << endl;  //  ������� ����� � ������� ���������� ����
		}
	
	}
	return a;  //  ���������� ������ �������
}

int main() {
	int n;  //  ������� ���������� ��� ���������� �������
	Hotel* a = create(n);  //  ������� ������ �������

	return 0;
}