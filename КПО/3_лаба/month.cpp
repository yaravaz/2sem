#include <iostream>
#include "stdafx.h"
#include <string>
using namespace std;

string nameofmonth(int number) {
	string month[12]{ "������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������" };
	return month[number - 1];
}