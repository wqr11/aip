#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;

    cout << "n = ";
    cin >> n;

    if (n == 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    bool was_one = false;

    for (int i = 0; i < sizeof(int) * 8; ++i)
    {
        if ((n >> i) & 1)
        {
            if (was_one)
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                was_one = true;
            }
        };
    }

    cout << "YES" << endl;

    return 0;
}