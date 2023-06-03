#include <iostream>
#include <algorithm>

using namespace std;

void search(int a[], int k, int n)
{
    if (k == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = k; i < n; i++) {
        swap(a[k], a[i]);
        search(a, k + 1, n);
        swap(a[k], a[i]);
    }
}

int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(a) / sizeof(int);

    search(a, 0, n);

    return 0;
}