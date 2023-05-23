#pragma once
using namespace std;

int progressive(int n, int a1, int znam, int i) {  //  ������� ��� �������������� ����������
	int an = a1;  //  ������ ��������
	if (n == 1) return a1;  //  ���� ���� ������ ����
	if (i == n) return an;  //  ���� �� ����� �� ������� ��������
	if (i < n) return progressive(n, an * znam, znam, i + 1);  //  ���� �� ������� �������� � ���������
}

int kubish(int x, int n) {  //  ������� �������� ��������
	if (n == 0) return 1;  //  ������ ��������
	else if (n == 1) return 2 * x - 1;  //  ������
	else return 2 * (2 * x - 1) * kubish(x, n - 1) - kubish(x, n - 2);  // ���������� ��� ��������� n
}

double drob(int i, int n) {  //  ������� ������ �����
	if (i == n) return (n - 1)/((n - 1) + n);  //  ������� ��� ���������� � �������
	if (i < n) return i / (i + drob(i + 1, n));  //  ������� ��� ���������� � ����������� ��������
}

void print(int n, char a) {  //  ������� ������ ��������
	for (int i = 0; i < n; i++)  //  ��������� ����
		cout << a;  //  �������� ������
}

void func(int p, int n) {  //  ������� ��� �������
	if (n >= 1) {  //  ������� ������ �������
		print(p, ' ');  //  �������� �������
		print(n, '*');  //  �������� ���������
		cout << endl;  //  ������� �� ����� ������
		func(p + 1, n - 2);  //  �������� ��������� �������
	}
}