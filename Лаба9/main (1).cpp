#include <iostream>
#include "task1.h"
#include "task2.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Task 1 (rfind)\n";
        cout << "2 - Task 2 (string file)\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            run_task1();
            break;
        case 2:
            run_task2();
            break;
        case 0:
            cout << "Bye!\n";
            break;
        default:
            cout << "Wrong choice!\n";
        }

    } while (choice != 0);

    return 0;
}
