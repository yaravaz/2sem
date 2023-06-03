#include <iostream>
using namespace std;

double f1(double x) {
	return pow(x, 2) + 4 * x - 2;
}

double f2(double x) {
	return sin(x) + 0.1;
}

double dichotomy(double(*f)(double), double a, double b)
{
	double x = 1, e = 0.001;
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0)
		{
			b = x;
		}
		else a = x;
	}
	return x;
}

int fmin(int n, ...) {
	int* p = &n;
	int min = *p;
	for (int i = 1; i <= n; i++)
	{
		if (min > *(p += 2))
			min = *p;
	}
	return min;
}

int main() {
	setlocale(0, "Rus");
	cout << "Для 1-ой функции " << dichotomy(f1, 0, 1) << endl;
	cout << "Для 2-ой функции " << dichotomy(f2, 0, 1) << endl;

	cout << fmin(6, 2, 3, 5, 8, 1, 6) << endl;
	cout << fmin(5, 34, 4, 1234, 9, 23) << endl;
	cout << fmin(10, 4, 56, 73, 23, 87, 45, -1, 34, 23, 677) << endl;
}