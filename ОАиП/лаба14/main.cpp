#include "Hash.h"
#include <iostream>
#include<string>
using namespace std;

int key(void* d)
{
	AAA* f = (AAA*)d;   return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
////-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	//AAA a1(1, "one"), a2(2, "two"), a3(4, "three"), a4(2, "fo");
	int siz = 10, choice, k;
	cout << "������� ������ ���-�������" << endl; 	cin >> siz;
	Object H = create(siz, key);

	for (;;)
	{
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan();  break;
		case 2: { AAA* a = new AAA;
			char* str = new char[500];
			//string str;
			cout << "������� ����" << endl;	cin >> k;
			while (H.search(k)) {
				cout << "����� ���� ��� ����!\n������� ������: ";
				cin >> k;
			}

			a->key = k;
			cout << "������� �����" << endl;
			cin >> str;
			/*getchar();
			getline(cin, str);*/
			a->mas = str;
			if (H.N == H.size)
				cout << "������� ���������" << endl;
			else
				H.insert(a);
		} break;
		case 3: {  cout << "������� ���� ��� ��������" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "������� ���� ��� ������" << endl;
			cin >> k;
			unsigned int start = clock();
			if (H.search(k) == NULL)
				cout << "������� �� ������" << endl;
			else
				AAA_print(H.search(k));
			unsigned int end = clock();
			float dif = end - start;
			cout << endl << dif << " ��\n";
		}  break;
		}
		if (H.N == (H.size / 2)) {
			Object NewT = create(H.size * 2, key);
			for (int i = 0; i < H.size; i++)
			{
				if ((H.data)[i] == NULL)
					continue;
				else
					if ((H.data)[i] == DEL)
						continue;
					else
						NewT.insert(H.data[i]);
			}
			H = NewT;
		}
	}
	return 0;
}
