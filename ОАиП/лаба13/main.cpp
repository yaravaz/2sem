#include "heap.h"
#include <iostream>
#include <conio.h>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(60, cmpAAA);
	heap::Heap h2 = heap::create(60, cmpAAA);
	heap::Heap h3 = heap::create(60, cmpAAA);

	for (;;)
	{
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "4 - удалить минимальный" << endl
			<< "5 - удаление i-ого элемента" << endl
			<< "6 - добавление элемента во 2 кучу" << endl
			<< "7 - вывод 2 кучи" << endl
			<< "8 - объединение 2 куч в одну" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:
			h1.scan(0);
			break;
		case 2: {
			AAA* a = new AAA;
			cout << "введите ключ" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:
			h1.extractMax();
			break;
		case 4:
			h1.extractMin();
			break;
		case 5:
			int ind;
			cout << "индекс: ";
			cin >> ind;
			h1.extractI(ind);
			break;
		case 6: {
			AAA* a = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			a->x = k;
			h2.insert(a);
		}
			  break;
		case 7:
			h2.scan(0);
			break;
		case 8:
			for (int i = 0; i < h2.size; i++) {
				h1.insert(h2.storage[i]);
			}
			break;
		default:  cout << endl << "¬ведена неверна€ команда!" << endl;
		}
	} return 0;
}