#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char* read(ifstream& f) {
    string s;
    ifstream in("FILE1.txt");
    getline(in, s);
    in.close();
    char* str = new char[s.size() - 1];
    int i = 0;
    for (i = 0; i < s.size(); i++) {
        str[i] = s[i];
    }
    str[i] = '\0';
    return str;
    delete[]str;
}

int main() {
    setlocale(0, "rus");
    int i = 0;
    char str[200];
    ofstream file1("FILE1.txt");
    printf("введите строку: \n");
    gets_s(str);
    file1 << str;
    file1.close();
    ifstream file2("FILE1.txt");
    char * str1 = read(file2);
    int len = strlen(str1), num = 0, max = 0, pos = 0, posMax = 0;
    while (pos < len) {
        if (str1[pos] != ' ') {
            num++;
            pos++;
            if (num > max) {
                max = num;
                posMax = pos;
            }
        }
        else {
            num = 0;
            pos++;
        }
    }
    for (int i = 0; i < max; i++) {
        cout << str1[posMax - max + i];
    }
    file2.close();
    return 0;
}