#include <map>  //  ���������� ������ ����������
#include <set>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n, x, x1, x2, count = 0;  //  ������ ����������� ����������
    cout << "Enter count of numbers: ";  //  ������� �����
    cin >> n;  //  ������ ���������� �����
    multimap<int, int> a;  //  ������� ��������� ��� ���� �����, ��� ���� - ��� ���������� ���� � �����
    set <int> b, c, d, f;  //  ������� ������ ����
    for (int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "] = "; cin >> x;  //  ������� ����� � ������ ����� 
        x1 = x;  //  ��������������� �����
        while (x1 > 0) { x2 = x1 % 10; x1 /= 10; count++; b.insert(x2); }  //  ��������� � ��� b �����, ��������� �����
        a.insert(make_pair(count, x));  //  ��������� � ���������, �������� �����
        for (set<int>::iterator it = b.begin(); it != b.end(); it++) {  //  �������� �� ��������� ���� b
            if (count == 3) d.insert(*it); else c.insert(*it);  //  ���� ����� ���������� - ��������� ��� � ��� d, ����� � ��� c
        }
        count = 0;  //  �������� ���������� ����
        b.clear();  //  ������� ��� b
    }

    cout << "Digits in not three digits: " << endl;  //  ������� �����
    for (set<int>::iterator iter = c.begin(); iter != c.end(); iter++)
        cout << *iter << " ";  //  ������� ����� �� � ���������� ������
    cout << endl;

    cout << "Digits in three digits: " << endl;  //  ������� �����
    for (set<int>::iterator iti = d.begin(); iti != d.end(); iti++)
        cout << *iti << " ";  //  ������� ����� �� ���������� �����
    cout << endl;

    for (set<int>::iterator iteri = c.begin(); iteri != c.end(); iteri++) {
        if (d.find(*iteri) == d.end()) f.insert(*iteri);  //  ���� ����� �� ���� c ��� � ���� d, �� ��������� � � ��� f
    }
    cout << "All numbers that are not occur in three - digit numbers: " << endl;  //  ������� �����
    for (set<int>::iterator ito = f.begin(); ito != f.end(); ito++)
        cout << *ito << " ";  //  ������� ������������ �����
    cout << endl;

    return 0;
}