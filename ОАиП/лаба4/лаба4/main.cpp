#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

struct Library {
	string author;
	string name;
	string publisher;
	string section;
	string origin;
	string availability;
};

void input();
void output();
void find(string writer);
void deleted();
void element();

int i; string file = "database.txt";
Library book[20];

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n; string writer; bool flag = true;

	while (flag) {
		system("cls");
		cout << "����� ���������� � ����������, ��� �� ������ �������?\n";
		cout << "1 - ������ ���������� � �����\n";
		cout << "2 - ������� ���������� �� ������\n";
		cout << "3 - ����� ������\n";
		cout << "4 - ������� ���������� �� ������\n";
		cout << "5 - ������� ����������� ��������� �� ������\n";
		cout << "0 - �����\n";
		cin >> n;
		switch (n) {
		case(1):
			input();
			break;
		case(2):
			output();
			break;
		case(3):
			cout << "������ ������ �� �����?\n";
			cin.ignore();
			getline(cin, writer);
			find(writer);
			break;
		case(4):
			deleted();
			break;
		case(5):
			element();
			break;
		case(0):
			flag = false;
			break;
		}
	}
	return 0;
}

void input() {
	cin.ignore();
	cout << "������� ����������, ������� ������ ��������\n";
	cout << "�����: "; 
	getline(cin, book[i].author);
	cout << "��������: ";
	getline(cin, book[i].name);
	cout << "������������: ";
	getline(cin, book[i].publisher);
	cout << "������(����������� ����������, �����, �������� ���������, ������������� � �. �.): ";
	getline(cin, book[i].section);
	cout << "������������� (�������, �����, �������): ";
	getline(cin, book[i].origin);
	cout << "�������: ";
	getline(cin, book[i].availability);
	ofstream out;
	out.open(file, ios::app);
	out << book[i].author << " " << book[i].name << " " << book[i].publisher << " " << book[i].section << " " << book[i].origin << " " << book[i].availability << endl;
	i++;
	out.close();
}

void output() {
	ifstream in;
	string str;

	in.open(file);
	while (!in.eof()) {
		getline(in, str);
		cout << str << endl;
	}
	in.close();
	system("pause");
}

void find(string writer) {
	int counter = 0;
	for (int j = 0; j < i; j++) {
		if (book[j].author == writer) {
			cout << book[j].author << " " << book[j].name << " " << book[j].publisher << " " << book[j].section << " " << book[j].origin << " " << book[j].availability << endl;
			counter++;
		}
	}
	if (counter == 0) {
		cout << "������ ��� � ������\n";
	}
	system("pause");
}

void deleted() {
	string name;
	ofstream out;
	out.open(file);
	cout << "���������� � ����� ����� �� ������ �������? \n";
	cin.ignore();
	getline(cin, name);
	for (int j = 0; j < i; j++) {
		if (book[j].name == name) {
			for (int k = j; k < i; k++) {
				book[k] = book[k + 1];
			}
			i--;
			out << book[j].author << " " << book[j].name << " " << book[j].publisher << " " << book[j].section << " " << book[j].origin << " " << book[j].availability << endl;
		}
		else {
			out << book[j].author << " " << book[j].name << " " << book[j].publisher << " " << book[j].section << " " << book[j].origin << " " << book[j].availability << endl;
		}
	}
	out.close();
}

void element() {
	int n;
	cout << "������� ���������, ������� ������ ���������� \n";
	cout << "1 - ����� \n";
	cout << "2 - ��������: \n";
	cout << "3 - ������������: \n";
	cout << "4 - ������(����������� ����������, �����, �������� ���������, ������������� � �. �.): \n";
	cout << "5 - ������������� (�������, �����, �������): \n";
	cout << "6 - �������: \n";
	cin >> n;
	switch (n) {
	case(1): 
		for (int j = 0; j < i; j++) {
			cout << book[j].author << endl;
		}
		break;
	case(2):
		for (int j = 0; j < i; j++) {
			cout << book[j].name << endl;
		}
		break;
	case(3):
		for (int j = 0; j < i; j++) {
			cout << book[j].publisher << endl;
		}
		break;
	case(4):
		for (int j = 0; j < i; j++) {
			cout << book[j].section << endl;
		}
		break;
	case(5):
		for (int j = 0; j < i; j++) {
			cout << book[j].origin << endl;
		}
		break;
	case(6):
		for (int j = 0; j < i; j++) {
			cout << book[j].availability << endl;
		}
		break;
	}
	system("pause");
}