#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main() {
    int x, y, b, a;
    cin >> x >> y;
    if (x > y) { b = 7 - x + y; a = x - y; }
    else {
        b = 7 - y + x; a = y - x;
    }
    if (a > b) cout << b << " " << a;
    else cout << a << " " << b;
    return 0;
}