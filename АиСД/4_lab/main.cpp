#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int* bubble_sort(int* arr, int n) {

    int temp = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;
}

string str;

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    bool flag = true;
    while (flag) {
        system("cls");
        int n, sum = 0, i, j, k;

        while (true) {
            flag = true;
            system("cls");
            cout << "Введите количество элементов в массиве\n";
            cin >> str;
            for (i = 0; i < size(str); i++)
                if (!isdigit(str[i])) {
                    system("cls");
                    cout << "Неккоректное значение\n";
                    system("pause");
                    flag = false;
                }
            if (flag) {
                break;
            }
        }
        n = stoi(str);
        if (n > 10000) break;
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100 + 1;
        }
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n\n";
        bubble_sort(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        } 
        cout << "\n\n";
        int* arrB = new int[n];
        i = 0, j = n - 1, k = 0;
        while(i <= j) {
            if (i < j) {
                arrB[k] = arr[j];
                cout << arrB[k] << " ";
                sum += arrB[k];
                k++;
                arrB[k] = arr[i];
                cout << arrB[k] << " ";
                k++, i++, j--;
            }
            else {
                arrB[k] = arr[i];
                cout << arr[i] << " ";
                sum += arrB[k];
                i++;
            }
        }

        cout << "- это один из возможных вариантов вывода\n\n" <<sum << " - максимальная сумма на счёте чека\n";
        system("pause");
        system("cls");

        while (true) {
            flag = true;
            system("cls");
            cout << "Введите количество элементов в массиве\n";
            cin >> str;
            for (i = 0; i < size(str); i++)
                if (!isdigit(str[i])) {
                    system("cls");
                    cout << "Неккоректное значение\n";
                    system("pause");
                    flag = false;
                }
            if (flag) {
                break;
            }
        }
        n = stoi(str);
        if (n > 10000) break;

        int* arrA = new int[n];
        int counter = 0, number = 0;

        for (int i = 0; i < n; i++) {
            cin >> arrA[i];
        }
        for (i = 0; i < n; i++) {
            cout << arrA[i] << " ";
        }
        cout << "\n\n";
        bubble_sort(arrA, n);
        for (i = 0; i < n; i++) {
            cout << arrA[i] << " ";
        }
        cout << "\n\n";
        
        i = n - 1;

        while (number != 3 && counter < n) {
            counter++;
            if (arrA[i] != arrA[i - 1]) {
                number++;
            }
            i--;
        }

        cout << counter;
        cout << "\n\nХотите продолжить?(1 - да, 2 - нет)\n";
        cin >> n;
        switch (n) {
        case 1: break;
        case 2: flag = false; break;
        default: cout << "Некорректное значение" << endl; break;
        }
        delete[] arr;
        delete[] arrA;
        delete[] arrB;
    }
    return 0;
}