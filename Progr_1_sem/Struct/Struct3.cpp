//  ����������� ������� ��� ������ � ������������ �������: ����, ����� � �������������� � ������������������ ������, ����������� ������ � ��������� �����, ��������, ���������, ��������� � ������� ����������� �����, ���������� � �������.

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

struct complex_alg  //  ��������� �������������� ����� ������������ �����
{
    float Re;  //  �������������� �����
    float Im;  //  ������ �����
};
struct complex_trig  //  ��������� ������������������ ����� ������������ �����
{
    float Modul;  //  ������ �����
    float Argum;  //  �������� �����
};

complex_alg enter_alg() //  ���� ����� � �������������� �����
{
    complex_alg a;  //  ������� ��������� a
    cout << "Enter the real part of the number: \n";  //  ������� ����� � ��������� ������� �� ����� ������
    cin >> a.Re;  //  ������ �������������� �����
    cout << "Enter the imaginary part of a complex number: \n";  //  ������� ����� � ��������� ������� �� ����� ������
    cin >> a.Im;  //  ������ ������ �����
    return a;  //  ���������� ����������� ����� � �������������� �����
}

complex_trig enter_trig()  //  ���� ����� � ������������������ �����
{
    complex_trig a;  //  ������� ��������� a
    cout << "Enter the modul of a complex number: \n ";  //  ������� ����� � ��������� ������� �� ����� ������
    cin >> a.Modul;  //  ������ ������ �����
    cout << "Enter complex number argument: \n ";  //  ������� ����� � ��������� ������� �� ����� ������
    cin >> a.Argum;  //  ������ �������� �����
    return a;  //  ���������� ����������� ����� � ������������������ �����
}

void print_alg(complex_alg a)  //  ����� ����� � �������������� �����
{
    cout << a.Re;  //  ������� �������������� �����
    if (a.Im >= 0)  //  ���� ������ ����� ������ ��� ����� ����
        cout << " + " << a.Im << "i " << endl;  //  ������� ����� ����� � ������
    else  //  �����...
        cout << " " << a.Im << "i " << endl;  //  � �������
}

void print_trig(complex_trig a)  //  ����� ����� � ������������������ �����
{
    cout << a.Modul << " ( cos ( " << a.Argum << " ) + i * sin ( " << a.Argum << " ) ) " << endl;  //  ������� �����
}


complex_alg perevod_trig_to_alg(complex_trig a)  //  ������� ����� �� ������������������ ����� � ��������������
{
    complex_alg a_alg;  //  ������� ��������� a
    a_alg.Re = a.Modul * cos(a.Argum);  //  ������� �������������� �����
    a_alg.Im = a.Modul * sin(a.Argum);  //  ������� ������ �����
    return a_alg;  //  ���������� ����� � �������������� �����
}


complex_trig perevod_alg_to_trig(complex_alg a) {  //  ������� ����� �� �������������� ����� � ������������������

    complex_trig a_trig;  //  ������� ��������� a
    const double M_PI = 3.14;  //  ������� ��������� ��
    a_trig.Modul = sqrt(a.Re * a.Re + a.Im * a.Im);  //  ������� ������
    if (((a.Re > 0) && (a.Im > 0)) || ((a.Re > 0) && (a.Im < 0))) {  //  ���� ������� � ������ ��� ��������� ��������...
        a_trig.Argum = atan(a.Im / a.Re);  //  �� ������� �������� ���
    }
    if (((a.Re < 0) && (a.Im > 0)) || ((a.Re < 0) && (a.Im < 0))) {  //  ���� ������� �� ������ ��� ������� ��������...
        a_trig.Argum = atan(a.Im / a.Re) + M_PI;  //  �� ������� �������� ���
    }
    return a_trig;  //  ���������� ����� � ������������������ �����
}

void module_trig(complex_trig a) {  //  ���������� ������
    double module;  //  ������� ���������� ������
    module = a.Modul;  //  ������� ������
    cout << "Module of this trigonometric complex number is " << module << endl;  //  ������� ����� � ��������� ������� �� ����� ������ � ������
}

void argum_trig(complex_trig a) {  //  ���������� ���������
    double argum = a.Argum;  //  ������� ��������
    cout << "Module of this trigonometric complex number is " << argum << endl;  //  ������� ����� � ��������� ������� �� ����� ������ � ��������
}


complex_alg summa(complex_alg a, complex_alg b)  //  ������� �������� ���� ����� � �������������� �����
{
    complex_alg c;  //  ������� ��������� c
    c.Re = a.Re + b.Re;  //  ������� ����� �������������� ������
    c.Im = a.Im + b.Im;  //  ������� ����� ������ ������
    return c;  //  ���������� �����
}

complex_alg razn(complex_alg a, complex_alg b)  //  ������� ��������� ���� ����� � �������������� �����
{
    complex_alg c;  //  ������� ��������� c
    c.Re = a.Re - b.Re;  //  ������� �������� �������������� ������
    c.Im = a.Im - b.Im;  //  ������� �������� ������ ������
    return c;  //  ���������� ��������
}

complex_alg proizv(complex_alg a, complex_alg b)  //  ������� ��������� ���� ����� � �������������� �����,
{
    complex_alg c;  //  ������� ��������� c
    c.Re = a.Re * b.Re - a.Im * b.Im;  //  ������� ������������ �������������� ������
    c.Im = a.Im * b.Re + a.Re * b.Im;  //  ������� ������������ ������ ������
    return c;  //  ���������� ������������
}

