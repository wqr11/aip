#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, eps, U, S;
    int n = 0;

    cout << "x = ";
    cin >> x;
    cout << "eps = ";
    cin >> eps;

    U = 1.0;
    S = U;

    cout << "n = " << n << ", U = " << U << ", S = " << S << endl;

    while (fabs(U) > eps)
    {
        n++;
        U *= x / n;
        S += U;
        cout << "n = " << n << ", U = " << U << ", S = " << S << endl;
    }

    cout << "Итог S = " << S << endl;
    cout << "exp(x) = " << exp(x) << endl;

    return 0;
}