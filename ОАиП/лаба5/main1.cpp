#include <iostream>
#include <string>

using namespace std;

int n = 100;

struct dat {
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 5;
};

enum type {
	emergency = 1, preferential, payment, credit
};

struct client {
	string name;
	string surname;
	string secondname;
	int type;
	int number;
	float sum;
	dat data_now;
};

void input();
void output();
void deleted();
void find(string lastName);

string str, surname;
bool flag1, check;
int i;
client clients[10];

int main() {
	setlocale(LC_CTYPE, "Rus");

	while (true) {
		system("cls");
		cout << "��� �� ������ �������?\n1 - ������ �������\n2 - ������� ����������\n3 - ������� �������\n4 - ����� �������\n0 - �����\n";
		cin >> str;

		if (str[0] < '0' || str[0] > '4' || size(str) > 1) {
			system("cls");
			cout << "������������ ��������" << endl;
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
			deleted();
			break;
		case 4: 
			while (true) {
				flag1 = false;
				cout << "������� �������: ";
				cin >> str;
				for (int j = 0; j < size(str); j++) {
					if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
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
			surname = str;
			find(surname);
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
		cout << "���: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
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
	clients[i].name = str;

	while (true) {
		flag1 = false;
		cout << "�������: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
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
	clients[i].surname = str;

	while (true) {
		flag1 = false;
		cout << "��������: ";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
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
	clients[i].secondname = str;

	while (true) {
		cout << "1 - �������\n2 - ��������\n3 - ���������\n4 - ���������\n";
		cin >> str;

		if (str[0] < '1' || str[0] > '4' || size(str) > 1) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}
	clients[i].type = stoi(str);
	while (true) {
		check = true;
		cout << "����� �����: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
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
	clients[i].number = stoi(str);

	while (true) {
		check = true;
		cout << "����� �� �����: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
			if (str[j] == '.') {
				check = true;
			}
		}
		if (!check || stoi(str) > 100) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}
	clients[i].sum = stof(str);

	cout << "���� ���������� ���������:\n";
	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (true) {
		check = true;
		cout << "����� ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		if (!check || stoi(str) > 12) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		break;
	}
	clients[i].data_now.month = stoi(str);

	while (true) {
		check = true;
		cout << "���: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
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
	clients[i].data_now.year = stoi(str);
	int year;
	while (true) {
		check = true;
		cout << "����: ";
		cin >> str;

		for (int j = 0; j < size(str); j++) {
			if (str[j] < '0' || str[j] > '9') {
				check = false;
			}
		}
		year = 2000 + clients[i].data_now.year;
		if ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0))) {
			if (clients[i].data_now.month == 2 && stoi(str) > 29) {
				check = false;
			}
			if (clients[i].data_now.month != 2 && stoi(str) > months[clients[i].data_now.month - 1]) {
				check = false;
			}
		}
		else {
			if (stoi(str) > months[clients[i].data_now.month - 1]) {
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
	clients[i].data_now.day = stoi(str);
	i++;
}

void output() {
	system("cls");
	for (int j = 0; j < i; j++) {
		cout << clients[j].name << " " << clients[j].surname << " " << clients[j].secondname << " ";
		switch (clients[j].type) {
		case emergency: cout << "�������" << " "; break;
		case preferential: cout << "��������" << " "; break;
		case payment: cout << "���������" << " "; break;
		case credit: cout << "���������" << " "; break;
		}
		cout << clients[j].number << " " << clients[j].sum << " ";
		if (clients[j].data_now.day < 10)
			cout << "0" << clients[j].data_now.day << ".";
		else
			cout << clients[j].data_now.day << ".";
		if (clients[j].data_now.month < 10)
			cout << "0" << clients[j].data_now.month << ".";
		else
			cout << clients[j].data_now.month << ".";
		if(clients[j].data_now.year < 10)
			cout << "0" << clients[j].data_now.year << endl;
		else
			cout << clients[j].data_now.year << endl;
		
	}
	system("pause");
}

void find(string lastName) {
	system("cls");
	bool flag = false;
	for (int j = 0; j < i; j++) {
		if (clients[j].surname == lastName) {
			cout << clients[j].name << " " << clients[j].surname << " " << clients[j].secondname << " ";
			switch (clients[j].type) {
			case emergency: cout << "�������" << " "; break;
			case preferential: cout << "��������" << " "; break;
			case payment: cout << "���������" << " "; break;
			case credit: cout << "���������" << " "; break;
			}
			cout << clients[j].number << " " << clients[j].sum << " ";
			if (clients[j].data_now.day < 10)
				cout << "0" << clients[j].data_now.day << ".";
			else
				cout << clients[j].data_now.day << ".";
			if (clients[j].data_now.month < 10)
				cout << "0" << clients[j].data_now.month << ".";
			else
				cout << clients[j].data_now.month << ".";
			if (clients[j].data_now.year < 10)
				cout << "0" << clients[j].data_now.year << endl;
			else
				cout << clients[j].data_now.year << endl;
			flag = true;
			cout << endl;
		}
	}
	if (!flag)
		cout << "������ �� �������\n";
	system("pause");
}

void deleted() {
	system("cls");
	while (true) {
		cout << "������ ������� ���������? ������� ������� \n";
		cin >> str;
		for (int j = 0; j < size(str); j++) {
			if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= '�' && str[j] <= '�') || (str[j] >= '�' && str[j] <= '�'))) {
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
	for (int j = 0; j < i; j++) {
		if (clients[j].surname == str) {
			for (int k = j; k < i; k++) {
				clients[k] = clients[k + 1];
			}
			i--;
		}
		else
			cout << "�� �������\n";
	}
}

