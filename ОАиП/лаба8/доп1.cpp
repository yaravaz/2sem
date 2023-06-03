#include <iostream>
#include <string>

using namespace std;

struct Q {
	float a;
	Q* next;
	Q* head;
	Q* tail;
};

void PushQ(Q* queue);
void ViewQ(Q* queue);
void MoveQ(Q* queue);

int menu() {
	bool flag = true;
	string str;
	while (flag) {
		system("cls");
		cout << "Что вы хотите сделать?:\n1 - Добавление элемента в очередь\n2 - Вывод очереди\n3 - Сдвиг\n0 - Выход\n";
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
	while (flag) {
		switch (menu()) {
		case 1: PushQ(queue); break;
		case 2: ViewQ(queue); break;
		case 3: MoveQ(queue); break;
		case 0: flag = false; break;
		}
	}

	return 0;
}

int counter = 0;

void PushQ(Q* queue) {
	Q* el = new Q;
	el->next = NULL;
	float numb;
	string str;
	bool flag;

	while (true) {
		flag = true;
		cout << "Введите элемент очереди ";
		cin >> str;
		for (int i = 0; i < size(str); i++) {
			if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
				system("cls");
				cout << "Некореектное значение\n";
				flag = false;
				system("pause");
			}
		}
		if (flag) {
			break;
		}
	}
	numb = stof(str);
	
	if (counter == 0) {
		el->a = numb;
		queue->head = el;
		queue->tail = el;
	}
	else {
		el->a = numb;
		queue->tail->next = el;
		queue->tail = el;
	}
	counter++;
}

void ViewQ(Q* queue) {
	Q* el = queue->head;
	if (el == NULL) {
		cout << "Очередь пуста\n";
		system("pause");
		return;
	}
	else {
		while (el != NULL) {
			cout << el->a << ' ';
			el = el->next;
		}
		cout << endl;
	}
	system("pause");
}

void MoveQ(Q* queue) {
	Q* el = queue->head;
	float temp = queue->head->a, max = 0;
	if (el == NULL) {
		cout << "Очередь пуста\n";
	}
	else {
		while (el != NULL) {
			if (max < el->a) {
				max = el->a;
			}
			el = el->next;
		}
		while (queue->head->a != max) {
			el = queue->head;
			float temp = el->a;
			queue->head = queue->head->next;
			delete el;

			Q* el1 = new Q;
			el1->next = NULL;
			el1->a = temp;
			queue->tail->next = el1;
			queue->tail = el1;
		}

	}
}
