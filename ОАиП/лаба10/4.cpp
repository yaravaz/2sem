#include <iostream>
#include <string>

using namespace std;
char simb;
int n, counter = -1;

char step(string str, int i) {
    counter++;
    while (i < 26 + n) {
        if (i - counter * size(str) < size(str)) {
            simb = str[i - counter * size(str)];
        }
        else {
            step(str, i);
        }
        i++;
    }
    cout << simb;
    exit(0);
}

int main(){
    setlocale(LC_ALL, "rus");
    string str;
    cout << "¬ведите последовательность: ";
    getline(cin, str);
    cout << "n: ";
    int i=0;
    cin >> n;

    step(str, i);

    return 0;
}