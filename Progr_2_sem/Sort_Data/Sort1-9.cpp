#include <iostream>  //  ���������� ������ ����������
#include <fstream>
#include <string>
#include <vector> 
#include <iomanip>
#include <algorithm>

using namespace std;

ifstream in("C:/Users/savelevdv/Downloads/Sort/info.txt");  //  ��������� ����
ofstream out("C:/Users/savelevdv/Downloads/Sort/out.txt");  //  ������� ������ � ������ ����

struct date {  //  ������� ��������� ����
	int dd, mm, yy;  
};

struct people {  //  ��������� ��������
	string Name;  // �������
	string Doljnost;  //  ���������
	date DataRojdeniya{};  //  ���� ��������
	int Staje{};  //  ����
	int Zarplata{};  //  ��������
};

date Str_to_Date(const string& str) {  //  ��������� ���� �� ������ � ���������
	date x{};  //  ������� ��������� ����
	string temp;  
	temp = str.substr(0, 2);  //  �������� ����
	x.dd = atoi(temp.c_str());  //  ��������� � Int
	temp = str.substr(3, 2);  //  �������� �����
	x.mm = atoi(temp.c_str());  //  ��������� � Int
	temp = str.substr(6, 4);  // �������� ���
	x.yy = atoi(temp.c_str());  //  ��������� � Int
	return x;  //  ���������� ����
}

vector<people> inFile() {  //  ������� ����� �� �����
	vector<people> x;  //  ������� ������ �����
	people temp; 
	while (in.peek() != EOF) {  //  ���� �� ����� �� ����� �����
		in >> temp.Name;  //  �������� ���
		in >> temp.Doljnost;  //  �������� ���������
		string tmp;  
		in >> tmp;  //  �������� ���� ��������
		temp.DataRojdeniya = Str_to_Date(tmp);  //  ��������� ������ � ����
		in >> temp.Staje;  //  �������� ���� ������
		in >> temp.Zarplata;  //  �������� ��������
		x.push_back(temp);  //  ������� �������� � ������ �����
	}
	return x;  //  ���������� ���� ������
}

void print(const people& x) {  //  ����� � ����
	out << setw(21) << left << x.Name;  //  ������ ������ ��� �����
	out << setw(24) << left << x.Doljnost;  //  ������ ������ ��� ���������
	if (x.DataRojdeniya.dd < 10) out << left << '0' << x.DataRojdeniya.dd << '.';  //  ��������� 0
	else out << left << x.DataRojdeniya.dd << '.';  //  ������ �� ���������
	if (x.DataRojdeniya.mm < 10) out << '0' << x.DataRojdeniya.mm << '.';  //  ��������� 0
	else out << x.DataRojdeniya.mm << '.';  //  ������ �� ���������
	out << left << setw(6) << x.DataRojdeniya.yy;  //  ������ ������ ��� ����
	out << left << setw(5) << x.Staje;  //  ������ ������ ��� �����
	out << left << setw(8) << x.Zarplata << endl;  //  ������ ������ ��� ��������
}

bool operator < (const people& a, const people& b) {  //  �������������� �������� < � ����������� � ��������
	if (a.DataRojdeniya.yy < b.DataRojdeniya.yy) return true;  //  ��������� �� ���� ��������
	if ((a.DataRojdeniya.yy == b.DataRojdeniya.yy) && (a.Staje < b. Staje)) return true;  //  ���� ��� ���� � ��� ��, ��������� �� �����
	return false;  //  ����� ����
}

void comb_sort(vector<people>& pip) {  //  ������� ���������� ���������
	int gap = pip.size();  //  ���������� gap ����� ������� �������
	while (gap != 1) {  //  ���� gap �� ����� 1 - ���������
		gap = gap / 1.247;  //  ����� ������ gap �� ������������� �������� 1.247
		if (gap < 1) gap = 1;  //  ���� gap ���� ������ 1, �� ��������������� ��� ��� 1, ����� ��������� ����
		for (int i = 0; i < pip.size() - gap; i++) {  //  ���������� �� ������� �������� �� ������� ������� ����� gap
			if (pip[i + gap] < pip[i]) {  //  ���� ��� �������� ����� �� �� �����������, ��...
				swap(pip[i + gap], pip[i]);  //  ������ �� �������
			}
		}
	}
}

int main() {
	vector <people> x;  //  ������� ������ �� �����	
	x = inFile();  //  ������ ���� ����� �� ����� ����� ���������������� �������
	cout << " \n" << endl;
	
	comb_sort(x);  //  ��������� ���������

	for (auto& i : x)  //  ���������� �� ������ ���� �����
		print(i);  //  ������� ��������������� ������ � ���� ����� ���������� ���������
	return 0;
}

