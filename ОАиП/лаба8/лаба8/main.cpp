#include "stdafx.h"

int menu() {
	bool flag = true;
	string str;
	while (flag) {
		system("cls");
		cout << "Что вы хотите сделать?:\n1 - Добавление элемента в очередь\n2 - Вывод очереди\n3 - Размер очереди\n0 - Выход\n";
		cin >> str;
		if (str[0] < '0' || str[0] > '3' || size(str) > 1) {
			system("cls");
			cout << "Некорректное значение" << endl;
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
	cout << "Введите максимальный размер очереди ";
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