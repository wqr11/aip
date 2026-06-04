#include <iostream>
#include <cmath>

using namespace std;

/**
 * С использованием беззнакового 8-байтового числа
 * можно корректно посчитать факториал до 19 включительно
 */
typedef unsigned long long uint64;

uint64 fact(int N, uint64 *arr)
{
    if (N <= 2 || arr[N] != 0)
    {
        return arr[N];
    }

    for (int i = 3; i <= N; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = arr[i - 1] * i;
        }
    }

    return arr[N];
}

double F(double x, int N, uint64 *arr)
{
    double res = 0;
    for (int i = N; i > 0; i--)
    {
        res += (pow(x, 3 * i) * log(3 * x + i) / fact(i, arr));
    }
    return res;
}

int main()
{
    int N;
    double x;

    std::cout << "N = ";
    std::cin >> N;
    std::cout << "x = ";
    std::cin >> x;

    uint64 *arr = new uint64[N + 1]{0};

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    std::cout << "F(x, N) = F(" << x << "," << N << ") = " << F(x, N, arr) << "\n";

    return 0;
}
