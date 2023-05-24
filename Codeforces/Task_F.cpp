
#include <iostream>
#include <cmath>  // Подключаем модуль cmath
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 28) cout << "2";
    else if ((n >= 29) && (n <= 52)) cout << "3";
    else if ((n >= 53) && (n <= 77)) cout << "4";
    else cout << "5";
    return 0;
}