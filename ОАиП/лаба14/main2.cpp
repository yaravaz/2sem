#include <iostream>
#include<string>
using namespace std;

#pragma once
#define HASHDEL (void*) -1
struct Object
{
	void** data;
	Object(int, int(*)(void*));
	int size;
	int N;
	int(*getKey)(void*);
	bool insert(void*);
	int searchInd(int key);
	void* search(int key);
	void* deleteByKey(int key);
	bool deleteByValue(void*);
	void scan(void(*f)(void*));
	void scan();
	void resizeHashTable(int*& hashTable, int& size);
	void resize();
};
struct AAA
{
	int key;
	char* mas;
	//std::string mas;
	AAA(int k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};
static void* DEL = (void*)HASHDEL;
Object create(int size, int(*getkey)(void*));
#undef HASHDEL


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
	string str; bool uncor = true;
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
			uncor = true;
			cout << "������� ����" << endl;
			cin.ignore();
			cin.getline(str, 100);
			for (int i = 0; i < strlen(str); i++)
			{
				if (!isdigit(str[i]))
				{
					cout << "������� ������������ �����" << endl;
					uncor = false;
					break;
				}
			}
			if (!uncor) {
				break;
			}
			k = atoi(str);
			while (H.search(k)) {
				cout << "����� ���� ��� ����!\n ";
				uncor = false;
				break;
			}
			if (!uncor) {
				break;
			}
			a->key = k;
			cout << "������� �����" << endl;
			cin >> str;
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
	}
	return 0;
}

int HashFunction(int key, int size, int p)    //���-�������
{
	return (key + p) % size;
}
//-------------------------------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d)
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0); i != size && !b; j = HashFunction(t, size, ++i)) {
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
		}
	return b;
}
//-------------------------------
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " �������" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  �����" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  ������" << std::endl;
			else
				f((this->data)[i]);
	}
}
void Object::scan()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " �������" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  �����" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  ������" << std::endl;
			else
				std::cout << " ���� " << ((AAA*)(this->data)[i])->key << " - " << ((AAA*)(this->data)[i])->mas << std::endl;

	}
}
void Object::resizeHashTable(int*& hashTable, int& size) {
	// ������� ����� ������� � ������� ��������
	int newSize = size * 2;
	int* newHashTable = new int[newSize];

	// �������������� ����� ������� ������
	for (int i = 0; i < newSize; i++) {
		newHashTable[i] = 0;
	}

	// ������������ ��� �������� �� ������ ������� � �����
	for (int i = 0; i < size; i++) {
		if (hashTable[i] != 0) {
			int index = HashFunction(hashTable[i], newSize, 0);
			while (newHashTable[index] != 0) {
				index = (index + 1) % newSize;
			}
			newHashTable[index] = hashTable[i];
		}
	}

	// ����������� ������, ���������� ������ ��������
	delete[] hashTable;

	// ��������� ��������� �� ����� ������� � �� ������
	hashTable = newHashTable;
	size = newSize;
}

void Object::resize() {
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " �������" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  �����" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  ������" << std::endl;
			else
				std::cout << " ���� " << ((AAA*)(this->data)[i])->key << " - " << ((AAA*)(this->data)[i])->mas << std::endl;

	}
}


