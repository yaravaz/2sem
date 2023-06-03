#include <iostream>
#include "Varparm.h"

using namespace Varparm;

int main() {
	setlocale(LC_CTYPE, "rus");
	ivarparm(1, 1);
	ivarparm(2, 1, 2);
	ivarparm(3, 1, 2, 3);
	ivarparm(7, 1, 2, 3, 4, 5, 6, 7);

	cout << endl;

	svarparm(1, 1);
	svarparm(2, 1, 2);
	svarparm(3, 1, 2, 3);
	svarparm(7, 1, 2, 3, 4, 5, 6, 7);

	cout << endl;

	fvarparm(1.0, FLT_MAX);
	fvarparm(1.0, 2.0, FLT_MAX);
	fvarparm(1.0, 2.0, 3.0, FLT_MAX);
	fvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, FLT_MAX);

	cout << endl;

	dvarparm(1.0, DBL_MAX);
	dvarparm(1.0, 2.0, DBL_MAX);
	dvarparm(1.0, 2.0, 3.0, DBL_MAX);
	dvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, DBL_MAX);

	return 0;
}