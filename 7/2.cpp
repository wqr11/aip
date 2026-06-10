#include <iostream>

using namespace std;

void find_most_encountered_char(char *s, char &mes, int &count)
{
    int i = 0;

    int char_encounter_map[256] = {0};

    while (s[i] != 0)
    {
        ++char_encounter_map[s[i]];
        ++i;
    }

    for (int i = 0; i < 256; ++i)
    {
        int cur_count = char_encounter_map[i];
        if (cur_count > count)
        {
            count = cur_count;
            mes = i;
        }
    }
}

int main()
{
    FILE *fd = fopen("./2.txt", "r");

    char s[1024] = {0};

    fread(s, 1, 1024, fd);

    cout << "Строка = " << s << '\n';

    char mes;
    int count = 0;

    find_most_encountered_char(s, mes, count);

    cout << mes << " = " << count << '\n';
}