#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <chrono>

using namespace std;


void ShakerSort(int* a, int n) {
    int left, right, i;
    left = 1;
    right = n - 1;
    while (left <= right) {
        for (i = right; i >= left; i--) {
            if (a[i - 1] < a[i]) {
                swap(a[i - 1], a[i]);
            }
        }
        left++;
        for (i = left; i <= right; i++) {
            if (a[i - 1] < a[i]) {
                swap(a[i - 1], a[i]);
            }
        }
        right--;
    }
}
void Shell(int* A, int n) {
    int d = n;
    int count;
    d = d / 2;
    int j = 0;
    while (d > 0) {
        for (int i = 0; i < n - d; i++) {
            j = i;
            while (j >= 0 && A[j] < A[j + d]) {
                count = A[j];
                A[j] = A[j + d];
                A[j + d] = count;
                j--;
            }
        }
        d = d / 2;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int a[1000];
    int b[1000];
    int c1[1000];
    int c2[1000];
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        cout << a[i] << " ";
    }
    cout << "\n\n";
    int Min = 999999;
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 1000;
        Min = min(Min, b[i]);
        cout << b[i] << " ";
    }
    cout << "\n\n";
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > Min)
        {
            c1[k] = c2[k] = a[i];
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << c1[i] << " ";
    }
    cout << "\n\n\nшейкерная \n";
    auto begin = std::chrono::steady_clock::now();
    ShakerSort(c1, k);
    auto end = std::chrono::steady_clock::now();
    for (int i = 0; i < k; i++)
    {
        cout << c1[i] << " ";
    }
    double hg = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
    cout << "\nВремя выполнения сортировки " << hg/1000 << " nanoseconds " <<  endl << endl;
    cout << "\n\n\nШелла\n";
    begin = std::chrono::steady_clock::now();
    Shell(c2, k);
    end = std::chrono::steady_clock::now();
    for (int i = 0; i < k; i++)
    {
        cout << c2[i] << " ";
    }
    hg = (double)chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
    cout << "\nВремя выполнения сортировки " << hg/1000 << " nanoseconds" << endl << endl;
}


