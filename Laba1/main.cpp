#include <iostream>
using namespace std;

int main() {
    // Константа π
    const double PI = 3.14;

    // Змінна для кута в градусах
    double alphaDegrees;
    cout << "Введіть кут у градусах (0 <= α < 360): ";
    cin >> alphaDegrees;

    // Переведення у радіани
    double alphaRadians = alphaDegrees * PI / 180.0;

    // Вивід результату
    cout << "Кут у радіанах: " << alphaRadians << endl;

    return 0;
}