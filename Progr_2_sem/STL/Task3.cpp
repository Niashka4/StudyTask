#include <list>  // ���������� ����������� ���������� 
#include <numeric>  
#include <algorithm>
#include <iostream>

using namespace std;

bool odd(int x) {  //  ������� ��� ����������� ������� ��������
    return x % 2 == 0;  
}

bool nodd(int x) {  //  ������� ��� ����������� ��������� ��������
    return x % 2 != 0;
}

int main()
{
    int x, n, m;  
    cout << "Enter length of first posledovatelnosti: "; cin >> n; cout << endl;  //  ������� ����� � ��������� �� ����� ������, ������ ������ ������ ������������������
    list<int> lis1;  // ������� ������ ������
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";  
        cin >> x;  //  ������ �������
        lis1.push_back(x);  //  ��������� ��� � ����� ������
    }

    for (list<int>::iterator iter = lis1.begin(); iter != lis1.end(); iter++) 
        cout << *iter << " ";  //  ������� ������� ������
    cout << endl;  

    cout << "Enter length of second posledovatelnosti: "; cin >> m; cout << endl;  //  ������� ����� � ��������� �� ����� ������, ������ ������ ������ ������������������
    list<int> lis2;  //  ������� ������ ������
    for (int i = 0; i < m; i++) {  
        cout << "a[" << i << "] = ";  
        cin >> x;  //  ������ �������
        lis2.push_back(x);  //  ��������� ��� � ����� ������
    }

    for (list<int>::iterator iter = lis2.begin(); iter != lis2.end(); iter++)  
        cout << *iter << " ";  //  ������� ������� ������
    cout << endl;  

    cout << "Delete chetnie elements and sort in first posledovatelnost:" << endl;  //  ������� ����� � ��������� �� ����� ������
    list<int> tlis1(lis1);  //  �������� ������
    tlis1.remove_if(odd);  //  ������� ������ ��������
    tlis1.sort(); tlis1.unique();  //  ��������� ������ � ������� ���������
    
    for (list<int>::iterator iter = tlis1.begin(); iter != tlis1.end(); iter++)  
        cout << *iter << " ";  //  ������� ������� ������
    cout << endl;  

    cout << "Delete nechetnie elements and sort in second posledovatelnost:" << endl;  //  ������� ����� � ��������� �� ����� ������
    list<int> tlis2(lis2);  //  �������� ������
    tlis2.remove_if(nodd);  //  ������� �������� ��������
    tlis2.sort(); tlis2.unique();  //  ��������� ������ � ������� ���������

    for (list<int>::iterator iter = tlis2.begin(); iter != tlis2.end(); iter++)  
        cout << *iter << " ";  //  ������� ������� ������
    cout << endl;  

    cout << "The combined resulting sequence:" << endl;  //  ������� ����� � ��������� �� ����� ������
    tlis1.merge(tlis2);  //  ���������� ��� ������
    tlis1.sort(); tlis1.unique();  //  ��������� ������ � ������� ���������

    for (list<int>::iterator iter = tlis1.begin(); iter != tlis1.end(); iter++)    
        cout << *iter << " ";  //  ������� ������� ������
    cout << endl; 

    return 0;
}