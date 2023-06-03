#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void generate(int a, string prefix, ofstream& output_file) {
    if (a == 0) {
        output_file << prefix << endl;
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (i <= a) {
            generate(a - 1, prefix + to_string(i), output_file);
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int a;
    cout << "Введите число A: ";
    cin >> a;

    ofstream output_file("numbers.txt");
    generate(a, "", output_file);
    output_file.close();

    cout << "Все числа записаны в файл 'numbers.txt'" << endl;
    return 0;
}