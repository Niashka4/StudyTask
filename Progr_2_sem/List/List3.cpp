#include <iostream>  //  Подключаем нужные библиотеки

using namespace std;

struct list {  //  Структура списка
    int inf;  //  Значение ячейки
    list* next;  //  Ссылка на следующий элемент
    list* prev;  //  Ссылка на предыдущий элемент
};

void push(list*& h, list*& t, int x) {  //  Функция добавления элемента в конец списка
    list* r = new list;  //  Создаём новую ячейку
    r->inf = x;  //  Её значение 
    r->next = NULL;  //  Следующий элемент пуст
    if (!h && !t) {  //  Если список пуст, то...
        r->prev = NULL;  //  Предыдущая ячейка пуста
        h = r;  //  Значение головы
    }
    else {  //  Иначе
        t->next = r;  //  Следующее после головы - новый элемент  
        r->prev = t;  //  Предыдущее для нового элемента - хвост
    }
    t = r;  //  Хвост теперь - это новый элемент
}

void print(list* h, list* t) {  //  Функция вывода списка
    list* p = h;  //  Создаём указатель на голову
    while (p) {  //  Пока указатель не пуст
        cout << p->inf << " ";  //  Выводим значение указателя
        p = p->next;  //  Двигаем указатель дальше
    }
}

void bubbleSort(list*& h, list *&t) {  //  Функция сортировки списка пузырьком по указателям
    list* current = NULL;  //  Инициализируем текущий элемент...
    list *next = NULL;  //  следующий...
    list* prev = NULL;  //  и предыдущий
    bool flag = true;  //  Флаг об обмене элементов
    while (flag) {  //  Пока флаг true...
        flag = false;  //  Присваиваем flag как false
        current = h;  //  Текущий элемент - это голова

        while (current->next != NULL) {  //  Пока мы не дойдём до конца списка
            next = current->next;  //  Создаём ссылку на следующий элемент

            if (current->inf > next->inf) {  //  Если следующий элемент меньше текущего
                if (current == h) {  //  Если текущий - голова
                    h = next;  //  То двигаем голову дальше
                    next->prev = NULL;  //  До головы - пусто
                }
                else {  //  Иначе
                    prev->next = next;  //  Меняем местами указатели
                    next->prev = prev;
                }

                current->next = next->next;  //  Сдвигаем указатели

                if (next->next != NULL)  //  Если следующий-следующий не пуст
                    next->next->prev = current;  //  Меняем связи

                next->next = current;  
                current->prev = next;   

                prev = next;  //  Меняем ссылку на предыдущий
                next = current->next;  //  и следующий элементы

                flag = true;  //  Продолжаем выполнять сортировку
            }
            else {  //  Иначе
                prev = current;  //  Делаем шаг назад
                current = current->next;  //  Переопределяем текущий, предыдущий и...
                next = current->next;  //  следующий элемент
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");  //  Подключаем русский язык
    int n, el = 0;  //  Создаём необходимые переменные
    list* head = NULL;  //  Инициализируем голову
    list* tail = NULL;  //  Инициализируем хвост
    cout << "Введите количество чисел: "; cin >> n;  //  Вводим количество чисел
    for (int i = 0; i < n; i++) {  //  Проходим циклом от 0 до n
        cin >> el;  //  Вводим число
        push(head, tail, el);  //  Добавляем в список элемент
    }
    bubbleSort(head, tail);  //  Сортируем список
    print(head, tail);  //  Печатаем список
    return 0;
}



