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
		cout << "Добро пожаловать в библиотеку, что вы хотите сделать?\n";
		cout << "1 - Ввести информацию в архив\n";
		cout << "2 - Вывести информацию из архива\n";
		cout << "3 - Найти автора\n";
		cout << "4 - Удалить информацию из архива\n";
		cout << "5 - Вывести определённую категорию из архива\n";
		cout << "0 - Выйти\n";
		cin >> n;
		switch (n) {
		case(1):
			input();
			break;
		case(2):
			output();
			break;
		case(3):
			cout << "Какого автора вы ищите?\n";
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
	cout << "Введите информацию, которую хотите добавить\n";
	cout << "Автор: "; 
	getline(cin, book[i].author);
	cout << "Название: ";
	getline(cin, book[i].name);
	cout << "Издательство: ";
	getline(cin, book[i].publisher);
	cout << "Раздел(специальная литература, хобби, домашнее хозяйство, беллетристика и т. д.): ";
	getline(cin, book[i].section);
	cout << "Происхождение (покупка, кража, подарок): ";
	getline(cin, book[i].origin);
	cout << "Наличие: ";
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
		cout << "Автора нет в списке\n";
	}
	system("pause");
}

void deleted() {
	string name;
	ofstream out;
	out.open(file);
	cout << "Информацию о какой книге вы хотите удалить? \n";
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
	cout << "Введите категорию, которую хотите посмотреть \n";
	cout << "1 - автор \n";
	cout << "2 - название: \n";
	cout << "3 - издательство: \n";
	cout << "4 - раздел(специальная литература, хобби, домашнее хозяйство, беллетристика и т. д.): \n";
	cout << "5 - происхождение (покупка, кража, подарок): \n";
	cout << "6 - наличие: \n";
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