#include <iostream>
#include <iostream>  //  Подключаем нужные библиотеки
#include <fstream>
#include <cmath>
#include <queue>

using namespace std;

ifstream in("input.txt");  //  Подключаем файл

struct tree {  //  Структура дерева
    int inf;  //  Значение узла
    tree* right;  //  Ссылка на правый элемент
    tree* left;  //  Ссылка на левый элемент
};

tree* node(int x) {  //  Создание узла
    tree* n = new tree;  //  Новый элемент дерева
    n->inf = x;  //  Значение узла
    n->left = n->right = NULL;  //  Левый и правый элемент изначально пусты
    return n;  //  Возвращаем узел
}

void create(tree*& tr, int n) {  //  Функцмя создания дерева
    int x;
    if (n > 0) {  //  Если количество элементов больше нуля
        in >> x;  //  Получаем элемент
        tr = node(x);  //  Создаём узел
        int nl = n / 2;  //  Количество элементов в левом поддереве
        int nr = n - nl - 1;  //  Количество элементов в правом поддереве
        create(tr->left, nl);  //  Созда1м левое и правое поддерево
        create(tr->right, nr);
    }
}

void preorder(tree* tr) {  //  прямой обход (К-Л-П)
    if (tr) {
        cout << tr->inf << " ";  //  корень
        preorder(tr->left);  //  левое
        preorder(tr->right);  //  правое
    }
}

int levels(tree* tr, int k, int l) {  //  Функция вывода суммы элементов на k уровне
    int res;  //  Инициализируем переменную res
    if (tr) {  //  Если есть корень
        if (k == l) res = tr->inf;  //  Если нам нужно найти сумму на 0 уровне, то это значение корня
        else if (k > l) res = levels(tr->left, k, l + 1) + levels(tr->right, k, l + 1);  //  Иначе, если нам нужен уровень выше, то это сумма на левом и правом поддереве
        else res = 0;  //  Иначе сумма равна нулю
    }
    else res = 0;  //  Если корня нет, то сумма 0
    return res;  //  Возвращаем res
}

void print(tree* tr, int k) {  //  Функция вывода дерева на экран
    if (!tr) cout << "Empty tree\n";  //  Если нет элементов, то дерево пусто
    else {  //  Иначе
        queue<tree*> cur, next;  //  Создаём две очереди
        tree* r = tr;  //  Создаём ссылку на корень
        cur.push(r);  //  Добавляем корень в cur
        int j = 0;  //  Присваиваем j к нулю
        while (cur.size()) {  //  Пока cur не пуст
            if (j == 0) {  //  Если j = 0
                for (int i = 0; i < (int)pow(2.0, k) - 1; i++)  //  Идем циклом до 2 в степени k
                    cout << ' ';  //  Выводим пробел
            }
            tree* buf = cur.front();  //  Создаём ссылку на элемент
            cur.pop();  //  Удаляем этот элемент из очереди
            j++;  //  Увеличиваем счетчик
            if (buf) {  //  Если buf пуст
                cout << buf->inf;  //  Выводим значение buf
                next.push(buf->left);  //  Заполняем очередь по левому поддереву
                next.push(buf->right);  //  Заполняем очередь по правому поддереву
                for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)  //  Идем циклом до 2 в степени k
                    cout << ' ';  //  Выводим пробел
            }
            if (!buf) {  //  Если buf пуст
                for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)  //  Идем циклом до 2 в степени k
                    cout << ' ';  //  Выводим пробел
                cout << ' ';  //  Выводим пробел
            }
            if (cur.empty()) {  //  Если cur пуст
                cout << endl;  //  Выводим отступ
                swap(cur, next);  //  Меняем cur и next
                j = 0;  //  Обнуляем j
                k--;  //  Уменьшаем k
            }
        }
    }
}

int main() {
    tree* tr = NULL;  //  Изначально ссылка на голову пуста
    int n, s;
    setlocale(LC_ALL, "RUS");
    cout << "Введите уровень: "; cin >> s;  //  Получаем уровень
    in >> n;  //  Получаем количество элементов
    create(tr, n);  //  Создаем дерево
    int k = int(log((float)n) / log((float)2.0));
    print(tr, k);  //  Вывод дерева
    preorder(tr);  //  Прямой обход
    cout << endl;
    cout << "Сумма элементов на конкретном уровне:" << endl;
    cout << levels(tr, s, 0);  //  Ответ на задание
    return 0;
}