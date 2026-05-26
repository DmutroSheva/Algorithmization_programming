#include "array_utils.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1000;

// Завдання 1
void task1_array(const string filename) {
    ifstream fin(filename);
    ofstream fout("array_out.txt"); 

    int n;
    fin >> n;

    double arr[MAX_SIZE];

    for (int i = 0; i < n; i++)
        fin >> arr[i];

    fout << "Even elements in reverse: ";
    int countEven = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (int(arr[i]) % 2 == 0) {
            fout << arr[i] << " ";
            countEven++;
        }
    }

    fout << "\nNumber of even elements: " << countEven << "\n";

    cout << "Task 1 completed. Check array_out.txt\n";

    fin.close();
    fout.close();
}

// Завдання 3
void task3_bubble_sort(const string filename) {
    ifstream fin(filename);
    ofstream fout("array_out.txt"); 

    int n;
    fin >> n;

    double arr[MAX_SIZE];

    for (int i = 0; i < n; i++)
        fin >> arr[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }

    fout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        fout << arr[i] << " ";

    fout << "\n";

    cout << "Task 3 completed. Check array_out.txt\n";

    fin.close();
    fout.close();
}
