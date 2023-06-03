#include <iostream>
#include "stdafx.h"
#include <string>
using namespace std;

string nameofmonth(int number) {
	string month[12]{ "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
	return month[number - 1];
}