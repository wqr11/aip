#include <iostream>

double min(double x, double y)
{
    return x < y ? x : y;
}

using namespace std;

int main()
{
    int N;
    long long EM, EN;

    cout << "N = ";
    cin >> N;

    cout << "(m,n):\n";
    cin >> EM >> EN;

    long long total_s_cut = 0;
    long long total_s_thrown = 0;
    long long max_s_cut = 0;

    for (int i = 1; i < N; ++i)
    {
        long long m, n;
        cin >> m >> n;

        long long k = min(m / EM, n / EN);

        if (k == 0)
        {
            total_s_thrown += m * n;
        }
        else
        {
            // Пластину обрезаем до размеров (k*M) x (k*N)
            long long cut_area = m * n - k * k * EM * EN;
            total_s_cut += cut_area;
            if (cut_area > max_s_cut)
            {
                max_s_cut = cut_area;
            }
        }
    }

    cout << "а) Обработано: " << N << " пластинок(-ки)\n";
    cout << "б) Максимальная площадь обрезки: " << max_s_cut << "\n";
    cout << "в) Общая площадь обрезки: " << total_s_cut + total_s_thrown << "\n";

    return 0;
}