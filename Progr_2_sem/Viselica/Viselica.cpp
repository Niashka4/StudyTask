#include <vector>  // Подключаем необходимые библиотеки 
#include <cstdlib>
#include <time.h>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));
    vector<char> alf = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};  //  Создаём вектор для алфавита
    int n, help, count = 0, flag = 0, guess = 0, attemp = 0;  //  Создаём нужные переменные
    cout << "Enter length of word: "; cin >> n;  //  Выводим текст и вводим количество букв в слове
    cout << "Enter the maximum number of attempts: "; cin >> attemp; cout << endl;  //  Выводим текст и вводим максимальное число попыток
    vector<char> slovo;  //  Создаем вектор для загаданного слова
    for (int i = 0; i < n; i++) {
        slovo.push_back(alf[rand() % 25]);  //  Генерируем буквы слова
    }
    vector<char> game;  //  Создаем вектор из отгаданных букв
    for (int i = 0; i < n; i++) {
        game.push_back('_');  //  Заполняем этот вектор чёрточками
    }

    vector<char> helping;  //  Создаём вспомогательный вектор
    
    for (int i = 0; i < n; i++) cout << slovo[i];

    while (flag == 0) {  //  Выполняем пока флаг равен нулю
        cout << "Guess the word!" << endl;  //  Выводим текст
        for (int i = 0; i < n; i++) {
            cout << game[i] << " ";  //  Выводим отгаданные буквы
        }
        cout << endl;

        cout << "Alphabet: " << endl;  //  Выводим текст
        for (int i = 0; i < 26; i++) cout << alf[i] << " ";  //  Выводим все буквы и зачёркиваем отгаданные
        cout << endl;

        cout << "Attemp: " << count << endl;  //  Выводим текст

        cout << "Press 1 if you want to enter a letter, or 2 if you want to guess the whole word: " << endl; cin >> help;  //  Выводим текст и вводим действие
        if (help == 1) {  //  Отгадываем букву
            int fl = 0;  
            char letter;  //  Переменная для буквы  
            cout << "Enter a letter: "; cin >> letter;  //  Выводим текст и вводим букву
            for (int i = 0; i < n; i++)  
                if (slovo[i] == letter) {  //  Если в загаданном слове есть данная буква, то...
                    cout << "You guessed the letter!" << endl;  //  Выводим текст
                    game[i] = letter;  //  Заменяем чёрточку на букву
                    guess++;  //  Увеличиваем количество отгаданных букв
                    replace(alf.begin(), alf.end(), letter, '/');  //  Перечёркиваем отгаданную букву в алфавите
                    fl = 1;  //  Мы отгадали букву

                }
                if (fl == 0) cout << "You did not guess the letter!" << endl;  //  Если буква не отгадана, то выводим текст 
           
        }
        if (help == 2) {  //  Отгадываем слово целиком
            char let;  //  Переменная для буквы
            cout << "Spell the whole word:" << endl;  //  Выводим текст
            for (int i = 0; i < n; i++) {  
                cin >> let;  //  Вводим слово целиком по буквам
                helping.push_back(let);  //  Добавляем букву во вспомогательный вектор
            }
            if (helping == slovo) {  //  Если вспомогательный вектор равен вектору, загаданного слова, то...
                cout << "Well done! You guessed the word!" << endl; flag = 1;  //  Выводим текст с победой
            }
            else cout << "Oh, no... You did not guess the word(" << endl;  //  Если не отгадали, то текст с проигрышем
        }

        if (guess == n) {  //  Если количество отгаданных букв равно количеству букв в загаданном слове, то...
            cout << "Well done! You guessed the word!" << endl;  //  Выводим текст с победой
            for (int i = 0; i < n; i++) cout << slovo[i];  //  Выводим загаданное слово целиком
            flag = 1;  //  Мы победили
        } 
        count++;  //  Увеличиваем количество попыток
        helping.clear();  //  Очищаем вспомогательный вектор
        if (count > attemp) { flag = 1; cout << endl << "You did not guess the word( Try another word!" << endl; for (int i = 0; i < n; i++) cout << slovo[i]; }  //  Если мы сделали больше попыток, чем максимальное количество, то мы проиграли, выводим текст и всё загаданное слово
        cout << endl; 
    }
    return 0;
}