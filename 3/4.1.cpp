#include <iostream>
#include <cmath>

using namespace std;

long double fact(int N)
{
    if (N <= 2)
    {
        return N;
    }

    return N * fact(N - 1);
}

double F(double x, int N)
{
    double res = 0;
    for (int i = N; i > 0; --i)
    {
        res += (pow(x, 3 * i) * log(3 * x + i) / fact(i));
    }
    return res;
}

int main()
{
    int N;
    double x;

    cout << "N = ";
    cin >> N;
    cout << "x = ";
    cin >> x;

    cout << "F(x, N) = F(" << x << "," << N << ") = " << F(x, N) << '\n';

    return 0;
}
