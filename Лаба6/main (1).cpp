#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

const int MAX = 100;


// перевірка ЧИСЕЛ
int input_positive_int(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error! Enter integer number > 0!" << endl;
        }
        else {
            return value;
        }
    }
}

int input_int(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error! Enter integer number!" << endl;
        }
        else {
            return value;
        }
    }
}

// ВВЕДЕННЯ МАСИВУ 
void input_array(int arr[MAX], int& n) {
    n = input_positive_int("Enter array size: ");

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> arr[i];

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error! Enter integer value: ";
            cin >> arr[i];
        }
    }
}

// ВИВЕДЕННЯ МАСИВУ 
void output_array(const int arr[MAX], const int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// ОБРОБКА МАСИВУ task1
void analyze_array(const int arr[MAX], const int n) {
    cout << "Even elements in reverse index order: ";

    int countEven = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
            countEven++;
        }
    }

    cout << endl;
    cout << "Number of even elements: " << countEven << endl;
}



void transform_array(int arr[MAX], int& n) {
    

    for (int i = 1; i < n; i++) {
        for (int j = i; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        n--;
        i--;
    }
}


// task 1 
void task1() {
    int arr[MAX];
    int n;

    cout << "\nTASK 1: Array analysis and output\n";

    input_array(arr, n);                                               // Введення
    output_array(arr, n);                                              // Виведення

    analyze_array(arr, n);                                             // Аналіз
}

//task 2
void task2() {
    int arr[MAX];
    int n;

    cout << "\nTASK 2: Array transformation\n";

    input_array(arr, n);                                    // Введення

    cout << "Original ";
    output_array(arr, n);

    transform_array(arr, n);                                // Перетворення

    cout << "Modified ";
    output_array(arr, n);
}


//Меню
int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Array analysis\n";
        cout << "2 - Array transformation\n";
        cout << "0 - Exit\n";

        choice = input_int("Choose task: ");

        if (choice == 1) task1();
        else if (choice == 2) task2();

        system("pause");
        system("cls");

    } while (choice != 0);

    return 0;
}
