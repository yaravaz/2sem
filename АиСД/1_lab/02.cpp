#include <iostream>
#include <ctime>
using namespace std;

int func(int n) {
	if (n <= 2) {
		if (n == 1) {
			return 0;
		}
		if (n == 2) {
			return 1;
		}
	}
	return func(n - 1) + func(n - 2);
}

int main() {
	setlocale(0, "Rus");
	int n;
	cout << "Введите N: ";
	cin >> n;
	unsigned start_time = clock();
	cout << n << "-ое число Фибоначчи равно " << func(n) << endl;
	unsigned int end_time = clock();

	double time = (end_time - start_time) / 1000 + (end_time - start_time) - int(end_time - start_time);
	cout << "Расчетное время рекурсией: " << time << " с";
	return 0;
}