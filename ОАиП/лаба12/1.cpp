#include <iostream>
#include <algorithm>
using namespace std;
struct Tree
{
	double  key; 
	char text[20]; 
	int rate; 
	Tree * Left, * Right;
};
Tree * makeTree(Tree * Root); 
Tree * list(double i, char* s, int rate);  
Tree * insertElem(Tree * Root, double key, char* s, int rate); 
Tree * search(Tree * n, double key);   
Tree * delet(Tree * Root, double key); 
void view(Tree * t, int level); 
void delAll(Tree * t);       
void check(int rate);
void outRate();
int r1, r2, r3;    
Tree * Root = NULL;
int R_num = 0;
float coun, sum;
void main()
{
	setlocale(0, "Russian");
	double key; int rate, choice, n;
	Tree * rc; char s[20], letter;
	for (;;)
	{
		cout << "1 - �������� ������\n";
		cout << "2 - ���������� ��������\n";
		cout << "3 - ����� �� ��������\n";
		cout << "4 - �������� ��������\n";
		cout << "5 - ����� ������\n";
		cout << "6 - ����� ������ ����������� ������\n";
		cout << "7 - ������� ������\n";
		cout << "0 - �����\n";
		cout << "��� �����?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\n������� �������: ";cin >> key;
				cout << "������� �������: "; cin >> s;
				cout << "������� �����: "; cin >> rate;
				insertElem(Root, key, s, rate); break;
		case 3:  cout << "\n������� �������: ";  cin >> key;
				rc = search(Root, key);
				cout << "�������� = ";
				puts(rc->text); break;
		case 4:  cout << "\n������� ��������� ����� ��������: "; cin >> key;
				Root = delet(Root, key);  break;
		case 5:  
			if (Root->key >= 0)
		{
			view(Root, 0);
		}
		else cout << "������ ������\n"; break;
		case 6:  outRate();  break;
		case 7:  delAll(Root); break;
		break;
		case 0:  exit(0);
		}
	}
}
Tree * makeTree(Tree * Root)
{
	double key, rate; char s[20];
	cout << "0 ��� ����� �����\n\n";
	if (Root == NULL)
	{
		cout << "������� �������: "; cin >> key;
		cout << "������� �������: "; cin >> s;
		cout << "������� �����(1,2,3): "; cin >> rate;
		check(rate);
		Root = list(key, s, rate);
	}
	while (1)
	{
		cout << "\n������� �������: ";
		cin >> key;
		if (key == 0) break;    
		cout << "������� �������: ";  cin >> s;
		cout << "������� �����: ";  cin >> rate;
		check(rate);
		insertElem(Root, key, s, rate);
	}
	return Root;
	}
void check(int rate)
{
	if (rate == 1)
	r1++;
	if (rate == 2)
	r2++;
	if (rate == 3)
	r3++;
}
void outRate()
{
	int maximum = max(r1, max(r2, r3));
	if (maximum == r1)
		cout << "�������� ���������� ����� 1, � ����������� ��������� " << r1 << endl;
	if (maximum == r2)
		cout << "�������� ���������� ����� 2, � ����������� ��������� " << r2 << endl;
	if (maximum == r3)
		cout << "�������� ���������� ����� 3, � ����������� ��������� " << r3 << endl;
	}
Tree * list(double i, char* s, int rate)
{
	Tree * t = new Tree[sizeof(Tree)];
	t->key = i;
	t->rate = rate;
	for (i = 0; i < 20; i++)
    * ((t->text) + (int)i) = *(s + (int)i);
	t->Left = t->Right = NULL;
	return t;
	}
Tree * insertElem(Tree * t, double key, char* s, int rate) 
{
	Tree * Prev = NULL;	 
	int find = 0;  
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
		    find = 1;
		else
			if (key < t->key) t = t->Left;
		else t = t->Right;
    }
	if (!find) 
	{
		t = list(key, s, rate); 
		if (key < Prev->key)  
			Prev->Left = t; 
		else
			Prev->Right = t; 
	}
		return t;
	}
Tree * delet(Tree * Root, double key){	
	Tree * Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key) 
	{
	Prev_Del = Del;
	if (Del->key > key)
		Del = Del->Left;
	else
		Del = Del->Right;
	}
	if (Del == NULL)              
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL)
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
		Prev_R = Del; 
		R = Del->Left;
		while (R->Right != NULL)
		{
			Prev_R = R;
			R = R->Right;
		}
		if (Prev_R == Del)  
			R->Right = Del->Right;
		else
		{
			R->Right = Del->Right;
			Prev_R->Right = R->Left;
			R->Left = Prev_R;
		}
		}
		if (Del == Root) Root = R;
		else
		
			if (Del->key < Prev_Del->key)
				Prev_Del->Left = R; 
			else
				Prev_Del->Right = R;
		double tmp = Del->key;
		cout << "\n������ ������� � ������ " << tmp << endl;
		delete Del;
		return Root;
	}
Tree * search(Tree * n, double key) 
{
	Tree * rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
		}
	else
		cout << "��� ������ ��������\n";
	return rc;
}
void view(Tree * t, int level)
{
	if (t)
	{
		view(t->Right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "   ";
		long long tm = long long(t->key);
		int tm1 = t->rate;
		cout << tm << ' ' << tm1 << ' ';
		puts(t->text);
		view(t->Left, level + 1);
		}
	}
void delAll(Tree * t) 
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}