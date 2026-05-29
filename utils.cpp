template <typename T>
void parr(T *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << i << "] = " << arr[i] << '\n';
    }

    std::cout << std::endl;
}