#include <iostream>
#include <cmath>

using namespace std;
double sidelen(double a1, double a2)
{
    double r = a1 - a2;
    if (r < 0)
        r = -r;
    return r;
}

void RectPs(
    double x1,
    double y1,
    double x2,
    double y2,
    double &P,
    double &S)
{

    double a = sidelen(x1, x2);
    double b = sidelen(y1, y2);

    P = 2 * (a + b);
    S = a * b;
}

int main()
{
    double P, S;
    RectPs(0, 0, 5, 3, P, S);
    printf("1: (P,S) = (%.2f, %.2f)\n", P, S);
    RectPs(1, 1, 4, 6, P, S);
    printf("2: (P,S) = (%.2f, %.2f)\n", P, S);
    RectPs(-2, -1, 3, 4, P, S);
    printf("3: (P,S) = (%.2f, %.2f)\n", P, S);
}