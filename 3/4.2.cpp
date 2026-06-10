#include <iostream>
#include <cmath>

using namespace std;

bool is_sqrt_of_even(int a)
{
    /**
     * false, если:
     * 1) a < 0 - квадрат обязан быть не меньше 0
     * 2) квадрат нечетный
     */

    if (a < 0 || (a % 2) != 0)
    {
        return false;
    }

    int root = static_cast<int>(sqrt(a));

    return root * root == a && root % 2 == 0;
}

int main()
{
    int N;
    cout << "N = ";
    cin >> N;

    int res = 0;

    for (int i = N - 1; i >= 0; --i)
    {
        int a;

        cin >> a;

        if (is_sqrt_of_even(a))
        {
            ++res;
        }
    }

    cout << "res = " << res << endl;
}