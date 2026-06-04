#include <iostream>
#include <cstring>

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
        memset(padding, ' ', padsize);
        memset(points, '^', i);

        cout << padding << points << padding << '\n';
    }
}