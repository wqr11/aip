#include <iostream>
#include <cmath>

using namespace std;
const double EULER = 2.71828;

double z(double x, double a, double b)
{
    if (x <= 20)
    {
        return (x - a) / (b - x) + pow(EULER, pow((a * tan(x)), 0.25));
    }

    return (x - a) / pow(b - x, 1.0 / 6.0);
}

int main()
{
    double xn, xk, dx, a, b;

    std::cout << "xn = ";
    std::cin >> xn;

    std::cout << "xk = ";
    std::cin >> xk;

    std::cout << "dx = ";
    std::cin >> dx;

    std::cout << "a = ";
    std::cin >> a;

    std::cout << "b = ";
    std::cin >> b;

    std::cout << "x z" << '\n';

    for (double x = xn; x < xk; x += dx)
    {

        if ((b - x) == 0 || (a * tan(x) < 0))
        {
            std::cout << x << " no solution" << '\n';
        }
        else
        {

            std::cout << x << ' ' << z(x, a, b) << '\n';
        }
    }

    // Последнее значение
    std::cout << xk << ' ' << z(xk, a, b) << std::endl;
}