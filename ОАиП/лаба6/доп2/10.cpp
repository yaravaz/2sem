#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct list {
	float number;
	list* next;
};

void input(list*& p, float val);
void output(list*);
float del(list*& p, float val);
void sum(list*);
void find(list*, float val);
void infile(list*);
void fromfile();

int n;
string str;

ofstream fout;
ifstream fin;

int main() {
	setlocale(LC_CTYPE, "Russian");

	list* first = nullptr;
	float value;
	bool flag = true;

	while (flag) {
		system("cls");

		cout << "Что вы хотите сделать?: \n1 - ввод числа\n2 - удаление числа\n3 - найти произведение\n4 - поиск элемента\n5 - запись в файл\n6 - вывести из файл\n" << endl;
		cin >> str;

		if (str[0] < '0' || str[0] > '6' || size(str) > 1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		n = stoi(str);

		switch (n) {
		case 1: {
			cout << "Введите символ: ";
			cin >> value;

			input(first, value);
			output(first);
			system("pause");

			break;
		}

		case 2: {
			if (!first == NULL) {
				cout << "Введите удаляемое число: ";
				cin >> value;
				del(first, value);
			}
			else
				cout << "Список пуст" << endl;
			break;
		}
		case 3:
			sum(first);
			system("pause");
			break;
		case 4:
			cout << "Введите символ: ";
			cin >> value;

			find(first, value);
			system("pause");
			break;
		case 5: infile(first); break;
		case 6: fromfile(); break;
		case 0: exit(0);
		default:
			system("cls");
			cout << "Некорректное значение\n";
			system("pause");
			break;
		}

	}

	return 0;
}

void input(list*& p, float val) {
	list* newP = new list;
	if (newP != NULL) {
		newP->number = val;
		newP->next = p;
		p = newP;
	}
	else {
		cout << "error" << endl;
	}
}

void output(list* p) {
	if (p == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		cout << "Список: " << endl;
		while (p != NULL) {
			cout << p->number << " -> ";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
}

float del(list*& p, float val) {
	list* previous, * current, * temp;
	if (val == p->number) {
		temp = p;
		p = p->next;
		delete temp;
		output(p);
		cout << "\n";
		system("pause");
		return val;
	}
	else {
		previous = p;
		current = p->next;
		while (current != NULL && current->number != val)
		{
			previous = current;
			current = current->next;
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			free(temp);
			output(p);
			cout << "\n";
			system("pause");
			return val;
		}
	}
	return 0;
}

void sum(list* p) {
	int count = 0;
	float def = 1;
	if (p == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		while (p != NULL) {
			if (p->number < 10) {
				def *= p->number;
				count++;
			}
			p = p->next;
		}

		cout << "Произведение: " << def << endl;
	}
}

void infile(list* p) {
	fout.open("file.txt");
	if (p == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		if (fout.is_open()) {
			while (p != NULL) {
				fout << p->number << " -> ";
				p = p->next;
			}
			fout << "NULL";

			cout << "Запись в файл успешна завершена" << endl;
			fout.close();
		}
		else {
			cout << "error" << endl;
		}
	}
	system("pause");
}

void fromfile() {
	string str;

	fin.open("file.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, str);
			cout << str << endl;
		}
	}
	else {
		cout << "error" << endl;
	}
	fin.close();
	system("pause");
}

void find(list* p, float val) {
	int i;
	i = 0;
	while (p != NULL && p->number != val)
	{
		++i;
		p = p->next;

	}
	if (p != NULL) cout << i + 1 << " элемент искомый\n ";
}