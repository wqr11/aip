#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void init_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        unsigned int x = rand();
        int k2 = rand() % 8;
        int k1 = 1 + rand() % 4;

        arr[i] = (x >> k2) & ((1 << k1) - 1);
    }
}

void init_array(double *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        double C = 1 + rand() % 1000;
        double D = 1 + rand() % 1000;

        double ratio = C / D;
        double frac = ratio - static_cast<int>(ratio);

        arr[i] = frac;
    }
}

template <typename T>
void print_array(const T *arr, int size, const char *name)
{
    cout << name << " = [";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "]" << '\n';
}

template <typename T>
void transform_array(T *arr, int size, double p)
{
    T *temp = new T[size];
    int left = 0;
    int right = size - 1;

    for (int i = 0; i < size; i++)
    {
        if (fabs(arr[i]) <= p)
        {
            temp[left++] = arr[i];
        }
        else
        {
            temp[right--] = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }

    delete[] temp;
}

int main()
{
    srand(time(nullptr));

    double p;

    cout << "p = ";
    cin >> p;

    const int N = 5;
    const int M = 10;
    int sizeA = N + rand() % (M - N + 1);
    int sizeB = N + rand() % (M - N + 1);

    cout << "Размер массива A: " << sizeA << '\n';
    cout << "Размер массива B: " << sizeB << '\n';

    int *A = new int[sizeA];
    double *B = new double[sizeB];

    init_array(A, sizeA);
    init_array(B, sizeB);

    cout << "Массивы A и B:" << '\n';
    print_array(A, sizeA, "A");
    print_array(B, sizeB, "B");

    transform_array(A, sizeA, p);
    transform_array(B, sizeB, p);

    cout << "Преобразованные массивы:\n";
    print_array(A, sizeA, "A");
    print_array(B, sizeB, "B");

    delete[] A;
    delete[] B;

    return 0;
}