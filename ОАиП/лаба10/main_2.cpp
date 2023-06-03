#include <iostream>
using namespace std;

int a(int m, int n)
{
    int res;

    cout << "A(" << m << ", " << n << ")" << endl;

    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0) {
        return a(m - 1, 1);
    }
    else if (m > 0 && n > 0){
        return a(m - 1, a(m, n - 1));
    }

}




int main() {
    setlocale(LC_CTYPE, "Rus");
    int n, m;
    cout << "¬ведите m и n: ";
    cin >> m;
    cin >> n;
    int result = a(m, n);
    cout << "–езультат: " << result << endl;
    return 0;
}