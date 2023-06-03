#include <iostream>
using namespace std;

double f1(double x) {
	return exp(x) + x - 4;
}

double f2(double x) {
	return pow(x, 3) + x - 4;
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

void compr(int n, char* text...) {
	char* p = text, *str;
	for (int i = 0; i < n; ++i)
	{
		str = p;
		while (*p)
		{
			if (*p != ' ')
				*str++ = *p;
			++p;
		}
		*str = '\0';
		++p;
	}
}

int main() {
	setlocale(0, "Rus");
	cout << "��� 1-�� ������� " << dichotomy(f1, 0, 2) << endl;
	cout << "��� 2-�� ������� " << dichotomy(f2, 0, 2) << endl;

	cout << endl;
	char text1[] = "Hello, world!";
	char text2[] = "��� ����� �� ������� ������.";
	cout << text1 << endl << text2 << endl;
	compr(2, text1, text2);
	cout << text1 << endl << text2 << endl;
	cout << endl;
	char text11[] = "�� ����������� ���������� ����� ����� ������ � ������ � �������� � ����� ���.";
	char text22[] = "��� �������� �����.";
	char text3[] = "�� ���� � �� �������� ����� � �������� � ������������ ��� ����������.";
	char text4[] = "�� ������ � ������ ���� ���������� ��� � � �� ����� �� �����, ������ ��� �� ������� �����.";
	char text5[] = "� ��� ��� �����, ����� ������� �� ������, � ���� ���� ���� ���� � ������� �������������, ���������� ������.";
	cout << text11 << endl << text22 << endl << text3 << endl << text4 << endl << text5 << endl;
	compr(5, text11, text22, text3, text4, text5);
	cout << text11 << endl << text22 << endl << text3 << endl << text4 << endl << text5 << endl;
	cout << endl;
	char text111[] = "�������, ���� �������� ���� ��������.";
	char text222[] = "� ������� ����, ������ �����, � ��� ����� ���, ��� ��� ������� ����";
	char text33[] = "������� �����, � �������, ����� ���� ������� � ������� ��������";
	cout << text111 << endl << text222 << endl << text33 << endl;
	compr(3, text111, text222, text33);
	cout << text111 << endl << text222 << endl << text33 << endl;
}