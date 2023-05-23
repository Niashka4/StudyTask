//  ���� ��������� ����� �� ���������. ����� ��� �����, ����������� ������ �������������� � ������������ ������ {Xmin, Ymin}, {Xmax, Ymax}

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct point {  //  ��������� �������� �����
	double x, y;  //  ���������� �����
};

point * create(int& n) {  //  ������� �������� ������� �����
	cout << "Enter count of points: \n";  //  ������� ����� � ��������� ������ �� ����� ������
	cin >> n;  //  ������ ���������� �����
	point * a = new point[n]; //  ������� ������ �����
	for (int i = 0; i < n; i++) {  //  ������� �� ������� �����
		cout << "Input " << i + 1 << " point coordinates (x, y): \n";  //  ������� ����� � ��������� ������� �� ����� ������  
		cin >> a[i].x >> a[i].y;  //  ������ ���������� �����
	}
	return a;  //  ���������� ������ �����
}

void result(point* a, int n, double xmin, double ymin, double xmax, double ymax) {  //  ������� ��� ����������� ����� ������ ��������������
	for (int i = 0; i < n; i++) {  //  �������� �� ������� �����
		if ((a[i].x > xmin) && (a[i].x < xmax) && (a[i].y > ymin) && (a[i].y < ymax)) {  //  ���� x ���������� ����� ��������� � ������� �� xmin �� xmax � � ���������� - �� ymin �� ymax, �� ����� ��������� ������ ��������������
			cout << "This point is inside the given rectangle: { " << a[i].x << " ; " << a[i].y << " }" << endl;  //  ������� ����� � ���������� �����
		}
	}
}


int main() {
	int n;  //  ������� ���������� ��� ���������� �����
	double xmin, xmax, ymin, ymax;  //  ������� ���������� ��� ��������� ������ ��������������
	point * a = create(n);  //  ������� ������ �����
	cout << "Input two opposite points of rectangle in format {Xmin, Ymin}, {Xmax, Ymax}: \n";  // ������� ����� � ��������� ������� �� ����� ������ 
	cin >> xmin >> ymin >> xmax >> ymax;  //  ������ ���������� ���� ��������������� ������ ��������������
	if ((xmin >= xmax) && (ymin >= ymax)) cout << "Error input!";  //  ���� ��� �� ��������������� �������, ������� ������
	result(a, n, xmin, ymin, xmax, ymax);  //  ��������� ������� ��� ���������� ���������� �����
	return 0;
}