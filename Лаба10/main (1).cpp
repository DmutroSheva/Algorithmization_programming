#include "tasks.h"

int main() {
    int choice;

    do {
        cout << "\nMENU:\n";
        cout << "1 - Task 1 (Time)\n";
        cout << "2 - Task 2 (Power)\n";
        cout << "3 - Task 3 (Numbers)\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: cout << "Exit...\n"; break;
        default: cout << "Wrong choice!\n";
        }

    } while (choice != 0);

    return 0;
}
