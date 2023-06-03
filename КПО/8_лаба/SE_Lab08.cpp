#include <iostream>

using namespace std;

int defaultparm(int a, int b, int c, int d, int e, int f = 8, int g = 9) {

	return (a + b + c + d + e + f + g) / 7;
}

int main() {

	setlocale(LC_CTYPE, "Rus");

	int res1 = defaultparm(1, 2, 3, 4, 5);
	int res2 = defaultparm(1, 2, 3, 4, 5, 6, 7);

	return 0;
}