#include <iostream>
#include "stdafx.h"



bool check(int n) {
	bool flag;
	flag = false;
	if (n % 4 == 0)
		flag = true;
	if (n % 100 == 0) {
		flag = false;
		if (n % 400 == 0)
			flag = true;
	}
	return flag;
}