#include "tasks.h"
#include <limits>

void Numbers::input() {
    cout << "Enter A, B, C: ";

    while (true) {
        if (!(cin >> A >> B >> C)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter 3 integers: ";
        }
        else if (A < -100000 || A > 100000 ||
            B < -100000 || B > 100000 ||
            C < -100000 || C > 100000) {

            cout << "Numbers too large! Enter values in [-100000, 100000]: ";
        }
        else {
            break;
        }
    }
}

void Numbers::check() {
    result = (A > 0 || B > 0 || C > 0);
}

void Numbers::output() {
    if (result)
        cout << "TRUE: at least one number is positive\n";
    else
        cout << "FALSE: no positive numbers\n";
}

void task3() {
    cout << "\n--- Task 3 ---\n";

    Numbers n;
    n.input();
    n.check();
    n.output();
}
