#include <iostream>
using namespace std;

int main() {
	setlocale(0, "rus");

	double x = 1, e = 0.001, a = 1, b = 2;
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if ((pow(x, 3) + x - 3) * (pow(a, 3) + a - 3) <= 0)
		{
			b = x;
		}
		else a = x;
	}
	cout << x;
}