#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main() {
    int p, k;
    cin >> p >> k;
    cout << (p / (2 * (1 + k))) * (p / (2 * (1 + k))) * k;

    return 0;
}