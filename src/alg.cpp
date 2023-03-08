// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
	double value1 = value;
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
	uint16_t sum = 1, step = 0;
	for (; count > 0; --count) {
		sum += pown(x, step) / fact(step);
		step++;
	}
	return sum;
}

double sinn(double x, uint16_t count) {
	uint16_t sum = x, step = 3;
	for (; count > 0; --count) {
		sum -= pown(x, step) / fact(step) * pow(-1, step-1);
		step = 2 * step - 1;
	}
	return sum;
}

double cosn(double x, uint16_t count) {
	uint16_t sum = 1, step = 2;
	for (; count > 0; --count) {
		sum -= pown(x, step) / fact(step) * pow(-1, step);
		step = 2 * step - 2;
	}
	return sum;
}
