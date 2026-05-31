#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
void printArray(const T arr[], int size, const char *name)
{
    cout << name << ": ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
T sumBetweenNegatives(const T arr[], int size)
{
    int first = -1, last = -1;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    if (first == -1 || last == -1 || first == last)
        return 0;

    T sum = 0;
    for (int i = first + 1; i < last; ++i)
        sum += arr[i];

    return sum;
}

int main()
{
    FILE *fin = fopen("input.txt", "r");

    int count = 0;
    int A[1024] = {0};
    int temp;

    while (fscanf(fin, "%d", &temp) == 1)
    {
        A[count] = temp;
        ++count;
    }

    printArray(A, count, "Массив A");

    double B[count] = {0};

    for (int i = count - 1; i >= 0; --i)
    {
        B[i] = A[i] * sin(i);
    }

    printArray(B, count, "Массив B");

    FILE *fout = fopen("input.txt", "a");

    fprintf(fout, "\n");
    for (int i = 0; i < count; ++i)
    {
        fprintf(fout, "%.3f ", B[i]);
    }
    fclose(fout);

    int sumA = sumBetweenNegatives(A, count);
    double sumB = sumBetweenNegatives(B, count);

    printf("Сумма между первым и последним отрицательными в A: %d\n", sumA);
    printf("Сумма между первым и последним отрицательными в B: %.3f\n", sumB);

    return 0;
}