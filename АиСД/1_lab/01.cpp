#include <iostream>
#include <ctime>
using namespace std;

int main() {
	setlocale(0, "Rus");
	int n;
	cout << "Введите N: ";
	cin >> n;
	unsigned int start_time = clock();
	long long int numb = 0, first = 0, second = 1;
	if (n <= 2) {
		if (n == 1) {
			numb = first;
		}
		else if (n == 2) {
			numb = second;
		}
	}
	else {
		for (int i = 3; i <= n; i++) {
			numb = first + second;
			first = second;
			second = numb;
		}
	}
	cout << n << "-ое число Фибоначчи равно " << numb << endl;
	unsigned int end_time = clock();
	cout << "Расчетное время циклом: " << end_time - start_time << " мс";
	return 0;
}