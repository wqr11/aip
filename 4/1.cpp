#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

int main()
{
    int n;

    cout << "n = ";
    cin >> n;

    if (n == 0)
    {
        cout << "NO" << std::endl;
        return 0;
    }

    bool was_one = false;

    constexpr int intsize = sizeof(n);

    for (int i = 0; i < intsize; i++)
    {
        if ((n >> i) & 1)
        {
            if (was_one)
            {
                cout << "NO" << std::endl;
                return 0;
            }
            else
            {
                was_one = true;
            }
        };
    }

    cout << "YES" << std::endl;

    return 0;
}