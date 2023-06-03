#include "stdafx.h"

int menu() {
	bool flag = true;
	string str;
	while (flag) {
		system("cls");
		cout << "��� �� ������ �������?:\n1 - ���������� �������� � �������\n2 - ����� �������\n3 - ������ �������\n0 - �����\n";
		cin >> str;
		if (str[0] < '0' || str[0] > '3' || size(str) > 1) {
			system("cls");
			cout << "������������ ��������" << endl;
			system("pause");
			continue;
		}
		flag = false;
	}
	return(stoi(str));
}

int main() {
	setlocale(LC_CTYPE, "rus");
	bool flag = true;
	Q* queue = new Q;
	queue->head = queue->tail = NULL;
	cout << "������� ������������ ������ ������� ";
	int Size;
	cin >> Size;
	while (flag) {
		switch (menu()) {
		case 1: PushQ(queue, Size); break;
		case 2: ViewQ(queue); break;
		case 3: cout << SizeQ(queue) << endl; system("pause"); break;
		case 0: flag = false; break;
		}
	}

	return 0;
}