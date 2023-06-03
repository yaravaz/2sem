#include "tree.h"
#include <fstream>
int sum2 = 0;

void main()
{
	setlocale(LC_ALL, "rus");
	Tree* mainRoot = new Tree;
	int choice;


	while (1)
	{
		int numRight = 0;
		if (!mainRoot->node) cout << "������ ������.\n";
		else mainRoot->PrintTree(mainRoot->node, 0);
		cout << "\n";
		cout << "1 - �������� �������\n";
		cout << "2 - ������� �������\n";
		cout << "3 - ���������� ����� ������\n";
		cout << "4 - ��������� �����\n";
		cout << "5 - �������� �� ������������������\n";
		cout << "6 - ������� ���������� ������\n";
		cout << "0 - �����\n";
		cout << "��� �����: ";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 1:
		{
			int value;
			cout << "������� �������" << endl;
			string temp;
			cin >> temp;
			char temp1[10] = "         ";
			bool flag = false;
			for (int i = 0; i < temp.length(); i++) {
				if (temp[i] == '.')
					flag = true;
			}
			for (int i = 0; i < temp.length(); i++) {
				temp1[i] = temp[i];
			}
			if (flag == false)
				value = atoi(temp1);
			else {
				cout << "������������ ��������" << endl;
				break;
			}
			mainRoot->AddNode(value);
			break;
		}

		case 2:
		{
			int key;
			cout << "������� ��������� �������: "; cin >> key;
			mainRoot->Delete(key);
			break;
		}

		case 3:
		{
			if (!mainRoot->node) cout << "������ ������.\n";
			else mainRoot->DirectBypass(mainRoot->node);
			break;
		}

		case 4:
		{
			if (!mainRoot->node) cout << "������ ������.\n";
			else mainRoot->ReverseBypass(mainRoot->node);
			break;
		}

		case 5:
		{
			mainRoot->counter = 0;
			if (!mainRoot->node) cout << "������ ������.\n";
			else
				if (mainRoot->IsBalanced(mainRoot->node))
					cout << "������ ����������������." << endl;
				else
					cout << "������ �� ����������������." << endl;
			break;
		}
		case 6: {
			int key;
			cout << "\n������� ����: ";  cin >> key;
			mainRoot->countRoot(mainRoot->node, key, 0);
			break;
		}
		case 0:
		{
			exit(0);
			break;
		}

		default:
		{
			cout << "������������ ��������. ��� �����: \n";
			break;
		}

		}
	}
}
