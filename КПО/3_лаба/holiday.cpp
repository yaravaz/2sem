#include <iostream>
#include <fstream>
#include "stdafx.h"
#include <string>
#include <windows.h>
using namespace std;

string holiday(int order) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	string str, file = "holidays.txt";
	int counter = 1;
	ifstream in;
	in.open(file);

	while (!in.eof()) {
		getline(in, str);
		if (counter == order) {
			return str;
			break;
		}
		counter++;
	}
	in.close();
}