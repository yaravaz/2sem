#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	setlocale(0, "rus");

	FILE* f; FILE* g;
    int num, i; int numbr[10];
    fopen_s(&f, "f.txt", "r");
    fopen_s(&g, "g.txt", "w");
    while (!feof(f))
    {
        for (i = 1; i <= 5; i++)
        {
            fscanf_s(f, "%d", &num);
            fprintf(g, "%d ", num);
        }
        for (i = 1; i <= 5; i++)
        {
            fscanf_s(f, "%d", &num);
            numbr[i-1] = num;

        }
        for (i = 1; i <= 5; i++)
        {
            fscanf_s(f, "%d", &num);
            fprintf(g, "%d ", num);
        }
        for (i = 1; i <= 5; i++)
        {
            fscanf_s(f, "%d", &num);
            numbr[4 + i] = num;
        }
        for (int i = 0; i < 10; i++) {
            fprintf(g, "%d ", numbr[i]);
        }
    }
    fclose(f);
    fclose(g);
	return 0;
}