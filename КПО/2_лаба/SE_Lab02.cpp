#include <iostream>
#define X 13 // объявление констант(n = 4)
#define Y 14
#define Z 15
#define S 5.0

int sum(int x, int y) { // ф-ция суммы
	return(x + y);
}

int(*func) (int, int); // указатель на функцию

int main()
{
	// bool(1 байт)
	// false - 00 true - 01
	bool b1 = false; // инициализация переменной b1 со значением false
	bool b2 = true; // b2 со значением true

	// char(1 байт)
	// 6f and ee
	char c1 = 'o'; // инициализация переменной с1 со значением 'o'(английский)
	char c2 = 'о'; // с2 со значением 'o'(русский)

	// wchar_t(2 байта)
	// 76 00 and 3204
	wchar_t wc1 = L'v'; // инициализация переменной wc1 со значением L"v"
	wchar_t wc2 = L'в'; // cw2 со значением L"в"

	// short(unsigned short) (2 байта)
	short ishort1 = X; // DEC(13) -> HEX(D)
	short ishort2 = -X; // DEC(-13) -> BIN(10001101) -> BIN(111111110011) -> HEX(F3)
	short shortmax = 0x7FFF; // HEX(7FFF)
	short shortmin = 0x8000; // HEX(8000)
	unsigned short unshortmin = 0x0; // HEX(0)
	unsigned short unshortmax = 0x0000ffff; // HEX(ffff)

	// int(unsigned int) (4 байта)
	int iint1 = Y; // DEC(14) -> HEX(E)
	int iint2 = -Y; // DEC(-14) -> BIN(10001110) -> BIN(11110010) -> HEX(fff2)
	int intmax = 0x7fffffff; // HEX(7fffffff)
	int intmin = 0x80000000; // HEX(80000000)
	unsigned int unintmin = 0x0; // HEX(0)
	unsigned int unintmax = 0xffffffff; // HEX(ffffffff)

	// long(unsigned long) (8 байт)
	long ilong1 = Z; // DEC(15) -> HEX(F)
	long ilong2 = -Z; // DEC(-15) -> BIN(10001111) -> BIN(11110001) -> HEX(fff1)
	long longmin = 0x80000000; // HEX(80000000)
	long longmax = 0x7fffffff; // HEX(7fffffff)
	unsigned long ulongmin = 0x0; // HEX(0)
	unsigned long ulongmax = 0xFFFFFFFF; // HEX(ffffffff)

	// float(4 байта)
	float f1 = S; // DEC(5.0) -> HEX(5.000)
	float f2 = -S; // DEC(-5.0) -> BIN(10000101) -> BIN(11111011) -> HEX(fffC.000)

	float polInf = f1 / 0; // #INF
	float otrInf = f2 / 0; // -#INF
	float ind = sqrt(f2); // -#IND

	char a = 'А'; // объявления переменных типов char, wchar_t, short, int, float, double
	wchar_t b = L'А';
	short c = 19;
	int d = 191;
	float f = 1.9f;
	double g = 1.9e-5;

	// указатели на вышеинициализинованные переменные
	char* pa = &a; // a -> c0
	wchar_t* pb = &b; // b -> 10 04 -> 0410
	short* pc = &c; // c -> 13 00 -> 0013
	int* pd = &d; // d -> bf 00 00 00 -> 00bf 0000 -> 000000bf
	float* pf = &f; // f -> 33 33 f3 3f -> 3333 3ff3 -> 3ff33333
	double* pg = &g; // g -> 18 0a d8 0e 46 ec f3 3e -> 0a18 0ed8 ec46 3ef3 -> 0ed80a18 3ef3ec46 -> 3ef3ec460ed80a18

	char* ax = pa + 3; // ax -> 16 fc 93 00
	wchar_t* bx =  pb + 3; // bx -> 0a fc 93 00
	short* cx = pc + 3; // cx -> fe fb 93 00
	int* dx = pd + 3; //dx -> f8 fb 93 00
	float* fx = pf + 3; // fx -> ec fb 93 00
	double* gx = pg + 3; // gx -> e8 fb 93 00

	func = sum;
	int a21 = func(5, 3);
}