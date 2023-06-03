#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Q {
	float a;
	Q* next;
	Q* head;
	Q* tail;
};

ofstream fout;
ifstream fin;

int counter = 0;

void PushQ(Q* queue, int numb);
void ViewQ(Q* queue);

int main() {
	setlocale(LC_CTYPE, "rus");
	bool flag;
	string str, str1;
	fin.open("f.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, str);
			Q* queue = new Q;
			queue->head = queue->tail = NULL;
			for (int i = 0; i < size(str); i++) {
				flag = false;
				while (isdigit(str[i])) {
					str1.push_back(str[i]);
					str.erase(i, 1);
					flag = true;
				}
				if (flag) {
					PushQ(queue, stoi(str1));
					str1.clear();
				}
			}
			fout.open("g.txt", ios::app);
			fout << str << " ";
			ViewQ(queue);
			counter = 0;
		}
	}
	else {
		cout << "error" << endl;
	}
	fin.close();
	system("pause");
	return 0;
}

void PushQ(Q* queue, int numb) {
	Q* el = new Q;
	el->next = NULL;

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
	while (el != NULL) {
		fout << el->a << ' ';
		el = el->next;
	}
	fout << endl;
	fout.close();
}

void PopQ(Q* queue) {
	while (queue->head != NULL) {
		Q* el = queue->head;
		char a = el->a;
		queue->head = queue->head->next;
		delete el;
	}
	cout << endl;
}