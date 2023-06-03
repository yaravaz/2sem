#include <iostream>
#include "Varparm.h"

using namespace Varparm;

int Varparm::ivarparm(int a, ...) {

	int *p = &a;
	int pros = 1;
	int k = 1;
	for (int i = 0; i < p[0]; i++) {
		pros *= p[k];
		k++;
	}
	cout << "Произведение: " << pros << endl;

	return pros;
}

int Varparm::svarparm(short a, ...) {

	int* p = (int*)&a;
	int max = p[0];
	int k = 1;
	for (int i = 0; i < p[0]; i++) {
		if (p[k] > p[i]) {
			max = p[k];
		}
		k++;
	}
	cout << "Максимальное для short: " << max << endl;

	return max;
}

double Varparm::fvarparm(float a, ...) {

	double* p = (double*)(&a + 1);
	double sum = a;
	int k = 0;
	while (p[k] != (double)FLT_MAX) {
		sum += p[k];
		k++;
	}
	cout << "Сумма для float: " << sum << endl;

	return sum;
}

double Varparm::dvarparm(double a, ...) {

	double* p = &a;
	double sum = 0;
	int k = 0;
	while (p[k] != DBL_MAX) {
		sum += p[k];
		k++;
	}
	cout << "Сумма для double: " << sum << endl;

	return sum;
}
