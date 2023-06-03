// ���������� ����������
#include <iostream> // ��� �����-������
#include <cmath> // ��� �������������� �������

using namespace std;

// �������, ������� ����� �������������
double f(double x) {
    return cos(x)/x;
}

// ����� ��������
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n; // ��� ���������
    double sum = (f(a) + f(b)) / 2; // ��������� �����
    for (int i = 1; i < n; i++) {
        double x = a + i * h; // ������� �����
        sum += f(x); // ��������� �������� ������� � �����
    }
    return sum * h; // �������� �� ��� � ���������� ���������
}

// ����� ������� ���������������
double midpoint(double a, double b, int n) {
    double h = (b - a) / n; // ��� �����
    double sum = 0; // ��������� �����
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * h; // �������� �������� ��������������
        sum += f(x); // ��������� �������� ������� � �����
    }
    return sum * h; // �������� �� ��� � ���������� ���������
}

// ����� ��������
double simpson(double a, double b, int n) {
    double h = (b - a) / n; // ��� �����
    double sum = f(a) + f(b); // ��������� �����
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h; // ������� ����� (��������)
        sum += 4 * f(x); // ��������� �������� ������� � ����� 4
    }
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h; // ������� ����� (������)
        sum += 2 * f(x); // ��������� �������� ������� � ����� 2
    }
    return sum * h / 3; // �������� �� ��� � ����������� � ���������� ���������
}

int main() {
    setlocale(LC_ALL, "rus");
    double a = 1.0, b = 4.0; // ������� ��������������
    double exact = -0.4783856;
    for (int n = 10; n <= 100; n *= 10) { // ���������� ������ ���������� �����
        cout << "n = " << n << endl; // ������� ������� ���������� �����
        double T = trapezoidal(a, b, n); // �������� ������� ��������
        double M = midpoint(a, b, n); // ������� ���������������
        double S = simpson(a, b, n); // ������� �������
        cout << "���������: " << T << ", ���������� �����������: " << abs(T - exact)
            << ", ������������� �����������: " << abs(T - exact) / exact << endl;
        cout << "���������������: " << M << ", ���������� �����������: " << abs(M - exact)
            << ", ������������� �����������: " << abs(M - exact) / exact << endl;
        cout << "�������: " << S << ", ���������� �����������: " << abs(S - exact)
            << ", ������������� �����������: " << abs(S - exact) / exact << endl;
    }
    return 0;
}