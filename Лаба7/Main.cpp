#include <iostream>
using namespace std;


const int MAX = 50;

//Введення матриці
void inputMatrix(int a[MAX][MAX], int& m, int& n)
{
    // ПЕРЕВІРКА коректності розмірів
   
    do {
        cout << "Rows (2-50): ";
        cin >> m;
        cout << "Cols (2-50): ";
        cin >> n;
    } while (m < 2 || m > MAX || n < 2 || n > MAX);

    // Введення елементів по рядках
    
    cout << "Enter elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}

// Виведення матриці

void printMatrix(const int a[MAX][MAX], int m, int n)
{
    cout << "\nMatrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";                     // табуляція для рівного вигляду
        cout << endl;
    }
}

//  ПЕРЕВІРКА: стовпець зростає
// true  — якщо кожен наступний елемент >= попереднього, false — якщо порядок порушено

bool isAscending(const int a[MAX][MAX], int m, int col)
{
    for (int i = 1; i < m; i++)
        if (a[i][col] < a[i - 1][col])
            return false;
    return true;
}

//  ПЕРЕВІРКА: СТОВПЕЦЬ СПАДАЄ 
// true  — якщо кожен наступний елемент <= попереднього, false — якщо порядок порушено

bool isDescending(const int a[MAX][MAX], int m, int col)
{
    for (int i = 1; i < m; i++)
        if (a[i][col] > a[i - 1][col])
            return false;
    return true;
}

// ЗАВДАННЯ 1 
// Знайти максимальний елемент серед стовпців, які впорядковані за зростанням або спаданням

int findMaxInOrderedCols(const int a[MAX][MAX], int m, int n)
{
    bool found = false;                                         // чи знайдено хоч один підходящий стовпець
    int maxVal = a[0][0];                                        // майбутній максимум

    
    for (int j = 0; j < n; j++) {

        // Якщо стовпець впорядкований
        if (isAscending(a, m, j) || isDescending(a, m, j)) {

            
            for (int i = 0; i < m; i++) {
                if (!found || a[i][j] > maxVal) {
                    maxVal = a[i][j];
                    found = true;
                }
            }
        }
    }

    // Якщо впорядкованих стовпців не було
    if (!found) return 0;

    return maxVal;
}

// Завдання 2 
// Поміняти місцями: ліву верхню чверть, праву нижню чверть

void swapQuarters(int a[MAX][MAX], int m, int n)
{
    int halfM = m / 2;                              // половина рядків
    int halfN = n / 2;                              // половина стовпців

    
    for (int i = 0; i < halfM; i++)
        for (int j = 0; j < halfN; j++)
            swap(a[i][j], a[i + halfM][j + halfN]);
}

// Укладка завдання 1 

void task1()
{
    int a[MAX][MAX], m, n;                          // матриця та її реальні розміри

    inputMatrix(a, m, n);                           // введення
    printMatrix(a, m, n);                           // виведення

    int result = findMaxInOrderedCols(a, m, n); // обробка
    cout << "\nResult: " << result << endl;
}

// Укладка завдання 2 

void task2()
{
    int a[MAX][MAX], m, n;

  
    do {
        cout << "Rows (even): ";
        cin >> m;
        cout << "Cols (even): ";
        cin >> n;
    } while (m < 2 || m > MAX || n < 2 || n > MAX || m % 2 != 0 || n % 2 != 0);

    // Ввід елементів
    
    cout << "Enter elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "\nBefore:\n";
    printMatrix(a, m, n);

    swapQuarters(a, m, n);                              // перетворення

    cout << "\nAfter:\n";
    printMatrix(a, m, n);
}

// Menu
int main()
{
    int choice;

    
    do {
        cout << "====MENU====\n";
        cout << "\n1 - Task 1 (Ordered columns)\n";
        cout << "2 - Task 2 (Swap quarters)\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 0: cout << "Bye!\n"; break;
        default: cout << "Wrong choice\n";
        }
    } while (choice != 0);

    return 0;
}
