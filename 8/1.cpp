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

    str(const char *news)
    {
        *this = news;
    }

    str &operator=(const char *news)
    {
        int len = strlen(news);

        while (capacity <= len)
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

    char *tocharptr()
    {
        return this->s;
    }

    ~str()
    {
        delete[] s;
        s = nullptr;
    }
};

struct Child
{
    str *name;
    char sex;
    uint16 height;
};

double find_peak_and_median(Child *children[], int N)
{
    int peak = 0;
    int total = 0;
    int male_count = 0;
    str *peak_name = nullptr;

    for (int i = 0; i < N; ++i)
    {
        Child *child = children[i];

        if (child->sex == 'M')
        {
            total += child->height;
            male_count++;

            if (child->height > peak)
            {
                peak = child->height;
                peak_name = child->name;
            }
        }
    }

    double avg_height = (male_count > 0) ? static_cast<double>(total) / male_count : 0;

    cout << "Макс. рост мальчика: " << peak << '\n';
    cout << "Средний рост мальчиков: " << avg_height << '\n';

    return avg_height;
}

void print_low_names(Child **children, int N, double avg_height)
{
    cout << "Рост ниже среднего у мальчиков:" << '\n';
    for (int i = 0; i < N; ++i)
    {
        Child *child = children[i];
        if (child->sex == 'M' && child->height < avg_height)
        {
            cout << child->name->tocharptr() << '\n';
        }
    }
}

int main()
{
    int N;
    cout << "N = ";

    cin >> N;

    Child *children[N];

    for (int i = 0; i < N; ++i)
    {
        char name[256];
        char sex;
        uint16 height;

        cin >> name >> sex >> height;
        children[i] = new Child{new str(name), sex, height};
    }

    double avg_height = find_peak_and_median(children, N);
    print_low_names(children, N, avg_height);

    for (int i = N - 1; i >= 0; --i)
    {
        delete children[i]->name;
        delete children[i];
        children[i] = nullptr;
    }

    return 0;
}