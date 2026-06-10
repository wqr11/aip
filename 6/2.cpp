#include <iostream>
#include <cmath>

using namespace std;

constexpr int INTSIZE = sizeof(int) * 8;
constexpr int DIM = 10;

int count_bits(unsigned int value)
{
    int c = 0;
    for (int i = 0; i < sizeof(int) * 8; ++i)
    {
        c += (value >> i) & 1;
    }
    return c;
}

void init_arr(unsigned int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        arr[i] = i << 24 | (i + 1);
}

int main()
{
    unsigned int arr[DIM];

    init_arr(arr, DIM);

    for (int i = 0; i < 10; ++i)
    {
        cout << "bits of a[" << i << "] = " << count_bits(arr[i]) << '\n';
    }
}