#include <iostream>
#include <string>

using namespace std;

int n = 100;

struct date {
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
};

enum sex { Male = 1, Female};

struct citizens {
	string name;
	string surname;
	string secondname;
	date date_now;
	string sex;
	string adress;

} citizen[10];

void input();
void output();
void deleted();
void find();

string str, surname;
bool flag1, check;
int i;

int main() {
	setlocale(LC_CTYPE, "Rus");

	while (true) {
		system("cls");
		cout << "Что вы хотите сделать?: \n1 - Ввести нового горожанина\n2 - Показать список\n3 - Найти по дате рождения\n4 - Удалить\n0 - Выход\n";
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
			find();
			break;
		case 4:
			deleted();
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
		cout << "Имя: ";
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
	citizen[i].name = str;

	while (true) {
		flag1 = false;
		cout << "Фамилия: ";
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
	citizen[i].surname = str;

	while (true) {
		flag1 = false;
		cout << "Отчество: ";
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
	citizen[i].secondname = str;

	cout << "Дата рождения:\n";
	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (true) {
		check = true;
		cout << "Месяц ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 12) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	citizen[i].date_now.month = stoi(str);

	while (true) {
		check = true;
		cout << "Год: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 23) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	citizen[i].date_now.year = stoi(str);
	int year;
	while (true) {
		check = true;
		cout << "День: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		year = 2000 + citizen[i].date_now.year;
		if ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0))) {
			if (citizen[i].date_now.month == 2 && stoi(str) > 29) {
				check = false;
			}
			if (citizen[i].date_now.month != 2 && stoi(str) > months[citizen[i].date_now.month - 1]) {
				check = false;
			}
		}
		else {
			if (stoi(str) > months[citizen[i].date_now.month - 1]) {
				check = false;
			}
		}
		if (!check) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		break;
	}
	citizen[i].date_now.day = stoi(str);

	while (true) {
		flag1 = false;
		cout << "Адрес: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j]) && !isdigit(str[j])) {
				if (str[j] == ' ' || str[j] == '.' || str[j] == ',' || str[j] == '/' || str[j] == '\'')
					continue;
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
	citizen[i].adress = str;

	while (true) {
		flag1 = false;
		cout << "Пол(1 - м, 2 - ж): ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (str[0] < '1' || str[0] > '2' || size(str) > 1) {
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
	switch (stoi(str)) {
	case Male: citizen[i].sex = "Мужской"; break;
	case Female: citizen[i].sex = "Женский"; break;
	}

	i++;
}

void output() {
	system("cls");
	for (int j = 0; j < i; j++) {
		cout << citizen[j].surname << " " << citizen[j].name << " " << citizen[j].secondname << " ";
		if (citizen[j].date_now.day < 10)
			cout << "0" << citizen[j].date_now.day << ".";
		else
			cout << citizen[j].date_now.day << ".";
		if (citizen[j].date_now.month < 10)
			cout << "0" << citizen[j].date_now.month << ".";
		else
			cout << citizen[j].date_now.month << ".";
		if (citizen[j].date_now.year < 10)
			cout << "0" << citizen[j].date_now.year << " ";
		else
			cout << citizen[j].date_now.year << " ";
		cout << citizen[j].adress << " " << citizen[j].sex << endl;

	}
	system("pause");
}

void find() {
	system("cls");
	int day, month, year;
	bool flag = false;
	cout << "Введите дату рождения: \n";

	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (true) {
		check = true;
		cout << "Месяц ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 12) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	month = stoi(str);

	while (true) {
		check = true;
		cout << "Год: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check || stoi(str) > 23) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	year = 2000 + stoi(str);
	while (true) {
		check = true;
		cout << "День: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0))) {
			if (month == 2 && stoi(str) > 29) {
				check = false;
			}
			if (month != 2 && stoi(str) > months[month - 1]) {
				check = false;
			}
		}
		else {
			if (stoi(str) > months[month - 1]) {
				check = false;
			}
		}
		if (!check) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		break;
	}
	day = stoi(str);

	for (int j = 0; j < i; j++) {
		if (citizen[j].date_now.day == day) {
			if (citizen[j].date_now.month == month) {
				if (citizen[j].date_now.year + 2000 == year) {
					cout << citizen[j].surname << " " << citizen[j].name << " " << citizen[j].secondname << " ";
					if (citizen[j].date_now.day < 10)
						cout << "0" << citizen[j].date_now.day << ".";
					else
						cout << citizen[j].date_now.day << ".";
					if (citizen[j].date_now.month < 10)
						cout << "0" << citizen[j].date_now.month << ".";
					else
						cout << citizen[j].date_now.month << ".";
					if (citizen[j].date_now.year < 10)
						cout << "0" << citizen[j].date_now.year << " ";
					else
						cout << citizen[j].date_now.year << " ";
					cout << citizen[j].adress << " " << citizen[j].sex << endl;

					flag = true;
					cout << endl;
				}
			}
		}
	}
	if (!flag)
		cout << "Ничего не найдено\n";
	system("pause");
}

void deleted() {
	system("cls");
	int day, month, year;
	bool flag = false;
	cout << "Введите дату рождения: \n";

	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (true) {
		check = true;
		cout << "Месяц ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 12) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	month = stoi(str);

	while (true) {
		check = true;
		cout << "Год: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check || stoi(str) > 23) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	year = 2000 + stoi(str);
	while (true) {
		check = true;
		cout << "День: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0))) {
			if (month == 2 && stoi(str) > 29) {
				check = false;
			}
			if (month != 2 && stoi(str) > months[month - 1]) {
				check = false;
			}
		}
		else {
			if (stoi(str) > months[month - 1]) {
				check = false;
			}
		}
		if (!check) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		break;
	}
	day = stoi(str);

	for (int j = 0; j < i; j++) {
		if (citizen[j].date_now.day == day) {
			if (citizen[j].date_now.month == month) {
				if (citizen[j].date_now.year + 2000 == year) {
					for (int k = j; k < i; k++) {
						citizen[k] = citizen[k + 1];
					}
					i--;

					flag = true;
					cout << endl;
				}
			}
		}
	}
	if (!flag)
		cout << "Ничего не найдено\n";
	system("pause");
}