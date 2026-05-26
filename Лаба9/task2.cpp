#include "task2.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Перевірка: тільки великі латинські букви і пробіли
bool is_valid_string(string str) {
    if (str.empty()) return false;

    for (int i = 0; i < str.size(); i++) {
        if (!(str[i] == ' ' || (str[i] >= 'A' && str[i] <= 'Z')))
            return false;
    }
    return true;
}

// Підрахунок слів
int count_words(string str) {
    int count = 0;
    int i = 0;

    while (i < str.size()) {
        while (i < str.size() && str[i] == ' ')
            i++;

        if (i >= str.size()) break;

        int start = i;

        while (i < str.size() && str[i] != ' ')
            i++;

        int end = i - 1;

        if (str[start] == str[end])
            count++;
    }

    return count;
}

// task 2
void run_task2() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    cout << "\n--- Task 2 (file processing) ---\n";

    if (!fin) {
        cout << "Error opening file!\n";
        return;
    }

    string line;

    while (getline(fin, line)) {
        if (!is_valid_string(line)) {
            fout << "Wrong string: " << line << endl;
            continue;
        }

        int result = count_words(line);

        fout << "Line: " << line << endl;
        fout << "Count: " << result << endl << endl;
    }

    cout << "Done. Check output.txt\n";
}
