#include <iostream>

using namespace std;

struct tree {  //  Структура дерева
    int inf;  //  Значение узла
    tree* left;  //  Ссылка на левый элемент
    tree* right;  //  Ссылка на правый элемент
    tree* parent;  //  Ссылка на родителя
};

tree* node(int x) {  //  Создание узла
    tree* n = new tree;  //  Новый элемент дерева
    n->inf = x;  //  Значение узла
    n->parent = NULL;  //  Родитель, левый и правый элемент изначально пусты
    n->right = NULL;
    n->left = NULL;
    return n;  //  Возвращаем узел
}

void preorder(tree* tr) { // прямой обход (К-Л-П)
    if (tr) {
        cout << tr->inf; //корень
        preorder(tr->left); //левое
        preorder(tr->right); //правое
    }
}

void postorder(tree* tr) { // обратный обход (Л-П-К)
    if (tr) {
        postorder(tr->left); //левое
        postorder(tr->right); //правое
        cout << tr->inf; //корень
    }
}

void inorder(tree* tr) { // симметричный обход (Л-К-П)
    if (tr) {
        inorder(tr->left); //левое
        cout << tr->inf << " "; //корень
        inorder(tr->right); //правое
    }
}

void insert(tree*& tr, int x) {//вставка
    tree* n = node(x); //  Новый узел
    if (!tr) tr = n; //если дерево пустое - корень
    else {
        tree* y = tr;  //  Создаём ссылку на корень
        while (y) { //  ищем куда вставлять
            if (n->inf > y->inf) //  правая ветка
                if (y->right)  //  Если есть правый ребёнок
                    y = y->right;  //  Идём по правому поддереву
                else {
                    n->parent = y; //узел становится правым ребенком
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf)  //левая ветка
                if (y->left)  //  Если есть левый ребёнок
                    y = y->left;  //  Идём по левому поддереву
                else {
                    n->parent = y;  //узел становится левым ребенком
                    y->left = n;
                    break;
                }
        }
    }
}

tree* find(tree* tr, int x) {//поиск
    if (!tr || x == tr->inf)//нашли или дошли до конца ветки
        return tr;
    if (x < tr->inf)
        return find(tr->left, x);//ищем по левой ветке
    else
        return find(tr->right, x);//ищем по правой ветке
}

tree* Min(tree* tr) {//поиск min
    if (!tr->left) return tr;//нет левого ребенка
    else return Min(tr->left);//идем по левой ветке до конца
}

tree* Max(tree* tr) {//поиск max
    if (!tr->right) return tr;//нет правого ребенка
    else return Max(tr->right);//идем по правой ветке до конца
}

tree* Next(tree* tr, int x) {//поиск следующего
    tree* n = find(tr, x);
    if (n->right)//если есть правый ребенок
        return Min(n->right);//min по правой ветке
    tree* y = n->parent; //родитель
    while (y && n == y->right) {//пока не дошли до корня или узел - правый ребенок
        n = y;//идем вверх по дереву
        y = y->parent;
    }
    return y;//возвращаем родителя
}

void Delete(tree*& tr, tree* v) {  //  удаление узла
    tree* p = v->parent;  //  Находим родителя нужного узла
    if (!p && !v->left && !v->right) tr = NULL; //дерево содержит один узел
    else if (!v->left && !v->right) {//если нет детей
        if (p->left == v) //указатель у родителя меняем на NULL
            p->left = NULL;
        if (p->right == v)
            p->right = NULL;
        delete v;
    }
    else if (!v->left || !v->right) {//если только один ребенок
        if (!p) { //если удаляем корень, у которого 1 ребенок
            if (!v->left) { //если есть правый ребенок
                tr = tr->right; //он становится корнем
            }
            else { //аналогично для левого
                tr = tr->left;
            }
            if (tr) { //если новый корень не равен NULL, то убеждаемся, что у него нет родителя
                tr->parent = NULL;
            }
        }
        else {
            if (!v->left) {//если есть правый ребенок
                if (p->left == v) //если удаляемый узел явл. левым ребенком
                    p->left = v->right; //ребенок удаляемого узла становится левым ребенком своего "деда"
                else
                    p->right = v->right; ////ребенок удаляемого узла становится правым ребенком своего "деда"
                v->right->parent = p; //родителем ребенка становится его "дед"
            }
            else {//аналогично для левого ребенка
                if (p->left == v)
                    p->left = v->left;
                else
                    p->right = v->left;
                v->left->parent = p;
            }
            delete v;
        }
    }
    else {//есть оба ребенка
        tree* succ = Next(tr, v->inf);//следующий за удаляемым узлом
        v->inf = succ->inf; //присваиваем значение
        if (succ->parent->left == succ) {//если succ левый ребенок
            succ->parent->left = succ->right; //его правый ребенок становится левым ребенком своего "деда"
            if (succ->right) //если этот ребенок существует
                succ->right->parent = succ->parent; //его родителем становится "дед"
        }
        else {//аналогично если succ - правый ребенок
            succ->parent->right = succ->right;
            if (succ->right)
                succ->right->parent = succ->parent;
        }
        delete succ;
    }
}

int node_depth(tree* v)  //  Определение глубины узла
{
    int k = -1;  //  Счётчик 
    while (v != NULL)  //  Пока указатель не пуст
    {
        v = v->parent; k++;  //  Получаем родителя v и увеличиваем счетчик
    }
    return k;  //  Возвращаем глубину узла
}

int leaves_to_root(tree* tr) { // Определяем выcоту дерева
    static int max = 0;  //  Переменная для максимального количества
    if (tr) {  //  Идём по всему дереву
        leaves_to_root(tr->left); //  Левое поддерево
        leaves_to_root(tr->right); //  Правое поддерево
        if (!tr->left && !tr->right && node_depth(tr) > max)  max = node_depth(tr);  //  Если мы дошли до листа, находим максимальную его глубину
    }
    return max;  //  Возвращаем это значение
}

int main(){
    setlocale(LC_ALL, "RUS");
    int n, x;
    cout << "n = "; cin >> n;
    tree* tr = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(tr, x);
    }
    inorder(tr);  cout << endl;
    cout << "Высота дерева: ";
    cout << leaves_to_root(tr);
    cout << endl;

    return 0;
}