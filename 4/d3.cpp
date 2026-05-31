#include <iostream>
using namespace std;

int main()
{
    const long long TOTAL = 5345453567LL;
    long long collected = 0;
    double rate = 3452.0;
    int minutes = 0;

    while (collected < TOTAL)
    {
        minutes += 5;
        collected += rate;
        if (collected >= TOTAL)
        {
            double over = collected - TOTAL;
            double fraction = (rate - over) / rate;
            minutes = (minutes - 5) + static_cast<int>(5 * fraction);
            break;
        }
        rate *= 1.05;
    }

    int days = minutes / (24 * 60);
    minutes %= (24 * 60);
    int hours = minutes / 60;
    minutes %= 60;

    cout << days << " дней " << hours << " часов " << minutes << " минут" << endl;
    return 0;
}