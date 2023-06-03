#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void quicksort(int* arrD, int first, int last);

int main() {
	setlocale(LC_CTYPE, "Rus");

	long int N; int temp;

	cout << "Введите N: ";
	cin >> N;
	int* arr = new int[N];
	int* arrA = new int[N];
	int* arrB = new int[N];
	int* arrC = new int[N];
	int* arrD = new int[N];
	unsigned int start_time;
	unsigned int end_time;

	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 101;
		cout << arr[i] << " ";
		arrA[i] = arr[i];
		arrB[i] = arr[i];
		arrC[i] = arr[i];
		arrD[i] = arr[i];
	}

	cout << "\nПузырьковая сортировка: \n\n";
	start_time = clock();
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < N - i; j++) {
			if (arrA[j] > arrA[j + 1]) {
				temp = arrA[j];
				arrA[j] = arrA[j + 1];
				arrA[j + 1] = temp;
			}
		}
	}
	end_time = clock();
	cout << "Время выполнения пузырьковой сортировки " << end_time - start_time << "ms\n";
	for (int i = 0; i < N; i++) {
		cout << arrA[i] << " ";
	}
	
	cout << "\n\nСортировка вставкой: \n\n";
	start_time = clock();
	for (int i = 1; i < N; i++) {
		for (int j = i; j > 0 && arrB[j - 1] > arrB[j]; j--) {
			temp = arrB[j - 1];
			arrB[j - 1] = arrB[j];
			arrB[j] = temp;
		}
	}
	end_time = clock();
	cout << "Время выполнения сортировки вставки " << end_time - start_time << "ms\n";
	for (int i = 0; i < N; i++) {
		cout << arrB[i] << " ";
	}

	cout << "\n\nСортировка выбора: \n\n";
	start_time = clock();
	int min;
	for (int i = 0; i < N; i++) {
		min = i;
		for (int j = i + 1; j < N; j++)
			min = (arrC[j] < arrC[min]) ? j : min;
		if (i != min) {
			temp = arrC[i];
			arrC[i] = arrC[min];
			arrC[min] = temp;
		}
	}
	end_time = clock();
	cout << "Время выполнения сортировки выбора " << end_time - start_time << "ms\n";
	for (int i = 0; i < N; i++) {
		cout << arrC[i] << " ";
	}

	cout << "\n\nБыстрая сортировка: \n\n";
	start_time = clock();
	
	quicksort(arrD, 0, N - 1);

	end_time = clock();
	cout << "Время выполнения быстрой сортировки " << end_time - start_time << "ms\n";
	for (int i = 0; i < N; i++) {
		cout << arrD[i] << " ";
	}

	cout << endl;

	delete[] arrD;
	delete[] arrC;
	delete[] arrB;
	delete[] arrA;
	delete[] arr;
	return 0;
}

void quicksort(int* mas, int first, int last) {
	int half, temp;
	int f = first, l = last;
	half = mas[(f + l) / 2]; 				
	do
	{
		while (mas[f] < half) f++;
		while (mas[l] > half) l--;
		if (f <= l) 				
		{
			temp = mas[f];
			mas[f] = mas[l];
			mas[l] = temp;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}
