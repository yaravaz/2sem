#include <iostream>
#include <vector>
#include <algorithm>
#define strsize 26
using namespace std;
struct Tree          //������
{
	int key;         //����
	char text[strsize];
	Tree* Left, * Right;
};

Tree* list(int i, char* s);       //�������� ������ ��������
void insert(Tree*& Root, Tree*& elem);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* delet(Tree* Root, int key); //�������� �������� �� �����
void view(Tree* t, int level);    //����� ������ 
int count(Tree* t, char letter);  //������� ���������� ����
void delAll(Tree* t);             //������� ������
bool countRoot(Tree* t, int key, int count);
void countRight(Tree* t, int& count);
void countEven(Tree* t, int& count);
void showLevel(Tree* t, vector <pair<int, Tree*>>& tmpv, int count);


int c = 0;         //���������� ����
Tree* Root = NULL; 	//��������� �����

void help() {
	cout << "1 - ���������� ��������\n";
	cout << "2 - ����� �� �����\n";
	cout << "3 - �������� ��������\n";
	cout << "4 - ����� ������\n";
	cout << "5 - ������� ������\n";
	cout << "6 - ����� ���� �������\n";
	cout << "7 - ����� ������ �� ����� �� �������(4)\n";
	cout << "8 - ����� ������ �������� ������(�������) (2)\n";
	cout << "9 - ����� ������ ������ (12)\n";
	cout << "10 - ����� �� �������(3)\n";
	cout << "11 - �����\n";
}

void main()
{
	setlocale(0, "Russian");
	vector <pair<int, Tree*>> tmpVect;
	int key, choice, n, tmp;
	Tree* rc; char s[5], letter;
	Tree* elem;
	bool isFind;
	help();
	for (;;)
	{

		cout << "��� �����?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  cout << "\n������� ����: "; cin >> key;
			cout << "������� �����: "; cin >> s;
			elem = list(key, s);
			insert(Root, elem);
			break;
		case 2:  cout << "\n������� ����: ";  cin >> key;
			rc = search(Root, key);
			cout << "��������� �����= ";
			puts(rc->text); break;
		case 3:  cout << "\n������� ��������� ����: "; cin >> key;
			Root = delet(Root, key);  break;
		case 4:  if (Root->key >= 0)
		{
			view(Root, 0);
		}
			  else cout << "������ ������\n"; break;
		case 5:
			delAll(Root);
			Root = NULL;
			break;
		case 6:  help();  break;
		case 7:
			cout << "\n������� ����: ";  cin >> key;
			isFind = countRoot(Root, key, 0);
			if (!isFind)
				cout << "�� ������ ����" << endl;
			break;
		case 8:
			tmp = 0;
			countRight(Root, tmp);
			cout << "���������� ������ ������: " << tmp << endl;
			break;
		case 9:
			tmp = 0;
			countEven(Root, tmp);
			cout << "���������� ������ ������: " << tmp << endl;
			break;
		case 10:
			showLevel(Root, tmpVect, 0);
			sort(tmpVect.begin(), tmpVect.end());
			if (tmpVect.size() == 0)
				break;
			cout << "������:" << tmpVect[0].second->key << " " << tmpVect[0].second->text << endl;
			for (int i = 1; i < tmpVect.size(); i++)
			{
				if (tmpVect[i].first != tmpVect[i - 1].first)
					cout << "������� " << tmpVect[i].first << ":\n";
				cout << tmpVect[i].second->key << " " << tmpVect[i].second->text << endl;
			}

			break;
		case 11:  exit(0);
		}
	}
}



Tree* list(int key, char* s)     //�������� ������ ��������
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = key;
	for (int i = 0; i < strsize; i++)
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}
void insert(Tree*& t, Tree*& elem) {
	if (t == NULL)              //���� ������ ���, �� ��������� �������
	{
		t = elem;
		return;
	}
	if (t->key == elem->key)
	{
		cout << "���� ������ ���� ��������" << endl;
		delete elem;
		return;
	}
	if (elem->key > t->key)  //������ ����, ���� � ������ ��������
		insert(t->Right, elem);  //�� ������� ���������� ������
	else
		insert(t->Left, elem);   //����� - �����

}

Tree* delet(Tree* Root, int key)  //�������� �������� �� �����
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL) // ����� �������� R ��� ������
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // �� ����� ����� 
		else
			Prev_Del->Right = R;	// �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //����� �������� �� ����� 
{
	Tree* rc = n;
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

void view(Tree* t, int level) //����� ������ 
{
	if (t)
	{
		view(t->Right, level + 1);	//����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1);	//����� ������ ���������
	}
}

void delAll(Tree* t) //������� ������
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

bool countRoot(Tree* t, int key, int count)
{
	if (t != NULL)
	{
		if (key == t->key)
		{
			cout << "���������� ������: " << count << endl;
			return true;
		}
		if (key < t->key)
			return countRoot(t->Left, key, count + 1);
		else
			return countRoot(t->Right, key, count + 1);
	}
	return false;
}

void countRight(Tree* t, int& count) {
	if (t != NULL)
	{
		if (t->Right != NULL && (t->Right->Right == NULL && t->Right->Left == NULL))
		{
			count++;
			
		}	
		countRight(t->Right, count);
		countRight(t->Left, count);
	}
}

void countEven(Tree* t, int& count) {
	if (t != NULL)
	{
		if (t->key % 2 == 0)
			count++;
		countEven(t->Right, count);
		countEven(t->Left, count);

	}
}

void showLevel(Tree* t, vector <pair<int, Tree*>>& tmpv, int count)
{
	if (t != NULL)
	{
		tmpv.push_back(make_pair(count, t));
		showLevel(t->Left, tmpv, count + 1);
		showLevel(t->Right, tmpv, count + 1);
	}
}