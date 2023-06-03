#include "stdafx.h"

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

bool prov(Stack* myStk) {
	bool flag = false;
	Stack* e = myStk->head;
	Stack* e1 = myStk->head->next;
	while (e1->next != NULL) {
		if (e->data == e1->data)
			flag = true;
		e = e1;
		e1 = e1->next;
	}
	if (e->data == e1->data)
		flag = true;
	return flag;
}

void infile(Stack* myStk) {
	fout.open("file.txt");
	Stack* e = myStk->head;
	if (e == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		if (fout.is_open()) {
			while (e != NULL) {
				fout << e->data << " ";
				e = e->next;
			}

			cout << "Запись в файл успешна завершена" << endl;
			fout.close();
		}
		else {
			cout << "error" << endl;
		}
	}
	delete e;
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
	system("pause");
}