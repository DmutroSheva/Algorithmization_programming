#include <iostream>
#include <cmath>      // математичні функції
#include <iomanip>    // форматований вивід
#include <limits>

using namespace std;


// Вспоміжна функція: логарифм за основою 5
long double log_base_5(long double v) {
    return logl(v) / logl(5.0L);
}

int main()
{
    // ---------- Integer18 ----------
    cout << "Integer18." << endl;
    long long n; // вхідне ціле число
    cout << endl << "n = ";
    if (!(cin >> n)) {
        cerr << "Некоректний ввід: введіть ціле число." << endl;
        return 1;
    }
    if (n <= 999) {
        cout << "Помилка: число має бути більше за 999." << endl;
    } else {
        // одна операція цілочисельного ділення і одна операція взяття залишку
        int thousands = static_cast<int>((n / 1000) % 10);
        if (thousands < 0) thousands = -thousands; // убезпечити на випадок від'ємного
        cout << "Цифра розряду тисяч = " << thousands << endl;
    }

    // ---------- Boolean3 ----------
    cout << "\nBoolean3." << endl;
    long long A;
    cout << "A = ";
    if (!(cin >> A)) {
        cerr << "Некоректний ввід: введіть ціле число." << endl;
        return 1;
    }
    bool is_even = (A % 2 == 0);
    cout << "A є парним: " << boolalpha << is_even << noboolalpha << endl;

    // ---------- Math42 ----------
    cout << "\nMath42." << endl;
    // y = tan( |2*x^2 + 5*x| - log_5(|x - 2.5|) ) / sqrt( | sin^4(x^3) + (1/5) * log_5(|x^2 - 2.5|) | )
    long double x;
    cout << "Введіть дійсне x: ";
    if (!(cin >> x)) {
        cerr << "Некоректний ввід: введіть дійсне число." << endl;
        return 1;
    }

    const long double EPS = 1e-15L;

    // Перевірка аргументів логарифмів
    long double arg_log1 = fabsl(x - 2.5L);    // |x - 2.5|
    long double arg_log2 = fabsl(x * x - 2.5L); // |x^2 - 2.5|

    if (arg_log1 <= EPS) {
        cout << "Вираз не визначений: аргумент log_5(|x - 2.5|) повинен бути > 0 (уникайте x = 2.5)." << endl;
    } else if (arg_log2 <= EPS) {
        cout << "Вираз не визначений: аргумент log_5(|x^2 - 2.5|) повинен бути > 0 (уникайте x таких, що |x^2-2.5| = 0)." << endl;
    } else {
        // обчислення чисельника
        long double part_abs = fabsl(2.0L * x * x + 5.0L * x); // |2*x^2 + 5*x|
        long double log1 = log_base_5(arg_log1);              // log_5(|x-2.5|)
        long double numerator_arg = part_abs - log1;          // аргумент для tan

        // перевірка на випадок cos ≈ 0 => tan невизначений
        long double cos_val = cosl(numerator_arg);
        if (fabsl(cos_val) < 1e-18L) {
            cout << "Тангенс невизначений у цій точці (cos ≈ 0). Неможливо обчислити y." << endl;
        } else {
            long double tan_val = tanl(numerator_arg);

            // обчислення підкореневого виразу
            long double sin_x3 = sinl(powl(x, 3));          // sin(x^3)
            long double sin4 = powl(sin_x3, 4);             // sin^4(x^3)
            long double log2 = log_base_5(arg_log2);        // log_5(|x^2 - 2.5|)
            long double inner = sin4 + (1.0L / 5.0L) * log2; // внутрішній вираз
            long double inner_abs = fabsl(inner);           // беремо абсолютне значення підкореневого

            if (inner_abs <= EPS) {
                cout << "Підкореневий вираз занадто малий або нульовий (sqrt аргумент <= 0). Неможливо обчислити y." << endl;
            } else {
                long double denom = sqrtl(inner_abs);
                long double y = tan_val / denom;
                cout << fixed << setprecision(6);
                cout << "Результат y = " << y << endl;
            }
        }
    }

    return 0;
}