#include <iostream>

using namespace std;

int main()
{
    int H;
    cin >> H;

    for (int i = 1; i <= 2 * H; i += 2)
    {
        int padsize = (2 * H - i) / 2;
        char padding[padsize + 1] = {0};
        char points[i + 1] = {0};

        for (int j = padsize - 1; j >= 0; --j)
        {
            padding[j] = ' ';
        }

        for (int j = i - 1; j >= 0; --j)
        {
            points[j] = '^';
        }

        cout << padding << points << padding << '\n';
    }
}