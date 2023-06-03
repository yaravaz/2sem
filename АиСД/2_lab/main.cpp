#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	float minedge = 0, maxedge, half, num;
	int n;
	bool flag = false;
	cout << "Введите верхнюю границу интервала, в котором будет располагать число: ";
	cin >> maxedge;
	num = maxedge;
	system("cls");

	cout << "Задумайте число\n";
	system("pause");

	system("cls");

	while ((minedge < maxedge - 1) && (flag != true)) {
		system("cls");
		half = ceil((minedge + maxedge) / 2);
		cout << "Вы загадали " << (int)half << "?\n";
		cout << "1 - меньше\n";
		cout << "2 - больше\n";
		cout << "3 - угадал(а)\n";
		cin >> n;
		
		switch (n) {
		case 1: 
			maxedge = half;
			break;
		case 2: 
			if (half == num - 1) {
				cout << "Вы загадали " << ++half << endl;
				exit(0);
			}
			else
				minedge = half;
			break;
		case 3: 
			flag = true;
			break;
		default:
			cout << "Некорректный ввод\n";
			return -1;
		}
	}

	cout << "Вы загадали " << half << endl;
	int i = -1;
	do {
		i++;
	} while (pow(2, i) <= num);

	cout << "\nМаксимальное количество шагов = " << i << endl;
	cout << num << endl;

	while (num > 1) {
		num = ceil(num / 2);
		cout << num << endl;
	}

	return 0;
}