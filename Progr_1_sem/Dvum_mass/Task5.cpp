#include <iostream>
#include <cmath>  //  ���������� ���������� � ��������������� ���������
#include "Header.h"  //  ���������� ���������
using namespace std;

int main() {
	int nomer;  //  ������� ���������� ��� ������

	for (;;) {  //  ��������� ����������� ����
		cout << "Enter number of task: \n";  cin >> nomer;  //  ������� ����� � ��������� ������� �� ��������� ������ � ������ �������� ���������� ������

		if (nomer == 0) return 0;  //  ������� ������ �� �����
		if ((nomer == 4) || (nomer == 9) || (nomer == 14)) {  // ������� ���������������� ��������� ��� ��������� ������� 
			int n, m;  //  ������� ���������� ��� ���������� ����� � �������� � �������
			cout << "n = "; cin >> n;  //  ������� ����� � ������ ���������� ����� � �������
			cout << "m = "; cin >> m;  //  ������� ����� � ������ ���������� �������� � �������
			int** a = create(n, m);  //  ������� ��������� ������������ ������ ����� ���������������� �������
			cout << endl << "Initial array" << endl;  //  ������� �����
			print(a, n, m);  //  �������� ������ ����� ���������������� �������
			if (nomer == 4) {  //  ������� ��� 4 ������
				int* x = create_x(m);  //  ������� ���������� ������ ����� ���������������� �������
				swap4(a, n, m, x);  //  ������ ���� �� ������� ������� �� ������ ������ ����� ���������������� �������
			}
			if (nomer == 9) {  //  ������� ��� 9 ������
				int j_max = max9(a, n, m), j_min = min9(a, n, m);  //  ������� 2 ����������� �������� ����� ���������������� �������
				swap9(a, n, m, j_min, j_max);  //  ������ �� ������ ����� ���������������� �������
			}

			if (nomer == 14) swap14(a, n, m);  //  � 14 ������ ������ ������ ���� ��������� ����� ���������������� �������
			cout << endl << "Modified array" << endl;  //  ������� �����
			print(a, n, m);  //  �������� ������ ����� ���������������� ������� 
			delete[]a;  //  ������� ������
		}
		if (nomer == 20) {  //  ������� ��� 20 ������
			int n;  //  ������� ���������� ��� ���������� �������� � ����� � �������
			cout << "n = "; cin >> n;  //  ������� ����� � ������ �� ���������� 
			cout << "Array" << endl;  //  ������� �����
			int** a = create20(n);  //  ������� ���������� ������ � �������� ����� ���������������� �������
			print(a, n, n);  //  �������� ������ ����� ���������������� ������� 
			delete[]a;  //  ������� ������
		}
	}
	return 0;
}