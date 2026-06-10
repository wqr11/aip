#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int BOXES = 10;

bool is_game_over(double money[])
{
    bool game_over = true;
    for (int i = BOXES - 1; i >= 0; --i)
    {
        if (money[i] > 0)
        {
            game_over = false;
        }
    }
    return game_over;
}

int main()
{
    srand(time(nullptr));

    double money[BOXES];
    double M;

    cout << "M = ";
    cin >> M;

    double max_money_per_box = M / 10.0;
    double sum = 0;

    for (int i = 0; i < BOXES - 1; ++i)
    {
        money[i] = rand() % ((int)max_money_per_box + 1);
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

        game_over = is_game_over(money);
    }

    cout
        << "Игра окончена. Всего игроков: " << player - 1 << endl;
    return 0;
}