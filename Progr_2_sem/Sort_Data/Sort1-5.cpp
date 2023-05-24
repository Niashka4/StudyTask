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
	if (a.Staje < b.Staje) return true;  //  ���� ���� ������� ������ �������, �� ���������� ������
	return false;  //  ����� ����
}

void bucketSort(vector<people>& x) {  //  ������� ������� ���������� ������� �����
	int max_staje = 0;  
	for (auto& i : x) {  //  ���������� �� ���� �����
		if (i.Staje > max_staje) {
			max_staje = i.Staje;  // ������� ������������ �������� �����
		}
	}

	int bucket_size = max_staje / 5 + 1;  //  ������� ������ ������ �����
	vector <vector <people> > buckets(bucket_size);  // ������� ����� � ��������� �� ����������
	for (auto& i : x) {  //  ���������� �� ���� �����
		int bucket_id = i.Staje / 5;  //  ������� ����� ����� � ������� �������� ��������
		buckets[bucket_id].push_back(i);  //  ���������� � ���� ���� ��������
	}

	for (auto& bucket : buckets) {  //  ���������� �� ���� ������
		sort(bucket.begin(), bucket.end(), [](const people& p1, const people& p2) {	 //  ��������� ������ ����
			return p1.Staje < p2.Staje;  //  �� ������ ���� �� �����������
			});
	}

	int number = 0;  
	for (auto& bucket : buckets) {  //  �������� �� ���� ������
		for (auto& i : bucket) {  //  �������� �� ������� �������� � �����
			x[number++] = i;  	//  �������� �������� � �������� ������ � ������� ����������� �����
		}
	}
}

int main() {
	vector <people> x;  //  ������� ������ �� �����	
	x = inFile();  //  ������ ���� ����� �� ����� ����� ���������������� �������
	cout << " \n" << endl;
	
	bucketSort(x);  //  ��������� ������� �����������

	for (auto& i : x)  //  ���������� �� ������ ���� �����
		print(i);  //  ������� ��������������� ������ � ���� ����� ������� ����������
	return 0;
}

