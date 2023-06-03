#include "stdafx.h"

int counter = 0;

void PushQ(Q* queue, int Size) {
	Q* el = new Q;
	el->next = NULL;
	char simb;
	cout << "������� ������� ������� "; cin >> simb;
	if (counter == 0) {
		el->a = simb;
		queue->head = el;
		queue->tail = el;
	}
	else if (counter == Size) {
		cout << "�������� ����������� ������ �������\n";
		system("pause");
		exit(0);
	}
	else {
		el->a = simb;
		queue->tail->next = el;
		if (queue->tail->next->a == queue->tail->a) {
			PopQ(queue);
		}
		queue->tail = el;
	}
	counter++;
}

void ViewQ(Q* queue) {
	Q* el = queue->head;
	if (el == NULL) {
		cout << "������� �����\n";
		system("pause");
		return;
	}
	else {
		while (el != NULL) {
			cout << el->a << ' ';
			el = el->next;
		}
		cout << endl;
	}
	system("pause");
}

int SizeQ(Q* queue) {
	Q* el = queue->head;
	int count = 0;
	if (el == NULL) {
		cout << "������� �����\n";

	}
	else
		while (el != NULL) {
			count++;
			el = el->next;
		}
	return count;
}

void PopQ(Q* queue) {
	int count = 0;
	cout << "������� ������� ";
	while (queue->head != NULL && count != 3) {
		Q* el = queue->head;
		char a = el->a;
		queue->head = queue->head->next;
		delete el;
		count++;
		counter--;
		cout << a << ' ';
	}
	cout << endl;
	system("pause");
}