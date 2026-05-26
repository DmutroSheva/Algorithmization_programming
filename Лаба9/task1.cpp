#include "task1.h"
#include <iostream>
#include <string>

using namespace std;


size_t my_rfind(const char str[], char c) {
    int last = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            last = i;
    }

    return last;
}

// task 1
void run_task1() {
    char arr[1000];
    string str;
    char ch;

    cout << "\n--- Task 1 (rfind) ---\n";

    cout << "Enter string: ";
    cin.getline(arr, 1000);

    str = arr;

    cout << "Enter character: ";
    cin >> ch;
    cin.ignore();

    size_t pos_std = str.rfind(ch);
    int pos_my = my_rfind(arr, ch);

    cout << "\nResult:\n";

    if (pos_std != string::npos)
        cout << "string::rfind: " << pos_std << endl;
    else
        cout << "string::rfind: not found\n";

    if (pos_my != -1)
        cout << "my_rfind: " << pos_my << endl;
    else
        cout << "my_rfind: not found\n";
}
