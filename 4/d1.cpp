#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, x, eps;
    cout << "a, x, eps = ";
    cin >> a >> x >> eps;

    double y_prev = a;
    double y_curr;

    while (true)
    {
        y_curr = 0.5 * (y_prev + x / y_prev);
        if (fabs(y_curr * y_curr - y_prev * y_prev) < eps)
            break;
        y_prev = y_curr;
    }

    cout << "yn = " << y_curr << endl;
    return 0;
}