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
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� ������: ";
	cin.ignore();
	getline(cin, temp->data.author);
	cout << "������� ��������: ";
	getline(cin, temp->data.name);
	cout << "������� ������������: ";
	getline(cin, temp->data.publish);
	cout << "���: ";
	getline(cin, temp->data.type);
	cout << "������� ������������: ";
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
		cout << "������ ����!" << endl;
	}
	while (t)
	{
		cout << "�����:" << t->data.author << endl;
		cout << "��������" << t->data.name << endl;
		cout << "������������:" << t->data.publish << endl;
		cout << "���:" << t->data.type << endl;
		cout << "�������������:" << t->data.origin << endl;
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
		cout << "�������� �� �������" << endl;
		return;
	}

	cout << "�����:" << t->data.author << endl;
	cout << "��������:" << t->data.name << endl;
	cout << "������������:" << t->data.publish << endl;
	cout << "���:" << t->data.type << endl;
	cout << "������������:" << t->data.origin << endl;
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
	cout << "���������� ���������=" << i << endl;
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
	cout << "\n������ ������!" << endl;
}
void dop1()
{
	address* head = NULL;
	address* last = NULL;
	setlocale(LC_CTYPE, "rus");
	int choice;
	int c;
	cout << endl;
	cout << "1. ���� ��������" << endl;
	cout << "2. ����� �� �����" << endl;
	cout << "3. �����" << endl;
	cout << "4. ���������� ���������" << endl;
	cout << "5. �������� ������" << endl;
	cout << "6. �����" << endl;
	cout << endl;
	while (true)
	{
		cout << "\n��� �����: ";
		cin >> choice;
		switch (choice)
		{
		case 1: insert(setelement(), &head, &last);
			break;
		case 2: outputlist(&head, &last);
			break;
		case 3: { string fnumber;
			cout << "\n������� ��������: ";
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
		default: cout << "\n�������� ����";
		}
	}
}