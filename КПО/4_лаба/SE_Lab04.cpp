#include <iostream>
#include <tchar.h>

using namespace std;

typedef unsigned char day; // день
typedef unsigned char month; // месяц
typedef unsigned short year; // год
struct Date // дата
{
	day dd;
	month mm;
	year yyyy;
};

// >
bool operator>(Date date1, Date date2) {
	return (date1.yyyy > date2.yyyy || (date1.yyyy == date2.yyyy && (date1.mm > date2.mm || (date1.mm == date2.mm && date1.dd > date2.dd))));
}
 
// <
bool operator<(Date date1, Date date2) {
	return (date1.yyyy < date2.yyyy || (date1.yyyy == date2.yyyy && (date1.mm < date2.mm || (date1.mm == date2.mm && date1.dd < date2.dd))));
}

// ==
bool operator==(Date date1, Date date2) {
	return (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd == date2.dd);
}

int _tmain(int argc, _TCHAR* argv) {

	setlocale(LC_CTYPE, "Rus");

	Date date1 = {7,1,1980 };
	Date date2 = {7,2,1993 };
	Date date3 = {7,1,1980 };

	if (date1 < date2) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if (date1 > date2) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if (date1 == date2) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if (date1 == date3) cout << "истина" << endl;
	else cout << "ложь" << endl;

	return 0;
}