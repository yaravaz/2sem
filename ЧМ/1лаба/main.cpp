#include <iostream>
using namespace std;

int main() {
	setlocale(0, "rus");

	double e = 0.001, x1 = 1, x2 = 1, x0 = 1, counter = 0;
	do
	{
		x1 = x2;
		double prom = (0.06667) * (pow(x1, 3) + 12 * x1 - 12);
		x2 = x1 - prom;
		
		counter++;
		cout << x1 << endl;
	} 
	while (abs(x2 - x1) > e && counter < 100);
	cout << counter;
}
