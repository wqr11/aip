#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

double alpha(double t)
{
    double s = sin(3 * t);
    return s * s;
}

double U(double t)
{
    double a = alpha(t);
    return fabs(cos(exp(a))) + (5 * a) / (a + sqrt(a));
}

int main()
{
    srand(time(nullptr));

    const int N = 30;
    double U_values[N];

    double t_max = 0, t_min = 0;
    double U_max = -1e9, U_min = 1e9;

    int max_sec = 0, min_sec = 0;

    cout << "Секунда\tU_теор\tОтнос. погрешность\tU_эксп\n";
    cout << "------------------------------------------------\n";

    for (int sec = 1; sec <= N; sec++)
    {
        double t = sec;
        double Ut = U(t);

        int kd = rand() % 11;
        double d = kd * Ut / 100.0;

        if (rand() % 2 == 0)
        {
            d = -d;
        }

        double U_real = Ut + d;
        U_values[sec - 1] = U_real;

        printf("%d\t%.4f\t\t%.1f%%\t\t%.4f\n", sec, Ut, (double)kd, U_real);

        if (U_real > U_max)
        {
            U_max = U_real;
            max_sec = sec;
        }
        if (U_real < U_min)
        {
            U_min = U_real;
            min_sec = sec;
        }
    }

    cout << "------------------------------------------------\n";
    cout << "Максимальное значение U = " << U_max << " достигнуто на " << max_sec << " секунде\n";
    cout << "Минимальное значение U = " << U_min << " достигнуто на " << min_sec << " секунде\n";

    cout << "\nИнтервалы времени, где U(t) > 2:\n";
    bool in_interval = false;
    int start = 0;

    for (int i = 0; i < N; i++)
    {
        if (U_values[i] > 2 && !in_interval)
        {
            start = i + 1;
            in_interval = true;
        }
        else if (U_values[i] <= 2 && in_interval)
        {
            cout << "  " << start << "-" << i << " секунды\n";
            in_interval = false;
        }
    }
    if (in_interval)
    {
        cout << "  " << start << "-" << N << " секунды\n";
    }

    return 0;
}