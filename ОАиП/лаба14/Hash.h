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
