#include <iostream>
#include <ctime>

using namespace std;

struct Point
{
    double x, y, z;
};

struct Sphere
{
    Point center;
    double radius;
};

bool isHit(Sphere target, Point bullet)
{
    double dx = bullet.x - target.center.x;
    double dy = bullet.y - target.center.y;
    double dz = bullet.z - target.center.z;
    return (dx * dx + dy * dy + dz * dz <= target.radius * target.radius);
}

int main()
{
    srand(time(nullptr));

    Sphere target;
    cout << "Координаты центра шара (x y z): ";
    cin >> target.center.x >> target.center.y >> target.center.z;
    cout << "Радиус шара: ";
    cin >> target.radius;

    Point low, high;
    cout << "Границы куба (min x, max x, min y, max y, min z, max z): ";
    cin >> low.x >> high.x >> low.y >> high.y >> low.z >> high.z;

    int shots;
    cout << "Количество выстрелов: ";
    cin >> shots;

    int hits = 0;
    for (int i = shots; i > 0; --i)
    {
        Point bullet;
        bullet.x = low.x + (double)rand() / RAND_MAX * (high.x - low.x);
        bullet.y = low.y + (double)rand() / RAND_MAX * (high.y - low.y);
        bullet.z = low.z + (double)rand() / RAND_MAX * (high.z - low.z);

        if (isHit(target, bullet))
            ++hits;
    }

    cout << "Всего выстрелов: " << shots << endl;
    cout << "Попаданий: " << hits << endl;
    cout << "Промахов: " << shots - hits << endl;

    return 0;
}