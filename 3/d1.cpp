#include <iostream>
using namespace std;

int main()
{
    int money[] = {200, 100, 300, 1000, 250, 150, 900, 50, 700, 650};
    int chips[] = {2, 3, 6, 1, 1, 0, 4, 2, 0, 1};
    int n = 10;

    int total = 0;
    int boxes_opened = 0;
    int max_chips = 0;
    int total_chips = 0;

    for (int i = 0; i < n; ++i)
    {
        if (chips[i] == 0)
        {
            break;
        }
        total += money[i];
        total_chips += chips[i];
        if (chips[i] > max_chips) {
            max_chips = chips[i];
        }
        ++boxes_opened;
    }

    cout << "Открыто шкатулок: " << boxes_opened << endl;
    cout << "Денег выиграно: " << total << endl;

    if (boxes_opened >= 2)
    {
        cout << "Максимальный выигрыш: " << static_cast<double>(total) * max_chips / total_chips << endl;
    }
    else
    {
        cout << "Открыто менее двух шкатулок" << endl;
    }

    return 0;
}
