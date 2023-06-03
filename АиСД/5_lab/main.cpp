#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct stack {
	char data;
	stack* next;
	stack* head;
};

void push(char x, stack* myStk)
{
	stack* e = new stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
}
void show(stack* myStk)
{
	stack* e = myStk->head;
	string a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

int pop(stack* mystk)
{
	if (mystk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;
	}
	else
	{
		stack* e = mystk->head;
		int a = mystk->head->data;
		mystk->head = mystk->head->next;
		delete e;
		return a;
	}
}

int main() {
	setlocale(LC_CTYPE, "rus");
	stack* mystk = new stack;
	mystk->head = NULL;

	string str;
	char skobky[3][2] = {{'[', ']'}, {'{', '}'}, {'(', ')'}};
	string skobka = {'[', ']', '{', '}' , '(', ')'};
	int index_pare = 0;
	int n = 0;
	cout << "Введите строку:";
	cin.ignore();
	getline(cin, str);

	for (int i = 0; i < size(str); i++) {
			for (int j = 0; j < 6; j++) {
			if (str[i] != skobka[j]) {
				n++;
			}
		}
		if (n == 6) {
			str.erase(i, 1);
			i--;
		}
		n = 0;
	}
	cout << str;
	bool flag, control = true, flag1 = true;
	for (int i = 0; i < size(str); i++) {
		flag = false;
		for (int j = 0; j < 3; j++) {
			if (str[i] == skobky[j][0]) {
				push(str[i], mystk);
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}
		for (int j = 0; j < 3; j++) {
			if (str[i] == skobky[j][1] && mystk->head == NULL) {
				flag = true;
				push(str[i], mystk);
				break;
			}
		}
		if (flag) {
			continue;
		}
		for (int j = 0; j < 3; j++) {
			if (mystk->head->data == skobky[j][0]) {
				index_pare = j;
				break;
			}
		}

		if (str[i] == skobky[index_pare][1]) {
			pop(mystk);
		}
		else {
			control = false;
			break;
		}
	}

	if (!control || mystk->head != NULL) {
		cout << "\nскобки расставлены не верно\n";
	}
	else
		cout << "\nскобки расставлены верно\n";
	
	return 0;
}