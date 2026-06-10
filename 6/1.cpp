#include <iostream>
#include <cmath>

using namespace std;

long double fact(int N)
{
    long double r = 0.0;

    if (N <= 2)
    {
        return N;
    }

    return N * fact(N - 1);
}

long double series(double x, int N)
{
    long double res = 0.0;

    for (int i = N; i > 0; --i)
    {
        res += pow(x, 3 * i) * log(3 * x + i) / fact(i);
    }

    return res;
}

int find_n_derivative_peak(int *ns, long double *values, int size)
{
    for (int i = 1; i < size; i++)
    {
        const int N = ns[i];
        const long double V = values[i];
        const long double Vprev = values[i - 1];

        if (V <= Vprev * 1.1)
        {
            return N;
        }
    }

    return -1;
}

int find_n_with_max_sum(int *ns, long double *values, int size)
{
    long double maxsum = values[0];
    int maxN = ns[0];

    for (int i = size; i > 0; --i)
    {
        if (values[i] > maxsum)
        {
            maxsum = values[i];
            maxN = ns[i];
        }
    }

    return maxN;
}

int main()
{
    double x;
    cout << "x = ";
    cin >> x;

    int Ns[] = {5, 10, 15, 20, 25};
    constexpr int n_count = sizeof(Ns) / sizeof(int);

    long double *arr = new long double[26];
    arr[0] = 1.0;
    arr[1] = 1.0;
    arr[2] = 2.0;

    cout
        << "N series(x,N)" << '\n';

    long double *sarr = new long double[n_count];

    for (int i = 0, len = n_count; i < len; i++)
    {
        int N = Ns[i];

        long double s = series(x, N);

        sarr[i] = s;

        cout << N << " " << s << '\n';
    }

    const int foundN = find_n_derivative_peak(Ns, sarr, n_count);

    if (foundN > 0)
    {
        cout << "N DERIVATIVE PEAK = " << foundN << '\n';
    }
    else
    {
        const int maxSumN = find_n_with_max_sum(Ns, sarr, n_count);

        cout << "MAX SUM N = " << maxSumN << '\n';
    }
}