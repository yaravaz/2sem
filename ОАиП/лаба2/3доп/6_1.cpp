#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");

    FILE* file;
    fopen_s(&file, "fA.txt", "r");

    float numrs[100];
    int count = 0;

    for (int i = 0; !feof(file); i++)
    {
        fscanf_s(file, "%f", &numrs[i]);
        count++;
    }

    for (int i = 0; i < count - 1; i++)
    {
        printf("%f ", numrs[i]);
    }

    int num;
    cout << "\n¬ведите число: ";
    cin >> num;

    float minOfDif = numrs[0] - num;
    int pos = 0;
    for (int i = 0; i < count; i++)
    {
        if (abs(numrs[i] - num) < minOfDif)
        {
            minOfDif = numrs[i] - num;
            pos = i;
        }
    }

    printf("%d", pos+1);

    fclose(file);
    return 0;
}