#include <iostream>

using namespace std;

int _cdecl sum(int x, int y, int z) {return x + y + z;}
int _stdcall pros(int& x, int y, int z) {return x * y * z;}
int _fastcall sum2(int x, int y, int z, int k) {return x + y + z + k;}

int main() {

	setlocale(LC_ALL, "rus");
	int res, k1 = 1;
	res = sum(1, 2, 3);
	cout << "Результат сложения: 1 + 2 + 3 = " << res << endl;
	res = pros(k1, 2, 3);
	cout << "Результат произведения: 1 * 2 * 3 = " << res << endl;
	res = sum2(1, 2, 3, 4);
	cout << "Результат суммы: 1 + 2 + 3 + 4 = " << res << endl;
	return 0;
}