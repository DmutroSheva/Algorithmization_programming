#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

/* Перевірка і очищення некоректного вводу (замість повторюваних фрагментів). */
void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Завдання 1. Геометрія — варіант 15:
   
void task_geom15_count_points() {
    cout << "\n=== Завдання 1 (варіант 15): Підрахунок точок у заштрихованій області ===\n";

    // Ввести радіус r (параметр фігури)
    cout << "Введіть радіус r (r > 0): ";
    double r;
    if (!(cin >> r) || r <= 0.0) {
        clear_input();
        cout << "Помилка: r має бути додатнім числом.\n";
        return;
    }

    // Ввести кількість точок n (натуральне число)
    cout << "Введіть кількість точок n (натуральне число): ";
    int n;
    if (!(cin >> n) || n <= 0) {
        clear_input();
        cout << "Помилка: n має бути натуральним числом (>0).\n";
        return;
    }

    // Підготовка центрів кіл згідно інтерпретації
    double cxL = -r, cyL = 0.0; // центр лівого кола
    double cxR =  r, cyR = r;   // центр правого кола
    double r2 = r * r;          // квадрат радіуса для порівнянь

    int countInside = 0;        // лічильник точок, що належать заштрихованій області
    vector<int> indicesInside;  // індекси точок, що належать (для детального виводу)

    // Зчитування координат точок та перевірка належності кожної
    for (int i = 1; i <= n; ++i) {
        cout << "Точка #" << i << " — введіть x y: ";
        double x, y;
        if (!(cin >> x >> y)) {
            clear_input();
            cout << "Помилка: координати мають бути числовими. Зупинено введення.\n";
            return;
        }

        // Обчислення квадратів відстаней до центрів (без sqrt)
        double dist2L = (x - cxL) * (x - cxL) + (y - cyL) * (y - cyL);
        double dist2R = (x - cxR) * (x - cxR) + (y - cyR) * (y - cyR);

        // Перевірка належності до повного кола
        bool inLeftCircle = dist2L <= r2 + 1e-12;
        bool inRightCircle = dist2R <= r2 + 1e-12;

        // Перевірка відповідних "чвертей" (включно з межею)
        bool leftLowerQuarter  = inLeftCircle  && (x <= cxL + 1e-12) && (y <= cyL + 1e-12);
        bool rightUpperQuarter = inRightCircle && (x >= cxR - 1e-12) && (y >= cyR - 1e-12);

        if (leftLowerQuarter || rightUpperQuarter) {
            ++countInside;
            indicesInside.push_back(i);
        }
        // Для кожної точки при бажанні можна вивести проміжний результат (зараз не друкуємо)
    }

    // Вивід підсумку українською
    cout << "\nРезультат: серед " << n << " точок кількість тих, що потрапляють у заштриховану область = " << countInside << "\n";
    if (!indicesInside.empty()) {
        cout << "Номери точок, що належать області: ";
        for (size_t j = 0; j < indicesInside.size(); ++j) {
            if (j) cout << ", ";
            cout << indicesInside[j];
        }
        cout << "\n";
    }
}

//Завдання 2.
void task_sequence_sum_and_elements() {
    cout << "\n=== Завдання 2: обчислення суми та вивід кожного четвертого елемента (вар.15) ===\n";

    // Ввід x та перевірка області визначення (2 <= x <= 5)
    cout << "Введіть дійсне x (2 <= x <= 5): ";
    long double x;
    if (!(cin >> x) || x < 2.0L || x > 5.0L) {
        clear_input();
        cout << "Помилка: x має бути дійсним числом у проміжку [2, 5].\n";
        return;
    }

    // Ввід n (натуральне число)
    cout << "Введіть натуральне n (кількість членів сумування, n >= 0): ";
    int n;
    if (!(cin >> n) || n < 0) {
        clear_input();
        cout << "Помилка: n має бути цілим невід'ємним числом.\n";
        return;
    }

    // Підготовка контейнера для збереження членів послідовності
    vector<long double> a;
    a.reserve(n + 1);

    long double S = 0.0L; // сума

    // Обчислюємо члени послідовності і сумуємо
    for (int k = 0; k <= n; ++k) {
        // обчислюємо першу частину k(k+1)/x^{2k+1}
        long double denom1 = powl(x, 2LL * k + 1LL); // x^{2k+1}
        long double term1 = 0.0L;
        if (denom1 != 0.0L) term1 = (static_cast<long double>(k) * (k + 1)) / denom1;
        // друга частина: 1/x^{k+1}
        long double denom2 = powl(x, k + 1LL);
        long double term2 = 0.0L;
        if (denom2 != 0.0L) term2 = 1.0L / denom2;
        // член a_k
        long double ak = term1 - term2;
        a.push_back(ak);
        S += ak;
    }

    // Вивід результатів: сума та елементи
    cout << fixed << setprecision(10);
    cout << "\nОбчислена сума S = ";
    cout << (double)S << "\n"; // виводимо як double для сумісності з форматом

    // Виведемо всі члени a_k (для звіту може бути велика кількість — вивід контрольний)
    cout << "\nУсі члени послідовності a_k (k від 0 до " << n << "):\n";
    for (int k = 0; k <= n; ++k) {
        cout << "a[" << k << "] = " << (double)a[k] << "\n";
    }

    // Оскільки варіант 15 — непарний, виводимо кожний четвертий елемент.
    // Тут документовано: під "кожним четвертим" розуміємо ті індекси k, для яких k % 4 == 0 (k=0,4,8,...).
    cout << "\nОскільки варіант 15 — непарний, виводимо КОЖНИЙ ЧЕТВЕРТИЙ елемент (k = 0,4,8,...):\n";
    for (int k = 0; k <= n; ++k) {
        if (k % 4 == 0) {
            cout << "a[" << k << "] = " << (double)a[k] << "\n";
        }
    }
}

/* Меню запуску задач */
void print_menu() {
    cout << "\n=== Головне меню ===\n";
    cout << "1 - Завдання 1 (вар.15): підрахунок точок у заштрихованій області\n";
    cout << "2 - Завдання 2 (послідовність): обчислити суму та вивести кожний четвертий елемент\n";
    cout << "0 - Вихід\n";
    cout << "Введіть номер завдання: ";
}

int main() {
    cout << "Програма для варіанту 15 — Завдання 1 та Завдання 2\n";
    cout << "Увага: усі підказки та результати виводяться українською мовою.\n";

    while (true) {
        print_menu();
        int choice;
        if (!(cin >> choice)) {
            clear_input();
            cout << "Помилка: введіть ціле число (0..2).\n";
            continue;
        }

        switch (choice) {
            case 0:
                cout << "Завершення роботи програми. До побачення!\n";
                return 0;
            case 1:
                task_geom15_count_points();
                break;
            case 2:
                task_sequence_sum_and_elements();
                break;
            default:
                cout << "Невірний вибір. Введіть 0, 1 або 2.\n";
                break;
        }
    }

    return 0;
}