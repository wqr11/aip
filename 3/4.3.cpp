#include <iostream>
#include <cmath>

using namespace std;

double z(double x, double a, double b)
{
    if (x <= 20)
    {
        return (x - a) / (b - x) + exp(pow((a * tan(x)), 0.25));
    }

    return (x - a) / pow(b - x, 1.0 / 6.0);
}

int main()
{
    double xn, xk, dx, a, b;

    cout << "xn = ";
    cin >> xn;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "x z" << '\n';

    for (double x = xn; x < xk; x += dx)
    {

        if ((b - x) == 0 || (a * tan(x) < 0))
        {
            cout << x << " no solution" << '\n';
        }
        else
        {

            cout << x << ' ' << z(x, a, b) << '\n';
        }
    }

    cout << xk << ' ' << z(xk, a, b) << endl;
}