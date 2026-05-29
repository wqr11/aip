#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;

const int a1 = -2;
const int a2 = 2;
const int b1 = -2;
const int b2 = 2;

bool makehit(double x, double y)
{
    if ((y <= x + 3) && (y >= 0.6 * x - 0.8) && x * x + y * y <= 16)
    {
        cout << "HIT!" << '\n';
        return true;
    }
    else
    {
        cout << "MISS!" << '\n';
        return false;
    }
}

struct Ball
{
    double x;
    double y;
};

Ball genball()
{
    Ball b;
    b.x = a1 + (double)rand() / RAND_MAX * (a2 - a1);
    b.y = b1 + (double)rand() / RAND_MAX * (b2 - b1);
    return b;
}

int main()
{
    srand(time(0));

    while (true)
    {
        int n = -1;

        cin >> n;

        if (n == 0)
            break;

        Ball b = genball();
        makehit(b.x, b.y);
    }

    return 0;
}