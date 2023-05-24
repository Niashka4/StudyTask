#include <vector>  // ���������� ����������� ���������� 
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

int a, b;  //  ������� ���������� ���������� ��� ������ �������

bool odd(int x) {  // ������� ����������� ��������� �� ������� � �������
    return (x >= a) && (x <= b);
}

int main()
{
    int x, n;
    cout << "Enter A and B: "; cin >> a >> b; cout << endl;  //  ������� ����� � ��������� �� ����� ������, ������ ����� �������
    cout << "Enter length: "; cin >> n; cout << endl;  //  ������� ����� � ��������� �� ����� ������, ������ ������ ������������������
    vector<int> vec;  // ������� ������
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> x;  //  ������ �������
        vec.push_back(x);  //  ��������� ��� � ����� �������
    }

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";  //  ������� ������� �������
    cout << endl;

    cout << "Replace elements in [a,b]:" << endl;  //  ������� ����� � ��������� �� ����� ������
    vector<int> temp(vec);  //  �������� ������
    replace_if(temp.begin(), temp.end(), odd, 0);  //  ���� ������� ��������� ������ �������, ������ ��� �������� �� ����

    for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
        cout << *iter << " ";  //  ������� ������� �������
    cout << endl;

    cout << "Summa of elements = " << accumulate(temp.begin(), temp.end(), 0) << endl;  //  ������� ����� � ��������� �� ����� ������, ������� ����� ������ ��������� �������




    return 0;
}