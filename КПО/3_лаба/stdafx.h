#pragma once
#define NUMBEROFMONTH 12
#define FEBRUARY 1
#define FEBDAY 29
#define YEAR 2023
using namespace std;


bool check(int n);
int order(int* ms, int d, int m, int y);
string nameofmonth(int number);
string holiday(int order);