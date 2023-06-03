#include <iostream>
using namespace std;

int numsq(int a, int b) {
    if (b == 0) {
        return 0;
    }
    int squares = a / b;
    squares += numsq(b, a % b);
    return squares;
}

int main() {
    setlocale(LC_CTYPE, "Rus");
    int a, b;
    cout << "������� ����� ������ a � b: ";
    cin >> a;
    cin >> b;
    int result = numsq(a, b);
    cout << "���������� ���������: " << result << endl;
    return 0;
}