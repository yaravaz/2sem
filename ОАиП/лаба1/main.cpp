#include <iostream>
#include <string>
using namespace std;

double f1(double x) {
	return pow(x, 3) + 2 * x - 1;
}

double f2(double x) {
	return exp(x) - 2;
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

int check(int n) {
	bool flag = false;
	if (n % 4 == 0)
		flag = true;
	if (n % 100 == 0) {
		flag = false;
		if (n % 400 == 0)
			flag = true;
	}
	return flag;
}

int days(int n, ...)
{
	int* p = &n; int result1, result2;
	int d, m, y, dd, mm, yy, a, b, c;
	d = *p;
	m = *(p += 2);
	y = *(p += 2);
	dd = *(p += 2);
	mm = *(p += 2);
	yy = *(p += 2);
	bool flag = false;
	int k = d, k1 = dd;
	if (y >= 0 && y <=23) {
		y += 2000;
	}
	else if (y >= 80 && y <= 99) {
		y += 1900;
	}
	for (int i = 1980; i < y; i++) {
		flag = check(i);
		if (flag)
			k += 366;
		else
			k += 365;
		flag = false;
	}
	flag = check(y);
	switch (m-1)
	{
	case 11: k += 30;
	case 10: k += 31;
	case  9: k += 30;
	case  8: k += 31;
	case  7: k += 31;
	case  6: k += 30;
	case  5: k += 31;
	case  4: k += 30;
	case  3: k += 31;
	case  2: if (flag) k += 29; else k += 28;
	case  1: k += 31;
	}
	if (yy >= 0 && yy <= 23) {
		yy += 2000;
	}
	else if (yy >= 80 && yy <= 99) {
		yy += 1900;
	}
	for (int i = 1980; i < yy; i++) {
		flag = check(i);
		if (flag)
			k1 += 366;
		else
			k1 += 365;
		flag = false;
	}
	flag = check(yy);
		switch (mm-1)
		{
		case 11: k1 += 30;
		case 10: k1 += 31;
		case  9: k1 += 30;
		case  8: k1 += 31;
		case  7: k1 += 31;
		case  6: k1 += 30;
		case  5: k1 += 31;
		case  4: k1 += 30;
		case  3: k1 += 31;
		case  2: if (flag) k1 += 29; else k1 += 28;
		case  1: k1 += 31;
		}
	return abs(k1 - k);
}

int main() {
	setlocale(0, "Rus");
	cout << "Для 1-ой функции " << dichotomy(f1, 0, 1) << endl;
	cout << "Для 2-ой функции " << dichotomy(f2, 0, 1) << endl;

	bool flag = true; int s, d, dd, m, mm, y, yy;
	while (flag) {
		cout << "Хотите ввести дату?(1 - да/ 0 - нет)" << endl;
		cin >> s;
		if (s == 1) {
			cout << "Введите две даты в формате дд.мм.гг через пробел" << endl;
			string str;
			cin.ignore();
			getline(cin, str, '\n');
			d = (str[0] - '0') * 10 + str[1] - '0';
			m = (str[3] - '0') * 10 + str[4] - '0';
			y = (str[6] - '0') * 10 + str[7] - '0';
			dd = (str[9] - '0') * 10 + str[10] - '0';
			mm = (str[12] - '0') * 10 + str[13] - '0';
			yy = (str[15] - '0') * 10 + str[16] - '0';
			cout << days( d, m, y, dd, mm, yy) << " дней между датами" << endl;
		}
		else if(s == 0) {
			break;
		}
		else {
			cout << "Введено неверное значение" << endl;
		}
	}
	
}