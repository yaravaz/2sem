#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

struct Stack
{
	int data;
	Stack* head;
	Stack* next;
};

ifstream fin;

void show(Stack* myStk);
void push(int x, Stack* myStk);
void clear(Stack* myStk);
void fromfile();

string str;
bool flag;

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Stack* mystk = new Stack;
	mystk->head = NULL;
	
	int min = 100, counter = 0, numbofmin;

	fin.open("text.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, str);
			push(size(str), mystk);
			counter++;
			if (min >= size(str)) {
				min = size(str);
				numbofmin = counter;
			}
		}
	}
	else {
		cout << "error" << endl;
		exit(-1);
	}

	cout << "Стек: \n";
	show(mystk);

	cout << "Номер самой маленькой строки " << numbofmin << "\nДлина минимальной строки " << min << endl;

	clear(mystk);

	system("pause");
	fin.close();
}

void push(int x, Stack* myStk)
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
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
}

void clear(Stack* myStk) {

	while (myStk->head != NULL) {
		Stack* e = myStk->head;
		int a = myStk->head->data;
		myStk->head = myStk->head->next;
		delete e;
	}
}