#include "stdafx.h"

string str;
bool flag;

int menu() {
	flag = true;
	while (flag) {
		system("cls");
		cout << "Что вы хотите сделать?:\n1 - Добавление элемента в стек\n2 - Извлечение элемента из стека\n3 - Вывод стека\n4 - Очистка стека\n5 - Проверка\n6 - Записать в файл\n7 - Прочитать из файла\n0 - Выход\n";
		cin >> str;
		if (str[0] < '0' || str[0] > '7' || size(str) > 1) {
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
	Stack* mystk = new Stack;
	mystk->head = NULL;

	while (true) {
		int n = menu();
		switch (n) {
		case 1:
			while (true) {
				flag = true;
				cout << "Введите элемент: " << endl;
				cin >> str;

				for (int i(0); i < size(str); i++) {
					if (!isdigit(str[i])) {
						if (str[i] = '-') {
							continue;
						}
						system("cls");
						cout << "Некорректное значение\n";
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
				cout << "Извлеченный элемент: " << n << endl;
			system("pause");
			break;
		case 3: cout << "Весь стек: " << endl;
			show(mystk);
			system("pause");
			break;
		case 4:
			clear(mystk);
			cout << "Стек очищен\n";
			system("pause");
			break;
		case 5:
			if (prov(mystk)) {
				cout << "Такие элементы есть\n";
			}
			else cout << "Таких элементов нет\n";
			system("pause");
			break;
		case 6: infile(mystk); break;
		case 7: fromfile(); break;
		case 0: exit(0);
		}
	}
}
