#include <iostream>
#include <cstring>

using namespace std;

struct Child
{
    char *name;
    char sex;
    int height;
};

double find_peak_and_median(Child *children[], int N)
{
    int peak = 0;
    int total = 0;
    int male_count = 0;
    char *peak_name = nullptr;

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
            cout << child->name << '\n';
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
        int height;

        cin >> name >> sex >> height;

        char *name_copy = new char[strlen(name) + 1];
        strcpy(name_copy, name);

        children[i] = new Child{name_copy, sex, height};
    }

    double avg_height = find_peak_and_median(children, N);
    print_low_names(children, N, avg_height);

    for (int i = N - 1; i >= 0; --i)
    {
        delete[] children[i]->name;
        delete children[i];
        children[i] = nullptr;
    }

    return 0;
}