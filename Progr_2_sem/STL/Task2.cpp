#include <vector>  // ���������� ����������� ����������
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

int X;  //  ������� ���������� ���������� ��� �����

bool krat(int x) {  //  ������� ����������� ������ �� ������� �����
    return x % X != 0;
}

bool odd(int x) {  //  ������� ����������� �������� �����
    return x % 2 == 0;
}

int main()
{
    int x, n;
    cout << "Enter X: "; cin >> X; cout << endl;  //  ������� ����� � ��������� �� ����� ������, ������ ����� X
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

    cout << "Replace elements ne kratnie X:" << endl;  //  ������� ����� � ��������� �� ����� ������
    vector<int> temp(vec);  //  �������� ������
    replace_if(temp.begin(), temp.end(), krat, 0);  //  ���� ������� ������ X, �������� ��� �� 0

    for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
        cout << *iter << " ";  //  ������� ������� �������
    cout << endl;


    cout << "Summa of elements kratnih X = " << accumulate(temp.begin(), temp.end(), 0) << endl;  //  ������� ����� � ��������� �� ����� ������, ������� ����� ������ ���������

    vector<int>::iterator iter = min_element(vec.begin(), vec.end());  //  ���� ����������� �������

    cout << "Minimal element = " << *iter << endl;  //  ������� ����� � ��������� �� ����� ������, ������� ����������� �������

    vector<int> last(vec);  //  �������� ������
    vector<int>::iterator iteri = max_element(vec.begin(), vec.end());  //  ���� ������������ �������
    cout << "Replace chetnie elements to max element: " << endl;  //  ������� ����� � ��������� �� ����� ������
    replace_if(last.begin(), last.end(), odd, *iteri);  //  ���� ������� ������, �������� ��� �� ������������ �������

    for (vector<int>::iterator it = last.begin(); it != last.end(); it++)
        cout << *it << " ";  //  ������� ������� �������
    cout << endl;

    return 0;
}