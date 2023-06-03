#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void input();
void output();

struct time {
	int hours;
	int minutes;
};

struct train {
	int number_of_train;
	string destination;
	struct time time;
};

int choice;
int i = 0;
struct train trains[8];
string str;

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true){
		system("cls");
		cout << "Что вы хотите сделать?\n1 - Добавить поезд\n2 - Найти подходящие\n0 - Выход" << endl;
		cin >> str;

		if (str[0] < '0' || str[0] > '2' || size(str) > 1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		choice = stoi(str);

		switch (choice) {
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 0:
			exit(0);
		}
	}
}

void input() {
	system("cls");
	

	bool check;
	while (true) {
		check = true;
		cout << "Номер поезда: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
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

	trains[i].number_of_train = stoi(str);
	bool flag1;
	while (true) {
		flag1 = false;
		cout << "Пункт назначения: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'А' && str[j] <= 'Я') || (str[j] >= 'а' && str[j] <= 'я'))) {
				if (str[j] == ' ' || str[j] == '-') {
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
	trains[i].destination = str;
	cout << "Время\n";
	while (true) {
		check = true;
		cout << "Часы: ";
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
	trains[i].time.hours = stoi(str);
	while (true) {
		check = true;
		cout << "Минуты: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check || stoi(str) > 59) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	trains[i].time.minutes = stoi(str);
	i++;
	cout << endl << endl;
}

void sort() {
	struct train buf;
	for (int j = 0; j < i - 1; j++) {
		for (int k = j; k < i; k++) {
			if (trains[j].destination > trains[k].destination) {
				buf = trains[k];
				trains[k] = trains[j];
				trains[j] = buf;
			}
		}
	}
}

void output() {
	system("cls");
	sort();
	bool check;
	int usershour, usersmin; bool flag = false;
	while (true) {
		check = true;
		cout << "Введите время" << endl;
		cout << "Часы: ";
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
	usershour = stoi(str);
	while (true) {
		check = true;
		cout << "Минуты: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check || stoi(str) > 59) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		break;
	}
	usersmin = stoi(str);
	for (int j = 0; j < i; j++) {
		if ((trains[j].time.hours > usershour) || ((trains[j].time.hours == usershour) && (trains[j].time.minutes > usersmin))) {
			cout << "\n№" << trains[j].number_of_train << " " << trains[j].destination << " " << trains[j].time.hours << ":" << trains[j].time.minutes << endl;
			flag = true;
		}
	}
	if (!flag) {
		cout << "Не найдено " << endl;
	}
	system("pause");
}