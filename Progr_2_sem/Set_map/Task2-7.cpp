#include <map>  //  ���������� ������ ����������
#include <set>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string str_tolower(string text) {  //  �������, ������������� ����� � ������ �������
	for (int i = 0; i < text.length(); i++)  //  ���������� �� ���� ��������� ������
		text[i] = tolower(text[i]);  //  ����������� ������� ������ � ������ �������
	return text;  //  ���������� �����
}

set <string> words(string text) {  //  �������, ��������� ��� �� ���� ����������� 
	set <string> predl;  //  ������� ��� �� �����������
	if (text[text.length() - 1] != ' ')  //  ���� ��������� ������� ������ �� ����� ����, ��...
		text += " ";  //  ��������� � ����� ������
	while (text != "") {  //  ���� �� �� ������ �� ����� ������...
		predl.insert(str_tolower(text.substr(0, text.find(' '))));  //  ��������� � ��� ���� �� ����������� ��������� �� 0 �� ���������� �������
		text.erase(0, text.find(' ') + 1);  //  ������� ��� ���������
	}
	return predl;  //  ���������� ���� ���
}
int main() {  
	setlocale(LC_ALL, "RUS");  //  ���������� ������� ����
	string text, predl;  //  ������ ������ ��� ������ � �����������
	cout << "������� �����: ";  //  ������� �����
	getline(cin, text);  //  ������ �����
	set <string> result, povest, voskl, vopr, help;  //  ������ ��� ����������� ����
	while (text != "") {  //  ���� �� ����� �� ����� ������...
		int pos = text.find_first_of(".!?");  //  ������� ����� ������� �����, ��������������� ��� ���������������� �����
		predl = text.substr(0, pos);  //  ������� �����������
		help = words(predl);  //  �������� ��� �� ��� �����������
		if (text[pos] == '.') povest.insert(help.begin(), help.end());  //  ���� � ����� ����������� �����, ��������� ����� � ��� � ����������������� ������������
		if (text[pos] == '!') voskl.insert(help.begin(), help.end());  //  ���� � ����� ����������� ��������������� ����, ��������� ����� � ��� � ��������������� ������������
		if (text[pos] == '?') vopr.insert(help.begin(), help.end());  //  ���� � ����� ����������� �������������� ����, ��������� ����� � ��� � �������������� ������������
		text.erase(0, pos + 2);  //  ������� �� �����������
	}
	cout << "����� �� ����������������� �����������: ";  //  ������� �����
	for (set <string> ::iterator it = povest.begin(); it != povest.end(); it++)  //  �������� �� ���� � ����������������� �������
		cout << *it << " ";  //  ������� �����
	cout << endl;
	cout << "����� �� ��������������� �����������: ";  //  ������� �����
	for (set <string> ::iterator it = voskl.begin(); it != voskl.end(); it++)  //  �������� �� ���� � ���������������� �������
		cout << *it << " ";  //  ������� �����
	cout << endl;
	cout << "����� �� �������������� �����������: ";  //  ������� �����
	for (set <string> ::iterator it = vopr.begin(); it != vopr.end(); it++)  //  �������� �� ���� � ��������������� �������
		cout << *it << " ";  //  ������� �����
	cout << endl;
	set_difference(voskl.begin(), voskl.end(), povest.begin(), povest.end(), inserter(result,
		result.begin()));  //  ������� ��������� ����� �� ���������������� � ������������������ ����
	set <string> result1;  //  ������ ��������������� ��� 
	set_difference(vopr.begin(), vopr.end(), povest.begin(), povest.end(), inserter(result1,
		result1.begin()));  //  ������� ��������� ����� �� ��������������� � ������������������ ����
	for (set<string>::iterator it = result1.begin(); it != result1.end(); it++) result.insert(*it);  //  ���������� ��� �������������� ����
	cout << "�����, ������� ����������� ������ � �������������� � ��������������� ������������: ";  //  ������� �����
	for (set <string> ::iterator i = result.begin(); i != result.end(); i++)  //  ���������� �� ���� ������ ��������������� ����
		cout << *i << " ";  //  ������� ��
	cout << endl;
	cout << "����� ����������: " << result.size();  //  ������� ����� � ���������� ����
	return 0;
}

/* Cat is animal? It is pet! I know. It is my favourite pet. Wow! */
