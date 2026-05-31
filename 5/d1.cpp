#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

bool triangle_exists(double a, double b, double c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double inner_radius(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    return S / p;
}

double outer_radius(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    return (a * b * c) / (4 * S);
}

double rand_double(double minVal, double maxVal)
{
    return minVal + (double)rand() / RAND_MAX * (maxVal - minVal);
}

int main()
{
    srand(time(nullptr));

    for (int i = 1; i <= 3; ++i)
    {
        double a, b, c;

        do
        {
            a = rand_double(3, 15);
            b = rand_double(3, 15);
            c = rand_double(3, 15);
        } while (!triangle_exists(a, b, c));

        double inner_c_radius = inner_radius(a, b, c);
        double outer_c_radius = outer_radius(a, b, c);

        cout << "Треугольник " << i << ": a = " << a << ", b = " << b << ", c = " << c << '\n';
        cout << "Радиус вписанной: " << inner_c_radius << '\n';
        cout << "Радиус описанной: " << outer_c_radius << '\n';
        cout << "Сумма радиусов: " << inner_c_radius + outer_c_radius << '\n';
        cout << "Разность радиусов: " << outer_c_radius - inner_c_radius << "\n\n";
    }

    return 0;
}