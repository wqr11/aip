#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(nullptr));

    const int BOXES = 10;
    double money[BOXES];
    double M;

    cout << "M = ";
    cin >> M;

    double max_money_per_box = M / 10.0;
    double sum = 0;

    for (int i = 0; i < BOXES - 1; ++i)
    {
        money[i] = rand() % (static_cast<int>(M / 10.0 - sum) * 100) / 100;
        sum += money[i];
    }

    money[BOXES - 1] = M - sum;

    cout << "Деньги в штатулках:\n";
    for (int i = 0; i < BOXES; ++i)
        cout << money[i] << " ";

    cout << endl;

    int player = 1;
    bool game_over = false;

    while (!game_over)
    {
        int n = 1 + rand() % 3;

        double won = 0;

        for (int i = 0; n > 0; ++i)
        {
            if (money[i] > 0)
            {
                won += money[i];
                money[i] = 0;
                --n;
            }
        }

        if (won == 0)
        {
            game_over = true;
            break;
        }

        cout << "Игрок " << player << " выиграл: " << won << endl;
        ++player;

        game_over = true;
        for (int i = BOXES - 1; i >= 0; --i)
        {
            if (money[i] > 0)
            {
                game_over = false;
            }
        }
    }

    cout
        << "Игра окончена. Всего игроков: " << player - 1 << endl;
    return 0;
}