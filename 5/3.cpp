#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::fabs;

const double eps = 1e-8;

double dist(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

bool is_rt_angled(double a, double b, double c)
{
    return fabs(a * a - (b * b + c * c)) < eps ||
           fabs(b * b - (a * a + c * c)) < eps ||
           fabs(c * c - (a * a + b * b)) < eps;
}

double hypot(double a, double b, double c)
{
    if (fabs(a * a - (b * b + c * c)) < 1e-8)
        return a;
    if (fabs(b * b - (a * a + c * c)) < 1e-8)
        return b;
    return c;
}

double shortest_side(double a, double b, double c)
{
    double minf = a;
    if (b < minf)
        minf = b;
    if (c < minf)
        minf = c;
    return minf;
}

int main()
{
    double x1, y1, x2, y2, x3, y3;

    cout << "(x,y) = ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double la = dist(x2, y2, x3, y3);
    double lb = dist(x1, y1, x3, y3);
    double lc = dist(x1, y1, x2, y2);

    bool is_rt = is_rt_angled(la, lb, lc);

    cout << "IS RIGHT ANGLED = " << is_rt << '\n';

    if (is_rt)
        cout << "HYPOT = " << hypot(la, lb, lc) << '\n';
    else
        cout << "SHORTEST SIDE = " << shortest_side(la, lb, lc) << '\n';

    return 0;
}