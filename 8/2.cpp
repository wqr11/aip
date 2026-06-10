#include <iostream>
#include <cstring>

using namespace std;

struct DVD
{
    char *album;
    char *author;
    char *style;
    int year;
    int duration;
    int price;

    ~DVD()
    {
        delete[] album;
        delete[] author;
        delete[] style;
    }
};

bool startswith(const char *str, const char *prefix)
{
    int len = strlen(prefix);
    return strncmp(str, prefix, len) == 0;
}

int partition(DVD **arr, int l, int r)
{
    int pivot = arr[(l + r) / 2]->price;
    int i = l - 1;
    int j = r + 1;
    while (true)
    {
        do
        {
            ++i;
        } while (arr[i]->price < pivot);
        do
        {
            --j;
        } while (arr[j]->price > pivot);
        if (i >= j)
            return j;
        DVD *t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

void quick_sort(DVD **arr, int l, int r)
{
    if (l >= r)
        return;
    int pivot = partition(arr, l, r);
    quick_sort(arr, l, pivot);
    quick_sort(arr, pivot + 1, r);
}

void quick_sort_wrapper(DVD **arr, int size)
{
    if (size <= 1)
        return;
    quick_sort(arr, 0, size - 1);
}

int filter_by_author(DVD **src, DVD **dest, int size)
{
    int cur_dest = 0;
    for (int i = 0; i < size; ++i)
    {
        if (startswith(src[i]->author, "Б"))
        {
            dest[cur_dest] = src[i];
            ++cur_dest;
        }
    }
    return cur_dest;
}

int main()
{
    int N;
    cout << "N = ";
    cin >> N;

    DVD **arr = new DVD *[N];
    for (int i = 0; i < N; ++i)
    {
        char album[1024], author[1024], style[1024];
        int year(0), duration(0);
        int price(0);
        cin >> album >> author >> style >> year >> duration >> price;

        char *album_copy = new char[strlen(album) + 1];
        char *author_copy = new char[strlen(author) + 1];
        char *style_copy = new char[strlen(style) + 1];

        strcpy(album_copy, album);
        strcpy(author_copy, author);
        strcpy(style_copy, style);

        arr[i] = new DVD{album_copy, author_copy, style_copy, year, duration, price};
    }

    DVD **newarr = new DVD *[N];
    int filtered_size = filter_by_author(arr, newarr, N);
    quick_sort_wrapper(newarr, filtered_size);

    cout << "\nАльбом Автор Цена" << '\n';

    for (int i = 0; i < filtered_size; ++i)
    {
        cout << newarr[i]->album << " "
             << newarr[i]->author << " "
             << newarr[i]->price << '\n';
    }

    for (int i = 0; i < N; ++i)
        delete arr[i];
    delete[] arr;
    delete[] newarr;
}