#include <iostream>
#include <stdio.h> 
#include <sstream> 
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {
	setlocale(0, "rus");

	errno_t err, err2;
	FILE* fileA; FILE* fileB;
	err = fopen_s(&fileA, "fileA.txt", "r");
	if (err != NULL) {
		perror("Невозможно oткрыть файл\n");
		return -1;
	}
	err2 = fopen_s(&fileB, "fileB.txt", "w");
	if (err2 != NULL)
	{
		printf("Ошибка в открытии файла");
		return -1;
	}
	int* numbr = new int[20]; int i = 0, k = 0, counter = 0, j = 0;
	while (fscanf_s(fileA, "%d", &numbr[i]) != EOF) {
		i++;
	}
	if (feof(fileA) != 0) {
		printf("\nЧтение файла закончено\n");
	}
	else
	{
		printf("\nОшибка чтения из файла\n");
		return -1;
	}
	int* result = new int[i];
	while (j < (i - 1)) {
		if (numbr[j] * numbr[j+1] < 0) {
			result[k] = numbr[j];
			k++;
			j++;
		}
		else {
			while (numbr[j] * numbr[j + 1] > 0 && j < i - 1) {
				counter++;
				j++;
			}
			result[k] = numbr[j - counter];
			j++;
			k++;
			counter = 0;
		}
	}
	for (int j = 0; j < k; j++) {
		fprintf(fileB, "%d", result[j]);
		fputs(" ", fileB);
	}
	fclose(fileA);
	fclose(fileB);
	delete[] result;
	delete[] numbr;
	_CRT_SECURE_NO_WARNINGS;
	return 0;
}