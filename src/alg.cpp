// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double value1 = value;
    if (n == 0) {
        return 1;
    }
    for (; n > 1; --n) {
        value *= value1;
    }
    return value;
}

uint64_t fact(uint16_t n) {
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    uint16_t step = 1;
    long double sum = 1.0;
    for (; count > 0; --count) {
        sum += pown(x, step) / fact(step);
        step++;
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    int step = 3, flag = 1;
    double sum = 0;
    for (int q = 1; q < count + 2; q += 2) {
        sum += flag*pown(x, q) / fact(q);
        flag = -flag;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    int step = 3, flag = 1;
    double sum = 0;
    for (int q = 0; q < count + 8; q += 2) {
        sum += flag * pown(x, q) / fact(q);
        flag = -flag;
    }
    return sum;
}
