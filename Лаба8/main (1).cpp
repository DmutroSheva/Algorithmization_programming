#include <iostream>
#include "array_utils.h"
#include "matrix_utils.h"

using namespace std;

int main() {
    int choice;
    string filename;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Array analysis\n";
        cout << "2 - Matrix processing\n";
        cout << "3 - Bubble sort array\n";
        cout << "0 - Exit\n";
        cout << "Choose task: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter input file for array: ";
            cin >> filename;
            task1_array(filename);
            break;
        case 2:
            cout << "Enter input file for matrix: ";
            cin >> filename;
            task2_matrix(filename);
            break;
        case 3:
            cout << "Enter input file for array: ";
            cin >> filename;
            task3_bubble_sort(filename);
            break;
        case 0:
            cout << "Bye!\n";
            break;
        default:
            cout << "Wrong choice\n";
        }

    } while (choice != 0);

    return 0;
}
