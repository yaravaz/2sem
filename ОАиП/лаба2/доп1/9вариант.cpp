#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(0, "rus");
    FILE* fileA; FILE* fileB; errno_t err, err2;
    err = fopen_s(&fileA, "fileA.txt", "r");
    if (err != NULL) {
        perror("Невозможно oткрыть файл\n");
        return -1;
    }
    err2 = fopen_s(&fileB, "fileB.txt", "w");
    if (err != NULL) {
        perror("Невозможно oткрыть файл\n");
        return -1;
    }
    int N, k, i, j;
    vector<int> B;
    int A[100];
    N = k = 0;
    while (fscanf_s(fileA, "%d,", &N) > 0)
    {
        A[k++] = N;
    }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < B.size(); j++)
        {
            if (A[i] == B[j])
                break;
        }
        if (j == B.size())
            B.push_back(A[i]);
    }
    for (int i = 0; i < B.size(); i++)
    {
        fprintf(fileB, "%d ", B[i]);
    }
    fclose(fileA);
    fclose(fileB);
    return 0;
}