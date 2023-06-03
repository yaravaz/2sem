#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

typedef unsigned short day;
typedef unsigned short month;
typedef unsigned short year;
typedef unsigned short num;
typedef unsigned short quantity;
typedef float decimal;
typedef string str;


struct Date {
	day day;
	month month;
	year year;
};

struct Product {
	str type;
	str name;
	num number;
	quantity amount;
	decimal price;
	str manufacturer;
	Date date;
};

Product product[5], choice[1];
num i, n;
str buff;
bool flag, flag1;

void input();
void output();
void find();

bool operator>(Product product1, Product product2) {
	return ((product1.price * product1.amount) > (product2.price * product2.amount));
}


int main() {
	setlocale(LC_CTYPE, "Rus");
	flag = true;

	while (flag) {
		system("cls");
		
		cout << "Что вы хотите сделать?\n1 - Ввод информации в товаре\n2 - Вывод информации\n3 - Поиск товара, который продать выгоднее\n0 - Выход\n";
		cin >> buff;
		 
		if (buff[0] < '0' || buff[0] > '4' || size(buff) > 1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		n = stoi(buff);
		switch (n) {
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			find();
			break;
		case 0:
			exit(0);
		}
	}

	return 0;
}


void input() {
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		flag1 = false;
		cout << "Тип товара: ";
		cin.ignore();
		getline(cin, buff);
		for (int j = 0; j < size(buff); j++) {
			if (!((buff[j] >= 'A' && buff[j] <= 'Z') || (buff[j] >= 'a' && buff[j] <= 'z') || (buff[j] >= 'А' && buff[j] <= 'Я') || (buff[j] >= 'а' && buff[j] <= 'я'))) {
				if (buff[j] == ' ' || buff[j] == '-') {
					break;
				}
				else {
					system("cls");
					cout << "Некорректное значение" << endl;
					system("pause");
					flag1 = true;
					break;
				}
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	product[i].type = buff;
	while (true) {
		flag1 = false;
		cout << "Название: ";
		cin.ignore();
		getline(cin, buff);
		for (int j = 0; j < size(buff); j++) {
			if (!((buff[j] >= 'A' && buff[j] <= 'Z') || (buff[j] >= 'a' && buff[j] <= 'z') || (buff[j] >= 'А' && buff[j] <= 'Я') || (buff[j] >= 'а' && buff[j] <= 'я'))) {
				if (buff[j] == ' ' || buff[j] == '-') {
					break;
				}
				else {
					system("cls");
					cout << "Некорректное значение" << endl;
					system("pause");
					flag1 = true;
					break;
				}
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	product[i].name = buff;
	while (true) {
		flag1 = true;
		cout << "Инвертарный номер: ";
		cin >> buff;

		for (int j = 0; j < size(buff); j++) {
			if (buff[j] < '0' || buff[j] > '9') {
				flag1 = false;
			}
		}
		if (!flag1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	product[i].number = stoi(buff);
	while (true) {
		flag1 = true;
		cout << "Количество: ";
		cin >> buff;

		for (int j = 0; j < size(buff); j++) {
			if (buff[j] < '0' || buff[j] > '9') {
				flag1 = false;
			}
		}
		if (!flag1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	product[i].amount = stoi(buff);
	while (true) {
		flag1 = true;
		cout << "Цена: ";
		cin >> buff;

		for (int j = 0; j < size(buff); j++) {
			if (buff[j] < '0' || buff[j] > '9') {
				flag1 = false;
			}
			if (buff[j] == '.') {
				flag1 = true;
			}
		}
		if (!flag1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	product[i].price = stof(buff);
	while (true) {
		flag1 = false;
		cout << "Производитель: ";
		cin.ignore();
		getline(cin, buff);
		for (int j = 0; j < size(buff); j++) {
			if (!((buff[j] >= 'A' && buff[j] <= 'Z') || (buff[j] >= 'a' && buff[j] <= 'z') || (buff[j] >= 'А' && buff[j] <= 'Я') || (buff[j] >= 'а' && buff[j] <= 'я'))) {
				if (buff[j] == ' ' || buff[j] == '-') {
					break;
				}
				else {
					system("cls");
					cout << "Некорректное значение" << endl;
					system("pause");
					flag1 = true;
					break;
				}
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	product[i].manufacturer = buff;
	cout << "Срок реализации:\n";
	num months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (true) {
		flag1 = true;
		cout << "Месяц ";
		cin >> buff;

		for (int j = 0; j < size(buff); j++) {
			if (buff[j] < '0' || buff[j] > '9') {
				flag1 = false;
			}
		}
		if (!flag1 || stoi(buff) > 12) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	product[i].date.month = stoi(buff);

	while (true) {
		flag1 = true;
		cout << "Год: ";
		cin >> buff;

		for (int j = 0; j < size(buff); j++) {
			if (buff[j] < '0' || buff[j] > '9') {
				flag1 = false;
			}
		}
		if (!flag1 || stoi(buff) > 23) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	product[i].date.year = stoi(buff);
	num year;
	while (true) {
		flag1 = true;
		cout << "День: ";
		cin >> buff;

		for (int j = 0; j < size(buff); j++) {
			if (buff[j] < '0' || buff[j] > '9') {
				flag1 = false;
			}
		}
		year = 2000 + product[i].date.year;
		if ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0))) {
			if (product[i].date.month == 2 && stoi(buff) > 29) {
				flag1 = false;
			}
			if (product[i].date.month != 2 && stoi(buff) > months[product[i].date.month - 1]) {
				flag1 = false;
			}
		}
		else {
			if (stoi(buff) > months[product[i].date.month - 1]) {
				flag1 = false;
			}
		}
		if (!flag1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		break;
	}
	product[i].date.day = stoi(buff);
	i++;
}

void output() {
	system("cls");

	cout << "__________________________________________________________________________________________________________________________________________\n";
	cout << "|     Тип продукта    |       Название        |  Инвентарный номер  |    Кол-во    |     Цена     |  Производитель  |   Срок реализации  | \n";
	cout << "|_____________________|_______________________|_____________________|______________|______________|_________________|____________________|\n";
	for (int j = 0; j < i; j++) {
		cout << "| " << product[j].type << setw(22 - size(product[j].type)) << "| ";
		cout << product[j].name << setw(24 - size(product[j].name)) << "| ";
		cout << product[j].number << setw(22 - size(to_string(product[j].number))) << "| ";
		cout << product[j].amount << setw(15 - size(to_string(product[j].amount))) << "| ";
		if((int)product[j].price == product[j].price)
			cout << product[j].price << setw(22 - size(to_string(product[j].price))) << "| ";
		else
			cout << product[j].price << setw(19 - size(to_string(product[j].price))) << "| ";
		cout << product[j].manufacturer << setw(18 - size((product[j].manufacturer))) << "| ";

		if (product[j].date.day < 10)
			cout << "0" << product[j].date.day << ".";
		else
			cout << product[j].date.day << ".";
		if (product[j].date.month < 10)
			cout << "0" << product[j].date.month << ".";
		else
			cout << product[j].date.month << ".";
		if (product[j].date.year < 10)
			cout << "0" << product[j].date.year;
		else
			cout << product[j].date.year;
		cout << setw(13) << " |\n";
		cout << "|_____________________|_______________________|_____________________|______________|______________|_________________|____________________|\n";
	}

	system("pause");
}

void find() {
	system("cls");
	
	choice[0] = product[0];

	for (int j = 1; j <= i; j++) {
		if (product[j] > choice[0])
			choice[0] = product[j];

	}
	cout << "Наиболее выгодно продать " << choice[0].type << " " << choice[0].name << " " << choice[0].number << " " << choice[0].amount << " " << choice[0].price << " " << choice[0].manufacturer << " ";
	if (choice[0].date.day < 10)
		cout << "0" << choice[0].date.day << ".";
	else
		cout << choice[0].date.day << ".";
	if (choice[0].date.month < 10)
		cout << "0" << choice[0].date.month << ".";
	else
		cout << choice[0].date.month << ".";
	if (choice[0].date.year < 10)
		cout << "0" << choice[0].date.year << endl;
	else
		cout << choice[0].date.year << endl;

	system("pause");
}