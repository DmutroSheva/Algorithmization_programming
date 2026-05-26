#include "matrix_utils.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_M = 100;
const int MAX_N = 100;

void task2_matrix(const string filename) {
    ifstream fin(filename);
    ofstream fout("matrix_out.txt"); 

    int m, n;
    fin >> m >> n;

    double matrix[MAX_M][MAX_N];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fin >> matrix[i][j];

    int halfM = m / 2, halfN = n / 2;

    for (int i = 0; i < halfM; i++)
        for (int j = 0; j < halfN; j++)
            swap(matrix[i][j], matrix[i + halfM][j + halfN]);

    fout << "Matrix after swap:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            fout << matrix[i][j] << "\t";
        fout << "\n";
    }

    cout << "Task 2 completed. Check matrix_out.txt\n";

    fin.close();
    fout.close();
}
