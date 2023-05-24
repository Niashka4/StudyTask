#include <vector>  // ���������� ����������� ���������� 
#include <cstdlib>
#include <time.h>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));
    vector<char> alf = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};  //  ������ ������ ��� ��������
    int n, help, count = 0, flag = 0, guess = 0, attemp = 0;  //  ������ ������ ����������
    cout << "Enter length of word: "; cin >> n;  //  ������� ����� � ������ ���������� ���� � �����
    cout << "Enter the maximum number of attempts: "; cin >> attemp; cout << endl;  //  ������� ����� � ������ ������������ ����� �������
    vector<char> slovo;  //  ������� ������ ��� ����������� �����
    for (int i = 0; i < n; i++) {
        slovo.push_back(alf[rand() % 25]);  //  ���������� ����� �����
    }
    vector<char> game;  //  ������� ������ �� ���������� ����
    for (int i = 0; i < n; i++) {
        game.push_back('_');  //  ��������� ���� ������ ����������
    }

    vector<char> helping;  //  ������ ��������������� ������
    
    for (int i = 0; i < n; i++) cout << slovo[i];

    while (flag == 0) {  //  ��������� ���� ���� ����� ����
        cout << "Guess the word!" << endl;  //  ������� �����
        for (int i = 0; i < n; i++) {
            cout << game[i] << " ";  //  ������� ���������� �����
        }
        cout << endl;

        cout << "Alphabet: " << endl;  //  ������� �����
        for (int i = 0; i < 26; i++) cout << alf[i] << " ";  //  ������� ��� ����� � ����������� ����������
        cout << endl;

        cout << "Attemp: " << count << endl;  //  ������� �����

        cout << "Press 1 if you want to enter a letter, or 2 if you want to guess the whole word: " << endl; cin >> help;  //  ������� ����� � ������ ��������
        if (help == 1) {  //  ���������� �����
            int fl = 0;  
            char letter;  //  ���������� ��� �����  
            cout << "Enter a letter: "; cin >> letter;  //  ������� ����� � ������ �����
            for (int i = 0; i < n; i++)  
                if (slovo[i] == letter) {  //  ���� � ���������� ����� ���� ������ �����, ��...
                    cout << "You guessed the letter!" << endl;  //  ������� �����
                    game[i] = letter;  //  �������� �������� �� �����
                    guess++;  //  ����������� ���������� ���������� ����
                    replace(alf.begin(), alf.end(), letter, '/');  //  ������������� ���������� ����� � ��������
                    fl = 1;  //  �� �������� �����

                }
                if (fl == 0) cout << "You did not guess the letter!" << endl;  //  ���� ����� �� ��������, �� ������� ����� 
           
        }
        if (help == 2) {  //  ���������� ����� �������
            char let;  //  ���������� ��� �����
            cout << "Spell the whole word:" << endl;  //  ������� �����
            for (int i = 0; i < n; i++) {  
                cin >> let;  //  ������ ����� ������� �� ������
                helping.push_back(let);  //  ��������� ����� �� ��������������� ������
            }
            if (helping == slovo) {  //  ���� ��������������� ������ ����� �������, ����������� �����, ��...
                cout << "Well done! You guessed the word!" << endl; flag = 1;  //  ������� ����� � �������
            }
            else cout << "Oh, no... You did not guess the word(" << endl;  //  ���� �� ��������, �� ����� � ����������
        }

        if (guess == n) {  //  ���� ���������� ���������� ���� ����� ���������� ���� � ���������� �����, ��...
            cout << "Well done! You guessed the word!" << endl;  //  ������� ����� � �������
            for (int i = 0; i < n; i++) cout << slovo[i];  //  ������� ���������� ����� �������
            flag = 1;  //  �� ��������
        } 
        count++;  //  ����������� ���������� �������
        helping.clear();  //  ������� ��������������� ������
        if (count > attemp) { flag = 1; cout << endl << "You did not guess the word( Try another word!" << endl; for (int i = 0; i < n; i++) cout << slovo[i]; }  //  ���� �� ������� ������ �������, ��� ������������ ����������, �� �� ���������, ������� ����� � �� ���������� �����
        cout << endl; 
    }
    return 0;
}