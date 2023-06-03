#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct list {
	char number;
	list* next;
};


void input(list* &p, char val);
void output(list*);
bool empty(list*);
int del(list* &p, char val);
void find(list*, char val);
void infile(list*);
void fromfile();

int n;
bool flag;

ofstream fout;
ifstream fin;

int main() {
	setlocale(LC_CTYPE, "Russian");

	list* first = NULL;
	char value;
	flag = true;

	while (flag) {
		system("cls");
		cout << "Что вы хотите сделать?\n1 - Ввод символа\n2 - Удаление символа\n3 - Поиск элемента\n4 - Запись в файл\n5 - Вывести из файла\n0 - Выход " << endl;
		cin >> n;
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
				cout << "Введите удаляемый символ: ";
				cin >> value;
				del(first, value);
			}
			else
				cout << "Список пуст" << endl;
			system("pause");
			break;
		}
		case 3: 
			cout << "Введите символ: ";
			cin >> value; 

			find(first, value); 
			system("pause");
			break;
		case 4: infile(first); break;
		case 5: fromfile(); break;
		case 0: exit(0);
		}

	} 

	return 0;
}

void input(list*& p, char val) {
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
		cout << " NULL" << endl;
	}
}


int del(list*& p, char val) {
	list* previous, * current, * temp;
	if (val == p->number) {
		temp = p;
		p = p->next;
		delete temp;
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
			return val;
		}
	}

	return 0;
}

void find(list* p, char val) {
	int i;
	i = 0;
	while (p != NULL && p->number != val)
	{
		++i;
		p = p->next;

	}
	if (p != NULL) cout << i + 1 << " элемент искомый ";
	if (p->next != NULL) cout << "|следующий элемент:" << p->next->number << endl;
	else cout << "|элемент последний" << endl;

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
	while (!fin.eof()) {
		getline(fin, str);
		cout << str << endl;
	}
	system("pause");
	fin.close();
}