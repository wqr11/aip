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

    /**
     * Есть другие способы, но в данном случае
     * окей, т.к сложность все равно O(1), т.к sizeof(int) - константа для платформы
     */
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