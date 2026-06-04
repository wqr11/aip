#include <iostream>
#include <unordered_map>

using namespace std;
void find_most_encountered_char(char *s, char &mes, int &count)
{
    std::unordered_map<char, int> m;

    int i = 0;
    while (s[i] != 0)
    {
        if (m.find(s[i]) != m.end())
        {
            ++m.at(s[i]);
        }
        else
        {
            m[s[i]] = 1;
        };
        ++i;
    }

    for (auto i = m.cbegin(); i != m.cend(); ++i)
    {
        if (i->second > count)
        {
            count = i->second;
            mes = i->first;
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