complex_alg delenie(complex_alg a, complex_alg b)  //  ������� ������� ���� ����� � �������������� �����,
{
    complex_alg c;  //  ������� ��������� c
    c.Re = (a.Re * b.Re + a.Im * b.Im) / (b.Re * b.Re + b.Im * b.Im);  //  ������� ������� �������������� ������
    c.Im = (a.Im * b.Re - a.Re * b.Im) / (b.Re * b.Re + b.Im * b.Im);  //  ������� ������� ������ ������
    return c;  //  ���������� �������
}

complex_alg step(complex_alg a, int n) {  //  ������� ���������� ������������ ����� � �������������� ����� � �������
    complex_alg c;  //  ������� ��������� c � �������������� �����
    complex_trig c_trig;  //  ������� ��������� c � �������������� �����
    float p = 1; 
    c_trig = perevod_alg_to_trig(a); //  ������� ����� � ������������������ �����.
    for (int i = 1; i <= n; p *= c_trig.Modul, i++);  //  ��������� ���� �� ��������
    c.Re = p * cos(n * c_trig.Argum);  //  ������� �������������� �����
    c.Im = p * sin(n * c_trig.Argum);  //  ������� ������ �����
    return c;  //  ���������� ���������� �����
}

int main()
{
    int choose = 1, fl = 0, n = 0, fl2 = 0;  
    complex_alg a_alg, a2_alg, c_alg; complex_trig a_trig, a2_trig, c_trig;

    while (choose != 0) {
        cout << "Enter 1 to input algebraic complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
        cout << "Enter 2 to input trigonometic complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
        cin >> choose;  //  ������ ��������
        if (choose == 1) {
            fl = 1;
            a_alg = enter_alg();  //  ������ �������������� ����� �����
            a_trig = perevod_alg_to_trig(a_alg);  //  ������� ������������������ �����
        }
        if (choose == 2) {
            fl = 2;
            a_trig = enter_trig();  //  ������ ������������������ �����
            a_alg = perevod_trig_to_alg(a_trig);  //  ������� �������������� �����
        }
        cout << "Enter 1 to print complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
        cout << "Enter 2 to raise to a power complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
        cout << "Enter 3 to conversion to another form complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
        cout << "Enter 4 to input another complex \n";  //  ������� ����� � ��������� ������� �� ����� ������
        cin >> choose;  //  ������ ��������
        if ((choose == 1) && (fl == 1)) print_alg(a_alg);  //  ���� ����� �������������� �����, �� ������� ��
        else if ((choose == 1) && (fl == 2)) print_trig(a_trig);  //  ���� ����� ������������������ �����, �� ������� ��
        else if (choose == 2) { cout << "Enter degree: "; cin >> n; a_alg = step(a_alg, n); print_alg(a_alg); a_trig = perevod_alg_to_trig(a_alg); print_trig(a_trig); }  //  �������� ����� � ������� n � ������� ��� ��� �����
        else if ((choose == 3) && (fl == 1)) print_trig(a_trig); //  ��������� ����� � ��������������� �����
        else if ((choose == 3) && (fl == 2)) print_alg(a_alg); //  ��������� ����� � ��������������� �����
        else if (choose == 4) {
            cout << "Enter 1 to input algebraic complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
            cout << "Enter 2 to input trigonometic complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
            cin >> choose;  //  ������ ��������
            if (choose == 1) {
                fl2 = 1;
                a2_alg = enter_alg();  //  ������ �������������� ����� �����
                a2_trig = perevod_alg_to_trig(a2_alg);  //  ������� ������������������ �����
            }
            else if (choose == 2) {
                fl2 = 2;
                a2_trig = enter_trig();  //  ������ ������������������ �����
                a2_alg = perevod_trig_to_alg(a2_trig);  //  ������� �������������� �����
            }
            cout << "Enter 1 to find a summ of complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
            cout << "Enter 2 to find a difference of complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
            cout << "Enter 3 to find a product of complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
            cout << "Enter 4 to find a quotient of complex number \n";  //  ������� ����� � ��������� ������� �� ����� ������
            cin >> choose;  //  ������ ��������
            if (choose == 1) {
                c_alg = summa(a_alg, a2_alg);  //  ������� �����
                c_trig = perevod_alg_to_trig(c_alg);  // ��������� �� � ������������������ �����
                print_alg(c_alg);  //  ������� ����� � �������������� �����
                print_trig(c_trig);  // ������� ����� � ������������������ ����� 
            }
            else if (choose == 2) {
                c_alg = razn(a_alg, a2_alg);  //  ������� ��������
                c_trig = perevod_alg_to_trig(c_alg);  // ��������� �� � ������������������ �����
                print_alg(c_alg);  //  ������� �������� � �������������� �����
                print_trig(c_trig);   // ������� �������� � ������������������ ����� 
            }
            else if (choose == 3) {
                c_alg = proizv(a_alg, a2_alg);  //  ������� ������������
                c_trig = perevod_alg_to_trig(c_alg);  // ��������� �� � ������������������ �����
                print_alg(c_alg);  //  ������� ������������ � �������������� �����
                print_trig(c_trig);   // ������� ������������ � ������������������ ����� 
            }
            else if (choose == 4) {
                c_alg = delenie(a_alg, a2_alg);  //  ������� �������
                c_trig = perevod_alg_to_trig(c_alg);  // ��������� �� � ������������������ �����
                print_alg(c_alg);  //  ������� ������� � �������������� �����
                print_trig(c_trig);   // ������� ������� � ������������������ ����� 
            }
        }
    }
    return 0;
}