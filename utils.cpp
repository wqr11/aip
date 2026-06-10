template <typename T>
void parr(T *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "] = " << arr[i] << '\n';
    }

    cout << endl;
}