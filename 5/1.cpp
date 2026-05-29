#include <stdio.h>

int main()
{
    int *p1, m = 15, n = 7;
    double *p2, s = 55.e-1, t;
    p1 = &m;
    t = *p1 / 2.0;
    printf("\n t = %.2f\n", t);
    p2 = &s;
    n += (double)(*p2 + m) * (int)t;
    printf("\n n = %d\n", n);
    return 0;
}