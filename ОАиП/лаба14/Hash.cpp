#include "Hash.h"
#include <iostream>
int HashFunction(int key, int size, int p)
{
	int key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return (p + key) % size;
}

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
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0);i != size && !b;  j = HashFunction(t, size, ++i)) {
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

