#include <iostream>
#include "stdafx.h"
#include "List.h"
#include <string>

using namespace std;
void insert(address* e, address** phead, address** plast)
{
	address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

address* setelement()
{
	address* temp = new address();
	if (!temp)
	{
		cerr << "ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "введите автора: ";
	cin.ignore();
	getline(cin, temp->data.author);
	cout << "введите название: ";
	getline(cin, temp->data.name);
	cout << "введите издательство: ";
	getline(cin, temp->data.publish);
	cout << "тип: ";
	getline(cin, temp->data.type);
	cout << "введите происходение: ";
	getline(cin, temp->data.origin);

	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void outputlist(address** phead, address** plast)
{
	address* t = *phead;
	if (t == NULL)
	{
		cout << "список пуст!" << endl;
	}
	while (t)
	{
		cout << "автор:" << t->data.author << endl;
		cout << "название" << t->data.name << endl;
		cout << "издательство:" << t->data.publish << endl;
		cout << "тип:" << t->data.type << endl;
		cout << "происхождение:" << t->data.origin << endl;
		t = t->next;
	}
	cout << "" << endl;
}
void find(string fname, address** phead)
{
	address* t = *phead;
	while (t)
	{
		if (fname == t->data.name) break;
		t = t->next;
	}
	if (!t)
	{
		cout << "название не найдено" << endl;
		return;
	}

	cout << "автор:" << t->data.author << endl;
	cout << "название:" << t->data.name << endl;
	cout << "издательство:" << t->data.publish << endl;
	cout << "тип:" << t->data.type << endl;
	cout << "происходение:" << t->data.origin << endl;
}
void countlist(address** phead, address** plast)
{
	address* t = *phead;
	int i = 0;
	while (t != NULL)
	{
		i++;
		t = t->next;
	}
	cout << "количество элементов=" << i << endl;
}
void delall(address*& phead, address*& plast)
{
	address* t = phead, * p;
	while (t != NULL)
	{

		if (phead == t)
		{
			phead = t->next;
			if (phead)
				(phead)->prev = NULL;
			else
				plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != plast)
				t->next->prev = t->prev;
			else
				plast = t->prev;
		}
		p = t;
		t = t->next;
		delete p;
	}
	cout << "\nсписок очищен!" << endl;
}
void dop1()
{
	address* head = NULL;
	address* last = NULL;
	setlocale(LC_CTYPE, "rus");
	int choice;
	int c;
	cout << endl;
	cout << "1. ввод элемента" << endl;
	cout << "2. вывод на экран" << endl;
	cout << "3. поиск" << endl;
	cout << "4. количество элементов" << endl;
	cout << "5. очищение списка" << endl;
	cout << "6. выход" << endl;
	cout << endl;
	while (true)
	{
		cout << "\nваш выбор: ";
		cin >> choice;
		switch (choice)
		{
		case 1: insert(setelement(), &head, &last);
			break;
		case 2: outputlist(&head, &last);
			break;
		case 3: { string fnumber;
			cout << "\nвведите название: ";
			cin.ignore();
			getline(cin, fnumber);
			find(fnumber, &head);
		}
			  break;
		case 4: {

			countlist(&head, &last);
		}
			  break;
		case 5: {
			delall(head, last);
		}
			  break;
		case 6: return;
		default: cout << "\nневерный ввод";
		}
	}
}