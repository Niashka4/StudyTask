#include <iostream>
#include <cmath>  //  ���������� ���������� � ��������������� ���������
using namespace std;

template < typename X>
X** create(X c, int n, int m) {  //  ��������
	X** a = new X * [n]; //  ��������� ������
	for (int i = 0; i < n; i++)  //  �������� �� �����
		a[i] = new X[m];  //  ������� �������
	for (int i = 0; i < n; i++) //  ���� �������
		for (int j = 0; j < m; j++)  //  �������� �� �������
			cin >> a[i][j];  //  ������ ������� �������
	return a;  //  ������� ������
}

template < typename X>
void print(X** a, int n, int m) { //  ������
	for (int i = 0; i < n; i++, cout << endl)  //  �������� �� �����
		for (int j = 0; j < m; j++)  //  �������� �� �������
			cout << a[i][j] << " ";  //  ������� ������� �������
}

template < typename X>
X** change10(X** a, int n, int m, X* x) {  //  ������
	X min = a[0][0];  // ����������� ��������� �������� ������������ �������� 
	for (int i = 0; i < n; i++)  //  �������� �� �����
		for (int j = 0; j < m; j++)  //  �������� �� ��������
			if (a[i][j] < min) min = a[i][j];  //  ������� ����������� �������
	for (int j = 0; j < m; j++)  //  �������� �� ��������
		for (int i = 0; i < n; i++)  //  �������� �� �����
			if (a[i][j] == min) {  //  ���� ������ ����������� �������
				for (int i1 = 0; i1 < n; i1++) // �������� �� ����� ������ 
					a[i1][j] = x[i1];  //  ������ ������
				i = 0;  //  �������� ���������� ������� � ����
			}
	return a;  //  ���������� ���������� ������
}

template < typename X>
X* create_x(X c, int n) {  //  ��������
	X* x = new X[n]; //  ��������� ������
	for (int i = 0; i < n; i++)  //  ���������� �� ��������� �������
		cin >> x[i];  //  ������ ������� �������
	return x;  //  ���������� ���������� ������
}


int main() {
	char g;  //  ������� ���������� ��� ���������� �������
	int n = 0, m = 0;  //  ������� ���������� ��� ������� �������
	cout << "Input dimension\n";  //  ������� �����
	cin >> n >> m;  //  ������ ������� �������
	do {
		cout << "Enter type:\n1 - int\n2 - double\n3 - float\n";  //  ������� �����
		int k;  // ������� ���������� ��� ����
		cin >> k;  //  ������ ���
		switch (k) {  //  �������� ��������� ����
		case 1: {  //  ��� Int
			int c = 1;  //  Int ����������
			int** a = create(c, n, m);  //  ������� ��������� ������
			cout << "INT:\n";  //  ������� �����
			print(a, n, m);  //  ������� ������
			int* x = create_x(c, n);  //  ������� ���������� ������
			a = change10(a, n, m, x);  //  ���������� ������
			cout << "New:\n";  //  ������� �����
			print(a, n, m);  //  ������� ���������� ������
			break;  
		}
		case 2: {  //  ��� Double
			double c1 = 1;  //  Double ����������
			double** a1 = create(c1, n, m);  //  ������� ��������� ������
			cout << "DOUBLE:\n";  //  ������� �����
			print(a1, n, m);  //  ������� ������
			double *x1 = create_x(c1, n);  //  ������� ���������� ������
			a1 = change10(a1, n, m, x1);  //  ���������� ������
			cout << "New:\n";  //  ������� �����
			print(a1, n, m);  //  ������� ���������� ������
			break;
		}
		case 3: {  //  ��� Float
			float c3 = 1;  //  Float ����������
			float** a3 = create(c3, n, m);  //  ������� ��������� ������
			cout << "FLOAT:\n";  //  ������� �����
			print(a3, n, m);  //  ������� ������
			float *x3 = create_x(c3, n);  //  ������� ���������� ������
			a3 = change10(a3, n, m, x3);   //  ���������� ������
			cout << "New:\n";  //  ������� �����
			print(a3, n, m);  //  ������� ���������� ������
			break;
		}
		default: cout << "Error! \n";  //  ���� ������ ������� �������
		}
		cout << "Again? Y - yes, N - no\n";  //  ������� �����
		cin >> g; // ��������� ������ ��������� ���� �� ������ N
	} while (g != 'N');
	return 0;
}