#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int n = 100;

struct time {
	int hours;
	int minutes;
	int desh;
	int desmin;
};

struct train {
	int number_of_train;
	string destination;
	struct time time;
	int days;
}trains[20];

union buff {
	char str1[50];
	int n;
} buff;

void input();
void output();
void find(string name);

string str; string name;
bool flag1, check;
int i;

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		system("cls");
		cout << "��� �� ������ �������?\n";
		cout << "1 - ������ ����������\n2 - ������� ����������\n3 - ����� �����\n0 - �����\n";
		cin >> buff.str1;
		str = buff.str1;

		if (str[0] < '0' || str[0] > '4' || size(str) > 1) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}

		buff.n = stoi(str);
		switch (buff.n) {
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			while (true) {
				flag1 = false;
				cout << "����� ����������: ";
				cin.ignore();
				getline(cin, str);
				for (int j = 0; j < size(str); j++) {
					if (!isalpha(str[j])) {
						if (str[j] == ' ' || str[j] == '-') {
							break;
						}
						else {
							system("cls");
							cout << "������������ ��������" << endl;
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
			name = str;
			find(name);
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
		check = true;
		cout << "����� ������: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}

	trains[i].number_of_train = stoi(str);

	while (true) {
		flag1 = false;
		cout << "����� ����������: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ' || str[j] == '-') {
					continue;
				}
				system("cls");
				cout << "������������ ��������" << endl;
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
	trains[i].destination = str;

	while (true) {
		flag1 = false;
		cout << "��� ����������: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				system("cls");
				cout << "������������ ��������" << endl;
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
	trains[i].days = stoi(str);

	cout << "����� ��������\n";
	while (true) {
		check = true;
		cout << "����: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 23) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}
	trains[i].time.hours = stoi(str);
	while (true) {
		check = true;
		cout << "������: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 59) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}
	trains[i].time.minutes = stoi(str);

	cout << "����� �����������\n";
	while (true) {
		check = true;
		cout << "����: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 23) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}
	trains[i].time.desh = stoi(str);
	while (true) {
		check = true;
		cout << "������: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (!isdigit(str[j])) {
				check = false;
			}
		}
		if (!check || stoi(str) > 59) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}
	trains[i].time.desmin = stoi(str);

	i++;
}

void output() {
	system("cls");
	for (int j = 0; j < i; j++) {
		cout << "�" << trains[j].number_of_train << " " << trains[j].destination << " " << trains[j].days << " " << trains[j].time.hours << ":" << trains[j].time.minutes << "-" << trains[j].time.desh << ":" << trains[j].time.desmin << endl;

	}
	system("pause");
}

void find(string name) {
	system("cls");
	bool flag = false;
	for (int j = 0; j < i; j++) {
		if (trains[j].destination == name) {
			cout << "�" << trains[j].number_of_train << " " << trains[j].destination << " " << trains[j].days << " " << trains[j].time.hours << ":" << trains[j].time.minutes << "-" << trains[j].time.desh << ":" << trains[j].time.desmin << endl;
			flag = true;
			cout << endl;
		}
	}
	if (!flag)
		cout << "������ �� �������\n";
	system("pause");
}
