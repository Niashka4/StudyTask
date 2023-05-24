#include <iostream>
#include <cmath>  // Подключаем модуль cmath

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << (n % 100000000) / 100000;

    return 0;
}