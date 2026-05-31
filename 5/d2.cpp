#include <iostream>
#include <ctime>

using namespace std;

const int WIDTH = 44;
const int HEIGHT = 24;

int randX()
{
    return rand() % WIDTH;
}

int randY()
{
    return rand() % HEIGHT;
}

void draw_side(char screen[HEIGHT][WIDTH], int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    if (steps > 0)
    {
        for (int i = 0; i <= steps; i++)
        {
            int xt = x1 + i * dx / steps;
            int yt = y1 + i * dy / steps;
            if (xt >= 0 && xt < WIDTH && yt >= 0 && yt < HEIGHT)
                screen[yt][xt] = ' ';
        }
    }
}

int main()
{
    srand(time(nullptr));

    int x1 = randX();
    int y1 = rand() % (HEIGHT / 3);

    int x2 = rand() % (WIDTH / 3);
    int y2 = randY();

    int x3 = (WIDTH * 2 / 3) + rand() % (WIDTH / 3);
    int y3 = randY();

    char screen[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            screen[i][j] = '.';

    draw_side(screen, x1, y1, x2, y2);
    draw_side(screen, x2, y2, x3, y3);
    draw_side(screen, x1, y1, x3, y3);

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cout << screen[i][j];
        }
        cout << endl;
    }

    return 0;
}