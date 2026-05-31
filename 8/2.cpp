#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

typedef unsigned short int uint16;
typedef unsigned int uint32;

class str
{
private:
    uint32 size = 0;
    uint32 capacity = 1024;
    char *s = new char[capacity]();

public:
    str() {}
    str(const char *news) { *this = news; }

    char *tocharptr() { return this->s; }

    bool startswith(const char *prefix)
    {
        int len = strlen(prefix);
        return strncmp(s, prefix, len) == 0;
    }

    str &operator=(const char *news)
    {
        int len = strlen(news);
        while (capacity <= (uint32)len)
        {
            capacity *= 2;
            char *new_s = new char[capacity]();
            memmove(new_s, s, size);
            delete[] s;
            s = new_s;
        }
        memset(s, 0, size);
        memmove(s, news, len);
        size = len;
        return *this;
    }

    ~str()
    {
        delete[] s;
        s = nullptr;
    }
};

struct DVD
{
    str *album;
    str *author;
    str *style;
    uint16 year;
    uint16 duration;
    uint32 price;

    ~DVD()
    {
        delete album;
        delete author;
        delete style;
    }
};

int partition(DVD **arr, int l, int r)
{
    uint32 pivot = arr[(l + r) / 2]->price;
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
        if (src[i]->author->startswith("Б"))
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
        uint16 year(0), duration(0);
        uint32 price(0);
        cin >> album >> author >> style >> year >> duration >> price;
        arr[i] = new DVD{new str(album), new str(author), new str(style), year, duration, price};
    }

    DVD **newarr = new DVD *[N];
    int filtered_size = filter_by_author(arr, newarr, N);
    quick_sort_wrapper(newarr, filtered_size);

    cout << "\nАльбом Автор Цена" << '\n';

    for (int i = 0; i < filtered_size; ++i)
    {
        cout << newarr[i]->album->tocharptr() << " "
             << newarr[i]->author->tocharptr() << " "
             << newarr[i]->price << "\n";
    }

    for (int i = 0; i < N; ++i)
        delete arr[i];
    delete[] arr;
    delete[] newarr;
}
