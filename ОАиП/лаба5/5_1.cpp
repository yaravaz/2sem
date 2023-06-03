#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int n = 100;

struct date {
	unsigned year :11;
};

enum origin {
	 buy = 1, theft, gift
};

struct Library {
	string author;
	string name;
	string publisher;
	string section;
	int orign;
	string availability;
	date date_now;
};

void input();
void output();
void deleted(unsigned year);
void find(unsigned year);

string str; unsigned Year;
bool flag1, check;
int i;
Library book[20];

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		system("cls");
		cout << "Добро пожаловать в библиотеку, что вы хотите сделать?\n";
		cout << "1 - Ввести информацию в архив\n2 - Вывести информацию из архива\n3 - Найти книгу\n4 - Удалить информацию\n0 - Выйти\n";		
		cin >> str;

		if (str[0] < '0' || str[0] > '4' || size(str) > 1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		n = stoi(str);
		switch (n) {
		case 1: 
			input();
			break;
		case 2: 
			output();
			break;
		case 3: 
			while (true) {
				flag1 = false;
				cout << "Введите год выдачи книги: ";
				cin >> str;
				for (int j = 0; j < size(str); j++) {
					if (!isdigit(str[j])) {
						system("cls");
						cout << "Некорректное значение" << endl;
						system("pause");
						flag1 = true;
						break;
					}
				}
				if (stoi(str) > 2023 || stoi(str) < 0) {
					flag1 = true;
				}
				if (flag1) {
					continue;
				}
				break;
			}
			Year = stoi(str);
			find(Year);
			break;
		case 4: 
			while (true) {
				flag1 = false;
				cout << "Введите год выдачи книги, которую хотите удалить: ";
				cin >> str;
				for (int j = 0; j < size(str); j++) {
					if (!isdigit(str[j])) {
						system("cls");
						cout << "Некорректное значение" << endl;
						system("pause");
						flag1 = true;
						break;
					}
				}
				if (stoi(str) > 2023 || stoi(str) < 0) {
					flag1 = true;
				}
				if (flag1) {
					continue;
				}
				break;
			}
			Year = stoi(str);
			deleted(Year);
			break;
		case 0: 
			exit(0);
		}
	}
	return 0;
}

void input() {
	system("cls");
	while (true) {
		flag1 = false;
		cout << "Автор: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ') {
					continue;
				}
				system("cls");
				cout << "Некорректное значение" << endl;
				system("pause");
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	book[i].author = str;

	while (true) {
		flag1 = false;
		cout << "Название: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ') {
					continue;
				}
				system("cls");
				cout << "Некорректное значение" << endl;
				system("pause");
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	book[i].name = str;

	while (true) {
		flag1 = false;
		cout << "Издательство: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ') {
					continue;
				}
				system("cls");
				cout << "Некорректное значение" << endl;
				system("pause");
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	book[i].publisher = str;

	while (true) {
		flag1 = false;
		cout << "Раздел(специальная литература, хобби, домашнее хозяйство, беллетристика и т. д.): ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ') {
					continue;
				}
				system("cls");
				cout << "Некорректное значение" << endl;
				system("pause");
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	book[i].section = str;

	while (true) {
		cout << "Происхождение(1 - покупка, 2 - кража, 3 - подарок): ";
		cin >> str;

		if (str[0] < '1' || str[0] > '3' || size(str) > 1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	
	book[i].orign = stoi(str);
	
	while (true) {
		flag1 = false;
		cout << "Наличие: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				system("cls");
				cout << "Некорректное значение" << endl;
				system("pause");
				flag1 = true;
				break;
			}

		}
		if (flag1) {
			continue;
		}
		break;
	}
	book[i].availability = str;

	while (true) {
		check = true;
		cout << "Год выдачи: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 2023 || stoi(str) < 0) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	book[i].date_now.year = stoi(str);
	i++;
}

void output() {
	system("cls");
	for (int j = 0; j < i; j++) {
		cout << book[j].author << " " << book[j].name << " " << book[j].publisher << " " << book[j].section;
		switch (book[j].orign) {
		case buy: cout << " покупка" << " "; break;
		case theft: cout << " кража" << " "; break;
		case gift: cout << " подарок" << " "; break;
		}
		cout << book[j].availability << " " << book[j].date_now.year << endl;	
	}
	system("pause");
}

void find(unsigned year) {
	system("cls");
	bool flag = false;
	for (int j = 0; j < i; j++) {
		if (book[j].date_now.year == year) {
			cout << book[j].author << " " << book[j].name << " " << book[j].publisher << " " << book[j].section;
			switch (book[j].orign) {
			case buy: cout << " покупка" << " "; break;
			case theft: cout << " кража" << " "; break;
			case gift: cout << " подарок" << " "; break;
			}
			cout << book[j].availability << " " << book[j].date_now.year << endl;
			flag = true;
			cout << endl;
		}
	}
	if (!flag)
		cout << "Ничего не найдено\n";
	system("pause");
}

void deleted(unsigned year) {
	system("cls");
	bool flag = false;
	for (int j = 0; j < i; j++) {
		if (book[j].date_now.year == year) {
			for (int k = j; k < i; k++) {
				book[k] = book[k + 1];
			}
			i--;
			flag = true;
		}
	}
	if (!flag)
		cout << "Ничего не найдено\n";
	system("pause");
}

