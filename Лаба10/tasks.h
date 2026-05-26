#pragma once
#include <iostream>
using namespace std;

// ===== TASK 1 =====
struct TTime {
    int h, m, s;
    bool PM;

    void input();
    void convert();                                           
    void output();
    bool isValid();
};

void task1();

// ===== TASK 2 =====
struct Power {
    double A;
    double A2, A3, A5, A10, A15;

    void input();
    void calculate();   
    void output();
};

void task2();

// ===== TASK 3 =====
struct Numbers {
    int A, B, C;
    bool result;

    void input();
    void check();   
    void output();
};

void task3();
