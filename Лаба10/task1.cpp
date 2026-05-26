#include "tasks.h"
#include <limits>


bool TTime::isValid() {
    return (h >= 0 && h < 24 &&
        m >= 0 && m < 60 &&
        s >= 0 && s < 60);
}


void TTime::input() {
    cout << "Enter time (h m s): ";

    while (true) {
        if (!(cin >> h >> m >> s)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter 3 integers: ";
        }
        else {
            break;
        }
    }
}


void TTime::convert() {
    if (!isValid()) {
        cout << "Incorrect time! Set to 00:00:00\n";
        h = m = s = 0;
        PM = false;
        return;
    }

    if (h >= 12) {
        PM = true;
        if (h > 12) h -= 12;
    }
    else {
        PM = false;
        if (h == 0) h = 12;
    }
}


void TTime::output() {
    cout << "12h format: "
        << h << ":" << m << ":" << s
        << (PM ? " PM" : " AM") << endl;
}


void task1() {
    cout << "---TASK 1 ---\n";

    TTime t;
    t.input();
    t.convert();
    t.output();
}
