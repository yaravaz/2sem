#include "stdafx.h"

string str;
bool flag;

int menu() {
	flag = true;
	while (flag) {
		system("cls");
		cout << "��� �� ������ �������?:\n1 - ���������� �������� � ����\n2 - ���������� �������� �� �����\n3 - ����� �����\n4 - ������� �����\n5 - ��������\n6 - �������� � ����\n7 - ��������� �� �����\n0 - �����\n";
		cin >> str;
		if (str[0] < '0' || str[0] > '7' || size(str) > 1) {
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
	Stack* mystk = new Stack;
	mystk->head = NULL;

	while (true) {
		int n = menu();
		switch (n) {
		case 1:
			while (true) {
				flag = true;
				cout << "������� �������: " << endl;
				cin >> str;

				for (int i(0); i < size(str); i++) {
					if (!isdigit(str[i])) {
						if (str[i] = '-') {
							continue;
						}
						system("cls");
						cout << "������������ ��������\n";
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
				cout << "����������� �������: " << n << endl;
			system("pause");
			break;
		case 3: cout << "���� ����: " << endl;
			show(mystk);
			system("pause");
			break;
		case 4:
			clear(mystk);
			cout << "���� ������\n";
			system("pause");
			break;
		case 5:
			if (prov(mystk)) {
				cout << "����� �������� ����\n";
			}
			else cout << "����� ��������� ���\n";
			system("pause");
			break;
		case 6: infile(mystk); break;
		case 7: fromfile(); break;
		case 0: exit(0);
		}
	}
}
