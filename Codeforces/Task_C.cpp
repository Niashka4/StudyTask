#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main() {
    int a, b, k, s;
    cin >> a >> b >> k;
    s = (a / k) * (b / k);
    cout << s;

    return 0;
}