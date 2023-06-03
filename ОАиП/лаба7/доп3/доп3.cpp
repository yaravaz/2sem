#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string>

using namespace std;

struct Stack
{
	int data;
	Stack* head;
	Stack* next;
};


void show(Stack* myStk);
int pop(Stack* myStk);
void push(int x, Stack* myStk);
void clear(Stack* myStk);
void separate(Stack* myStk);

string str;
bool flag;

int menu() {
	flag = true;
	while (flag) {
		system("cls");
		cout << "Что вы хотите сделать?:\n1 - Добавление элемента в стек\n2 - Извлечение элемента из стека\n3 - Вывод стека\n4 - Очистка стека\n5 - Разделение\n0 - Выход\n";
		cin >> str;
		if (str[0] < '0' || str[0] > '5' || size(str) > 1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}
		flag = false;
	}
	return(stoi(str));
}

int main() {
	setlocale(LC_CTYPE, "rus");
	Stack* mystk = new Stack;
	mystk->head = NULL;

	while (true) {
		int n = menu();
		switch (n) {
		case 1:
			while (true) {
				flag = true;
				cout << "Введите элемент: " << endl;
				cin >> str;

				for (int i(0); i < size(str); i++) {
					if (!isdigit(str[i])) {
						if (str[i] = '-') {
							continue;
						}
						system("cls");
						cout << "Некорректное значение\n";
						system("pause");
						flag = false;
						break;
					}
				}
				if (flag) break;
			}
			n = stoi(str);
			push(n, mystk);
			break;
		case 2:
			n = pop(mystk);
			if (n != -1)
				cout << "Извлеченный элемент: " << n << endl;
			system("pause");
			break;
		case 3: cout << "Весь стек: " << endl;
			show(mystk);
			system("pause");
			break;
		case 4:
			clear(mystk);
			cout << "Стек очищен\n";
			system("pause");
			break;
		case 5:
			separate(mystk);
			break;
		case 0: exit(0);
		}
	}
}

ofstream fout;
ifstream fin;

void push(int x, Stack* myStk)
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
}
int pop(Stack* myStk)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;
	}
	else
	{
		Stack* e = myStk->head;
		int a = myStk->head->data;
		myStk->head = myStk->head->next;
		delete e;
		return a;
	}
}
void show(Stack* myStk)
{
	Stack* e = myStk->head;
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void clear(Stack* myStk) {

	while (myStk->head != NULL) {
		Stack* e = myStk->head;
		int a = myStk->head->data;
		myStk->head = myStk->head->next;
		delete e;
	}
}

void separate(Stack* myStk) {
	bool flag = false;
	Stack* e = myStk->head;
	Stack* more = new Stack;
	Stack* less = new Stack;
	more->head = NULL;
	less->head = NULL;
	while (e != NULL) {
		if (e->data <= 50) {
			push(e->data, less);
			e = e->next;
		}
		else {
			push(e->data, more);
			e = e->next;
		}
	}
	cout << "Стек с числами меньше 50\n";
	show(less);
	cout << endl;
	cout << "Стек с числами больше 50\n";
	show(more);
	cout << endl;
	system("pause");
}