#include <iostream>
#include "stdafx.h"
 

int order(int* ms, int d, int m, int y) {
	int dayOrder = d;
	if (check(y)) {
		ms[FEBRUARY] = FEBDAY;
	}
	for (int i = 1; i < m; i++) {
		dayOrder += ms[i];
	}
	return dayOrder;
}
