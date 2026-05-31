#include <iostream>
#include <ctime>

using namespace std;

const int DIM = 28;

struct Domino
{
    int left;
    int right;
};

bool isEqual(Domino a, Domino b)
{
    return (a.left == b.left && a.right == b.right) ||
           (a.left == b.right && a.right == b.left);
}

void printDominoes(Domino d[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << "[" << d[i].left << "|" << d[i].right << "] ";
    cout << endl;
}

int main()
{
    srand(time(nullptr));

    Domino set[DIM];

    for (int i = DIM - 1; i >= 0; i--)
    {
        set[i].left = rand() % 6 + 1;
        set[i].right = rand() % 6 + 1;
    }

    int n = DIM;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (isEqual(set[i], set[j]))
            {
                for (int k = j; k < n - 1; ++k)
                    set[k] = set[k + 1];
                --n;
                --j;
            }
        }
    }

    cout << "После чистки дубликатов:\n";
    printDominoes(set, n);

    Domino sorted[n];
    int used[n] = {0};
    int sortedCount = 0;

    sorted[sortedCount] = set[0];
    ++sortedCount;
    used[0] = 1;

    while (sortedCount < n)
    {
        int lastRight = sorted[sortedCount - 1].right;
        bool found = false;
        for (int i = 0; i < n; ++i)
        {
            if (!used[i] && set[i].left == lastRight)
            {
                sorted[sortedCount] = set[i];
                ++sortedCount;
                used[i] = 1;
                found = true;
                break;
            }
            if (!used[i] && set[i].right == lastRight)
            {
                Domino temp;
                temp.left = set[i].right;
                temp.right = set[i].left;
                sorted[sortedCount] = temp;
                ++sortedCount;
                used[i] = 1;
                found = true;
                break;
            }
        }
        if (!found)
            break;
    }

    cout << "\nЦепочка домино:\n";
    printDominoes(sorted, sortedCount);

    return 0;
}