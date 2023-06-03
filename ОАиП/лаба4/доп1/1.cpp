#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

typedef struct Exams 
{
	string surname;
	string name;
	string secondname;
	string count;
	float mark[10];
};

void input(int size);
void output();
void find(string lastName);
void processing();

int i, n;
string file = "database.txt";
Exams students[20];
bool flag1;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string str, surname; bool flag = true, flag1 = false; 

	while (flag){
		system("cls");
		cout << "Что вы хотите сделать? \n";
		cout << "1 - Ввод данных с клавиатуры\n";
		cout << "2 - Вывод данных\n";
		cout << "3 - Поиск по фамилии\n";
		cout << "4 - Процент учащихся со средним баллом более 3\n";
		cout << "0 - Выход из программы\n\n";
		cin >> str;

		if (str[0] < '0' || str[0] > '4' || size(str) > 1) {
			system("cls");
			cout << "Некорректное значение" << endl;
			system("pause");
			continue;
		}

		n = stoi(str);
		
		switch (n)
		{
		case 1: 
			bool check;
			while (true) {
				check = true;
				cout << "Введите количество студентов, данные о которых хотите ввести: ";
				cin >> str;
				
				for (int j = 0; j < size(str); j++) {
					if (str[j] < '0' || str[j] > '9') {
						check = false;
					}
				}
				if (!check) {
					system("cls");
					cout << "Некорректное значение" << endl;
					system("pause");
					continue;
				}
				break;
			}
			n = stoi(str);
			input(n);
			break;
		case 2: 
			output(); 
			break;
		case 3:   
			while (true) {
				flag1 = false;
				cout << "Введите фамилию: ";
				cin >> str;
				for (int j = 0; j < size(str); j++) {
					if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'А' && str[j] <= 'Я') || (str[j] >= 'а' && str[j] <= 'я'))) {
						system("cls");
						cout << "Некорректное значение" << endl;
						system("pause");
						flag1 = true;
						break;
					}

				}
				if (flag1) {
					continue;
				}
				break;
			}
			surname = str;
			find(surname); 
			break;
		case 4:  
			processing();
			break;
		case 0: 
			ofstream out;
			out.open(file);
			out.close();
			exit(0);  
		}
	}
}

void input(int number)
{
	system("cls");
	cin.ignore();
	ofstream out;
	out.open(file, ios::app);
	string str;
	for (int p = 0; p < number; p++)
	{
		while (true) {
			flag1 = false;
			cout << "Фамилия: ";
			cin >> str;
			for (int j = 0; j < size(str); j++) {
				if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'А' && str[j] <= 'Я') || (str[j] >= 'а' && str[j] <= 'я'))) {
					system("cls");
					cout << "Некорректное значение" << endl;
					system("pause");
					flag1 = true;
					break;
				}

			}
			if (flag1) {
				continue;
			}
			break;
		}
		students[i].surname = str;

		while (true) {
			flag1 = false;
			cout << "Имя: ";
			cin >> str;
			for (int j = 0; j < size(str); j++) {
				if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'А' && str[j] <= 'Я') || (str[j] >= 'а' && str[j] <= 'я'))) {
					system("cls");
					cout << "Некорректное значение" << endl;
					system("pause");
					flag1 = true;
					break;
				}

			}
			if (flag1) {
				continue;
			}
			break;
		}
		students[i].name = str;
		
		while (true) {
			flag1 = false;
			cout << "Отчество: ";
			cin >> str;
			for (int j = 0; j < size(str); j++) {
				if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'А' && str[j] <= 'Я') || (str[j] >= 'а' && str[j] <= 'я'))) {
					system("cls");
					cout << "Некорректное значение" << endl;
					system("pause");
					flag1 = true;
					break;
				}

			}
			if (flag1) {
				continue;
			}
			break;
		}
		students[i].secondname = str;

		while (true) {
			cout << "Количество экзаменов: ";
			cin >> str;

			if ((str[0] < '1' || str[0] > '5') || size(str) > 1) {
				system("cls");
				cout << "Некорректное значение" << endl;
				system("pause");
				continue;
			}
			break;
		}

		students[i].count = str;
		cout << "Оценки: "; 
		bool check;
		for (int j = 0; j < stoi(students[i].count); j++) {
			while (true) {
				check = true;
				cin >> str;

				for (int k = 0; k < size(str); k++) {
					if (str[k] < '0' || str[k] > '9') {
						check = false;
					}
				}
				if (!check || stoi(str) > 10) {
					system("cls");
					cout << "Некорректное значение" << endl;
					system("pause");
					continue;
				}
				break;
			}
			students[i].mark[j] = stoi(str);
		}
		cin.ignore();
		out << students[i].surname << " " << students[i].name << " " << students[i].secondname << " " << students[i].count << " ";
		for (int j = 0; j < stoi(students[i].count); j++) {
			out << students[i].mark[j] << " ";
		}
		out << endl;
		cout << endl;
		i++;
	}
	out.close();
}

void output()
{
	system("cls");
	ifstream in;
	in.open(file);
	string str;

	while (!in.eof())
	{
		getline(in, str);
		cout << str << endl;
	}
	system("pause");
	in.close();
}

void find(string lastName)
{
	system("cls");
	bool flag = false; 
	for (int j = 0; j < i; j++) {
		if (students[j].surname == lastName) {
			cout << students[j].surname << " " << students[j].name << " " << students[j].secondname << " " << students[j].count << " ";
			for (int k = 0; k < stoi(students[j].count); k++) {
				cout << students[j].mark[k] << " ";
			}
			flag = true; 
			cout << endl;
		}
	}
	if (!flag) 
		cout << "Ничего не найдено\n";
	system("pause");
}

void processing() {
	system("cls");
	int marks = 0, positive = 0, average = 0;
	float res;
	for (int j = 0; j < i; j++) {
		marks++;
		int lenght = stoi(students[j].count);
		for (int k = 0; k < lenght; k++) {
			average += students[j].mark[k];
		}
		if (average / lenght > 3) {
			positive++;
		}
		average = 0;
	}
	res = (float)positive / (float)marks * 100;
	cout << "\nПроцент студентов, сдавших экзамены выше 3 " << res << "%\n\n";
	system("pause");
}
