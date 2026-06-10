#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a[3];
    cout << "(a,b,c) = ";
    cin >> a[0] >> a[1] >> a[2];

    double med[3];

    for (int k = 0; k < 3; k++)
    {
        int m, n;
        switch (k)
        {
        case 0:
            m = 1;
            n = 2;
            break;
        case 1:
            m = 0;
            n = 2;
            break;
        case 2:
            m = 0;
            n = 1;
            break;
        }
        med[k] = 0.5 * sqrt(2 * (a[m] * a[m] + a[n] * a[n]) - a[k] * a[k]);
    }

    double min_med = med[0];
    for (int i = 1; i < 3; i++)
    {
        if (med[i] < min_med)
            min_med = med[i];
    }

    cout << "Кратчайшая медиана = " << min_med << endl;

    return 0;
}