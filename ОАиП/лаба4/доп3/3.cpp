#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

void input();
void output();
void find();

struct sanatory {
	string name;
	string location;
	int profile;
	int num;
};

int choice;
int i = 0;
struct sanatory sanatories[30];
string str;

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		system("cls");
		cout << "��� �� ������ �������?\n1 - �������� ���������\n2 - ������� ������\n3 - ����� ���������\n0 - �����" << endl;
		cin >> str;

		if (str[0] < '0' || str[0] > '3' || size(str) > 1) {
			system("cls");
			cout << "������������ ��������" << endl;
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
		case 3:
			find();
			break;
		case 0:
			exit(0);
		}
	}
}

void input() {
	system("cls");
	bool flag1;
	while (true) {
		flag1 = false;
		cout << "��������: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
				if (str[j] == ' ' || str[j] == '-')
					break;
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
	sanatories[i].name = str;

	while (true) {
		flag1 = false;
		cout << "����� ������������: ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
				if (str[j] == ' ' || str[j] == '-')
					break;
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
	sanatories[i].location = str;

	while (true) {
		cout << "�������� ������� (1 - �������, 2 - ������): ";

		cin >> str;

		if (str[0] < '1' || str[0] > '2' || size(str) > 1) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}
	sanatories[i].profile = stoi(str);

	bool check;
	while (true) {
		check = true;
		cout << "���������� �������: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '1' || str[j] > '9') {
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
	sanatories[i].num = stoi(str);
	i++;
	cout << endl << endl;
}

void sort() {
	struct sanatory buf;
	for (int j = 0; j < i - 1; j++) {
		for (int k = j; k < i; k++) {
			if (sanatories[j].name > sanatories[k].name) {
				buf = sanatories[k];
				sanatories[k] = sanatories[j];
				sanatories[j] = buf;
			}
		}
	}
}

void output() {
	system("cls");
	sort();
	cout << "____________________________________________________________________________________\n";
	cout << "|       ��������      |   �����������������   |     �������     |  ���-�� ������  |\n";
	cout << "|_____________________|_______________________|_________________|__________________|\n";
	for (int j = 0; j < i; j++) {
		if (sanatories[j].profile == 1) {
			cout << "| " << sanatories[j].name << setw(22 - size(sanatories[j].name)) << "| ";
			cout << sanatories[j].location << setw(24 - size(sanatories[j].location)) << "| ";
			cout << "��������������� | ";
			cout << sanatories[j].num << setw(19 - size(to_string(sanatories[j].num))) << "|\n";
			cout << "|_____________________|_______________________|_________________|__________________|\n";
		}
	}
	for(int j = 0; j < i; j++){
		if (sanatories[j].profile == 2) {
			cout << "| " << sanatories[j].name << setw(22 - size(sanatories[j].name)) << "| ";
			cout << sanatories[j].location << setw(24 - size(sanatories[j].location)) << "| ";
			cout << "��������        | ";
			cout << sanatories[j].num << setw(19 - size(to_string(sanatories[j].num))) << "|\n";
			cout << "|_____________________|_______________________|_________________|__________________|\n";
		}
	}

	system("pause");
}

void find() {
	bool flag1;
	system("cls");
	bool flag = false;
	string str;
	
	while (true) {
		flag1 = false;
		cout << "������� �������� ���������, ������� ������ ����� ";
		cin.ignore();
		getline(cin, str);
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
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

	for (int j = 0; j < i; j++) {
		if (sanatories[j].name == str) {
			cout << sanatories[j].name << " " << sanatories[j].location << " ";
			if (sanatories[j].profile == 1) {
				cout << "��������������� ";
			}
			else {
				cout << "�������� ";
			}
			cout << sanatories[j].num << endl;
			flag = true;
		}
	}
	if (!flag)
		cout << "������ �� �������\n";
	system("pause");
}