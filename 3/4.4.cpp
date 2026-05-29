#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::min;

int main()
{
    int N = 0;
    int count = 0;
    double EM = 0.0, EN = 0.0;
    double max_s_reduction = 0.0;
    double total_s_thrown = 0.0;

    std::cout << "N = ";
    std::cin >> N;

    std::cout << "(m,n) = ";

    std::cin >> EM;
    std::cin >> EN;

    --N;
    ++count;

    while (N > 0)
    {
        double m = 0.0, n = 0.0;

        std::cin >> m;
        std::cin >> n;

        /**
         * По условию задачи не ясно, какие пластины отбрасывать.
         * Поэтому, отбрасываем те, где k - не целое число
         */
        double k = min(EM / m, EN / n);

        if (int(k) != k)
        {
            if (m * n > max_s_reduction)
            {
                max_s_reduction = m * n;
            }
            total_s_thrown += m * n;
        }
        else
        {

            ++count;
        }

        --N;
    }
}