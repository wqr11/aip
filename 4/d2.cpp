#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x;
    int M;
    cout << "(x, M) = ";
    cin >> x >> M;

    long double num = 1.0, den = 1.0;

    // 1 << k - степени двойки
    for (int k = 1; (1 << k) < M; ++k)
        num *= (x - (1 << k));
    for (int k = 1; ((1 << k) - 1) < M; ++k)
        den *= (x - ((1 << k) - 1));

    cout << "Результат: " << num / den << endl;

    return 0;
}