#include <iostream>
#include "stdafx.h"



bool check(int n) {
	if ((n % 4 == 0) || ((n % 100 == 0) && (n % 400 == 0)))
		return true;
	else
		return false;
}