#include "tasks.h"
#include <limits>
#include <cmath>

void Power::input() {
    cout << "Enter A: ";

    while (true) {
        if (!(cin >> A)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter number: ";
        }
        else if (abs(A) > 1000) {  
            cout << "Too large number! Enter |A| <= 1000: ";
        }
        else {
            break;
        }
    }
}

void Power::calculate() {
    A2 = A * A;
    A3 = A2 * A;
    A5 = A3 * A2;
    A10 = A5 * A5;
    A15 = A10 * A5;
}

void Power::output() {
    cout << "A^2 = " << A2 << endl;
    cout << "A^3 = " << A3 << endl;
    cout << "A^5 = " << A5 << endl;
    cout << "A^10 = " << A10 << endl;
    cout << "A^15 = " << A15 << endl;
}

void task2() {
    cout << "\n--- Task 2 ---\n";

    Power p;
    p.input();
    p.calculate();
    p.output();
}
