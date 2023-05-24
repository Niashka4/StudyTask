#include <iostream>
#include <cmath>  // Подключаем модуль cmath
#include <iomanip>

using namespace std;

int main() {
    int t;
    long long px, py, qx, qy;
    double f;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> px >> py;
        cin >> qx >> qy;
        f = sqrt((qx - px) * (qx - px) + (qy - py) * (qy - py));
        cout << fixed << setprecision(15) << f << endl;
    }
    return 0;
}
