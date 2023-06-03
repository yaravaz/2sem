#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int n = 100;

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
};

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
Library book[20];

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		system("cls");
		cout << "����� ���������� � ����������, ��� �� ������ �������?\n";
		cout << "1 - ������ ���������� � �����\n2 - ������� ���������� �� ������\n3 - ����� �����\n0 - �����\n";
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
				cout << "������� ������: ";
				cin.ignore();
				getline(cin, str);
				for (int j = 0; j < size(str); j++) {
					if (!isalpha(str[j])) {
						if (str[j] == ' ') {
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
		flag1 = false;
		cout << "�����: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ') {
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
	book[i].author = str;

	while (true) {
		flag1 = false;
		cout << "��������: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ') {
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
	book[i].name = str;

	while (true) {
		flag1 = false;
		cout << "������������: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ') {
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
	book[i].publisher = str;

	while (true) {
		flag1 = false;
		cout << "������(����������� ����������, �����, �������� ���������, ������������� � �. �.): ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
				if (str[j] == ' ') {
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
	book[i].section = str;

	while (true) {
		cout << "�������������(1 - �������, 2 - �����, 3 - �������): ";
		cin >> str;

		if (str[0] < '1' || str[0] > '3' || size(str) > 1) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}

	book[i].orign = stoi(str);

	while (true) {
		flag1 = false;
		cout << "�������: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!isalpha(str[j])) {
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
	book[i].availability = str;

	i++;
}

void output() {
	system("cls");
	for (int j = 0; j < i; j++) {
		cout << book[j].author << " " << book[j].name << " " << book[j].publisher << " " << book[j].section;
		switch (book[j].orign) {
		case buy: cout << " �������" << " "; break;
		case theft: cout << " �����" << " "; break;
		case gift: cout << " �������" << " "; break;
		}
		cout << book[j].availability << endl;
	}
	system("pause");
}

void find(string name) {
	system("cls");
	bool flag = false;
	for (int j = 0; j < i; j++) {
		if (book[j].author == name) {
			cout << book[j].author << " " << book[j].name << " " << book[j].publisher << " " << book[j].section;
			switch (book[j].orign) {
			case buy: cout << " �������" << " "; break;
			case theft: cout << " �����" << " "; break;
			case gift: cout << " �������" << " "; break;
			}
			cout << book[j].availability << " " << endl;
			flag = true;
			cout << endl;
		}
	}
	if (!flag)
		cout << "������ �� �������\n";
	system("pause");
}
