#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

/*
  proc20_integer37.cpp
  Реалізація двох задач:
   - Proc20: процедура TrapezoidArea(a,b,h,S) та обчислення трьох площ трапецій;
   - Integer37: скільки квадратних плиток зі стороною C вміститься у прямокутник A x B і яка частина залишиться незаповненою.
  Усі повідомлення виводяться українською мовою.
*/

/* Допоміжна функція: чекати Enter перед поверненням в меню/завершенням */
void pause_enter() {
    cout << "\nНатисніть Enter для продовження...";
    cin.clear(); // скидаємо можливі помилки потоку
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/* Процедура Proc20:
   TrapezoidArea(a, b, h, S) — обчислює площу трапеції S = (a + b) * h / 2.
   Параметри:
     a, b, h  - вхідні дійсні (double)
     S        - вихідний параметр по посиланню (double &)
*/
void TrapezoidArea(double a, double b, double h, double &S) {
    // Обчислення згідно формули
    S = (a + b) * h / 2.0;
}

/* Завдання Proc20 — процедура-обгортка для взаємодії з користувачем */
void task_proc20_trapezoids() {
    cout << "\n=== Завдання Proc20: площі трьох трапецій ===\n";

    // Повторити три рази: зчитати a,b,h, перевірити, викликати TrapezoidArea і вивести S.
    for (int i = 1; i <= 3; ++i) {
        cout << "\nТрапеція №" << i << " — введіть основи a, b та висоту h (через пробіл): ";
        double a, b, h;
        if (!(cin >> a >> b >> h)) {
            // Якщо ввід некоректний — скидаємо стан потоку і повертаємося
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка: введено некоректні дані. Потрібні дійсні числа.\n";
            return;
        }
        // Перевірка додатності (основи можуть бути додатні, висота обов'язково додатна)
        if (a <= 0.0 || b <= 0.0 || h <= 0.0) {
            cout << "Помилка: a, b та h мають бути додатними числами.\n";
            return;
        }
        // Виклик процедури для обчислення площі
        double S = 0.0;
        TrapezoidArea(a, b, h, S); // виклик процедури (S повертається по посиланню)
        // Вивід результату українською
        cout << fixed << setprecision(6);
        cout << "Площа трапеції №" << i << " S = " << S << " (одиниці площі)\n";
    }
}

/* Завдання Integer37:
   Дано прямокутник розміром A x B і плитку розміром C x C.
   Знайти:
     - count: максимальну кількість плиток, що вмістяться при регулярній укладці (ряд/стовпець),
     - fraction: частину площі прямокутника, що залишиться незаповненою (у відсотках/долі).
*/
void task_integer37_tiles() {
    cout << "\n=== Завдання Integer37: укладання плиток ===\n";
    cout << "Введіть довжину A, ширину B прямокутника та сторону плитки C (через пробіл): ";

    double A, B, C;
    if (!(cin >> A >> B >> C)) {
        // Некоректний ввід
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Помилка: введено некоректні дані. Потрібні дійсні числа.\n";
        return;
    }

    // Перевірка додатності розмірів
    if (A <= 0.0 || B <= 0.0 || C <= 0.0) {
        cout << "Помилка: A, B та C мають бути додатними числами.\n";
        return;
    }

    // Обчислення, скільки плиток вміщується по довжині і по ширині (цілі кількості)
    long long tilesAlongA = static_cast<long long>(floor(A / C)); // кількість плиток у напрямку A
    long long tilesAlongB = static_cast<long long>(floor(B / C)); // кількість плиток у напрямку B

    // Загальна кількість плиток при регулярній укладці (прямокутна решітка)
    long long count = tilesAlongA * tilesAlongB;

    // Обчислення зайнятої площі плитками та незаповненої частини
    double totalArea = A * B;                        // площа прямокутника
    double tilesArea = static_cast<double>(count) * C * C; // площа, зайнята плитками
    double remainingArea = totalArea - tilesArea;    // що залишилося незаповненою

    // Врахувати можливі невеликі від'ємні значення через чисельні похибки
    if (remainingArea < 0.0 && remainingArea > -1e-12) remainingArea = 0.0;

    // Частина незаповненої площі від загальної (в долях)
    double fraction = remainingArea / totalArea; // в діапазоні [0,1]

    // Вивід результатів українською
    cout << fixed << setprecision(0);
    cout << "Максимальна кількість плиток, що вміститься (регулярна укладка): " << count << "\n";
    cout << "Кількість плиток по довжині: " << tilesAlongA << ", по ширині: " << tilesAlongB << "\n";
    cout << fixed << setprecision(6);
    cout << "Площа прямокутника = " << totalArea << "\n";
    cout << "Площа, зайнята плитками = " << tilesArea << "\n";
    cout << "Незаповнена площа = " << remainingArea << "\n";
    cout << "Частина незаповненої площі від загальної = " << fraction << " (тобто " << (fraction * 100.0) << "%)\n";
}

/* Меню вибору задач */
void print_menu() {
    cout << "\n=== Меню завдань ===\n";
    cout << "1 - Proc20: площі трьох трапецій (використовуючи TrapezoidArea)\n";
    cout << "2 - Integer37: укладання плиток та частина незаповненої площі\n";
    cout << "0 - Вихід\n";
    cout << "Введіть номер завдання: ";
}

int main() {
    cout << "Програма: Proc20 та Integer37. Усі повідомлення українською.\n";

    while (true) {
        print_menu();
        int choice;
        if (!(cin >> choice)) {
            // Якщо введено не число — скидаємо стан потоку і просимо повторити
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка: введіть ціле число (0,1 або 2).\n";
            continue;
        }
        // Очищаємо залишок рядка для коректної роботи pause
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 0:
                cout << "Завершення роботи програми. До побачення!\n";
                return 0;
            case 1:
                task_proc20_trapezoids();
                pause_enter();
                break;
            case 2:
                task_integer37_tiles();
                pause_enter();
                break;
            default:
                cout << "Невірний вибір. Оберіть 0, 1 або 2.\n";
                break;
        }
    }

    return 0;
}