#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Stack
{
	char data;
	Stack* head;
	Stack* next;
};


void show(Stack* myStk);
void push(char x, Stack* myStk);
void clear(Stack* myStk);

string str;
bool flag;

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Stack* mystk = new Stack;
	mystk->head = NULL;
	while (true) {
		cout << "Введите строку с чётным количеством символов: ";
		getline(cin, str);
		if (size(str) % 2 != 0) {
			system("cls");
			cout << "Некорректное значение\n";
			system("pause");
		}
		else {
			break;
		}
	}
	for (int i = 0; i < size(str) / 2; i++) {
		push(str[i], mystk);
	}
	show(mystk);
	clear(mystk);
	for (int i = size(str) / 2; i < size(str); i++) {
		push(str[i], mystk);
	}
	show(mystk);
	clear(mystk);
}

void push(char x, Stack* myStk)
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
}
void show(Stack* myStk)
{
	Stack* e = myStk->head;
	char a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;
		cout << a;
		e = e->next;
	}
}

void clear(Stack* myStk) {

	while (myStk->head != NULL) {
		Stack* e = myStk->head;
		char a = myStk->head->data;
		myStk->head = myStk->head->next;
		delete e;
	}
}
