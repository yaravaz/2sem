// Подключаем библиотеки
#include <iostream> // для ввода-вывода
#include <cmath> // для математических функций

using namespace std;

// Функция, которую нужно интегрировать
double f(double x) {
    return cos(x)/x;
}

// Метод трапеций
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n; // шаг разбиения
    double sum = (f(a) + f(b)) / 2; // начальная сумма
    for (int i = 1; i < n; i++) {
        double x = a + i * h; // текущая точка
        sum += f(x); // добавляем значение функции в сумму
    }
    return sum * h; // умножаем на шаг и возвращаем результат
}

// Метод средних прямоугольников
double midpoint(double a, double b, int n) {
    double h = (b - a) / n; // шаг сетки
    double sum = 0; // начальная сумма
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * h; // середина текущего прямоугольника
        sum += f(x); // добавляем значение функции в сумму
    }
    return sum * h; // умножаем на шаг и возвращаем результат
}

// Метод Симпсона
double simpson(double a, double b, int n) {
    double h = (b - a) / n; // шаг сетки
    double sum = f(a) + f(b); // начальная сумма
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h; // текущая точка (нечетная)
        sum += 4 * f(x); // добавляем значение функции с весом 4
    }
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h; // текущая точка (четная)
        sum += 2 * f(x); // добавляем значение функции с весом 2
    }
    return sum * h / 3; // умножаем на шаг и коэффициент и возвращаем результат
}

int main() {
    setlocale(LC_ALL, "rus");
    double a = 1.0, b = 4.0; // границы интегрирования
    double exact = -0.4783856;
    for (int n = 10; n <= 100; n *= 10) { // перебираем разное количество точек
        cout << "n = " << n << endl; // выводим текущее количество точек
        double T = trapezoidal(a, b, n); // интеграл методом трапеций
        double M = midpoint(a, b, n); // методом прямоугольников
        double S = simpson(a, b, n); // методом симсона
        cout << "Трапецией: " << T << ", абсолютная погрешность: " << abs(T - exact)
            << ", относительная погрешность: " << abs(T - exact) / exact << endl;
        cout << "Прямоугольников: " << M << ", абсолютная погрешность: " << abs(M - exact)
            << ", относительная погрешность: " << abs(M - exact) / exact << endl;
        cout << "Симсона: " << S << ", абсолютная погрешность: " << abs(S - exact)
            << ", относительная погрешность: " << abs(S - exact) / exact << endl;
    }
    return 0;
}