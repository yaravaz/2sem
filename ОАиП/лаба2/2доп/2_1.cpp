#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    int n, m; float m1, m2;
    FILE* fA, * fB, * fC;

    errno_t err1, err2;
    err1 = fopen_s(&fA, "fA.txt", "r");
    if (err1 != 0)
    {
        perror("Ошибка открытия fa.txt");
        return -1;
    }

    err2 = fopen_s(&fB, "fB.txt", "r");
    if (err2 != 0)
    {
        perror("Ошибка открытия fb.txt");
        return -1;
    }
    fopen_s(&fC, "fC.txt", "w");

    fscanf_s(fA, "%d", &n);
    fscanf_s(fB, "%d", &m);

    if (n != m) {
        cout << "Ошибка в данных";
        return -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf_s(fA, "%f", &m1);
            fscanf_s(fB, "%f", &m2);
            fprintf(fC, "%f", m1 + m2);
            fputs(" ", fC);
        }
        fprintf(fC, "\n");
    }
    fclose(fA);
    fclose(fB);
    fclose(fC);
    return 0;
}