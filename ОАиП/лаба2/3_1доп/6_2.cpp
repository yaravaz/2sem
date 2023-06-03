#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    char text1[1000], text2[1000];
    string strings[6];

    FILE* f1;
    fopen_s(&f1, "f1.txt", "w");
    cout << "¬ведите текст: " << endl;

    for (int i = 0; i < 6; i++)
    {
        gets_s(text1);
        fputs(text1, f1);
        fputs("\n", f1);
        strings[i] = text1;
    }
    fclose(f1);

    FILE* f2;
    fopen_s(&f2, "f2.txt", "w");
    for (int i = 1; i < 6; i += 2)
    {
        const char* c = strings[i].c_str();
        fputs(c, f2);
        fputs("\n", f2);
    }

    fclose(f2);

}