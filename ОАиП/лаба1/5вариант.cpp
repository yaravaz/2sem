#include <iostream>
using namespace std;

double f1(double x) {
	return exp(x) - 3 - (1 / x);
}

double f2(double x) {
	return 0.2 - pow(x, 2);
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

int kvadr(int n, ...) {
	int* p = &n;
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sqrt(*p)==int(sqrt(*p)))
			result++;
		p += 2;
	}
	return result;
}

int main() {
	setlocale(0, "Rus");
	cout << "Для 1-ой функции " << dichotomy(f1, 0, 1) << endl;
	cout << "Для 2-ой функции " << dichotomy(f2, 0, 1) << endl;

	cout << kvadr(6, 4, 3, 25, 8, 1, 6) << endl;
	cout << kvadr(5, 36, 6, 1234, 9, 23) << endl;
	cout << kvadr(10, 4, 56, 81, 23, 87, 45, 9, 34, 16, 677) << endl;
}