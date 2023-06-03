#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	setlocale(0, "rus");
	int a; char str[50], str2[50];

	errno_t err, err2;
	FILE* f; FILE* g;
	err = fopen_s(&f, "f.txt", "r");
	if (err != NULL) {
		perror("Невозможно oткрыть файл\n");
		return -1;
	}
	err2 = fopen_s(&g, "g.txt", "w");
	if (err2 != NULL)
	{
		printf("Ошибка в открытии файла");
		return -1;
	}
	fgets(str, sizeof(str), f);
	if (feof(f) != 0) {
		printf("\nЧтение файла закончено\n");
		printf("Считана последовательность:\n");
	}
	else
	{
		printf("\nОшибка чтения из файла\n");
		return -1;
	}
	puts(str);
	printf("Введите число\n");
	scanf_s("%d", &a);
	int numbrs[20]; int k = 0, i = 0;
	str[strlen(str) + 1] = '\0';
	while (i < strlen(str)) {
		if (str[i] != ' ') {
			numbrs[k] = (str[i] - '0') * 10;
			i++;
			numbrs[k] += str[i] - '0';
			k++;
			i++;
		}
		else
			i++;
	}
	i = k; k = 0; int j = 0;
	while (i > 0) {
		if (numbrs[k] > a) {
			str2[j] = numbrs[k] / 10 + '0';
			j++;
			str2[j] = numbrs[k] % 10 + '0';
			i--;
			k++;
			j++;
			str2[j] = ' ';
			j++;
		}
		else {
			i--;
			k++;
		}
	}
	str2[j] = '\0';
	fputs(str2, g);
	fclose(f);
	fclose(g);
	return 0;


}