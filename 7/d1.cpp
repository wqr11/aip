#include <iostream>
#include <cstring>

using namespace std;

int Kol_Slov(const char *str)
{
    int count = 0;
    bool in_word = false;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] != ' ')
        {
            if (!in_word)
            {
                ++count;
                in_word = true;
            }
        }
        else
        {
            in_word = false;
        }
    }
    return count;
}

void Poisk_dlinnogo_slova(const char *str, char *longest)
{
    char temp[200];
    char max_word[200] = "";
    int max_len = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] != ' ')
        {
            temp[j] = str[i];
            ++j;
        }
        else
        {
            if (j > 0)
            {
                temp[j] = '\0';
                if (j > max_len)
                {
                    max_len = j;
                    strcpy(max_word, temp);
                }
                j = 0;
            }
        }
    }

    if (j > 0)
    {
        temp[j] = '\0';
        if (j > max_len)
        {
            strcpy(max_word, temp);
        }
    }

    strcpy(longest, max_word);
}

int main()
{
    char input[500];
    char longest[200];

    cout << "Введите строку: ";
    cin.getline(input, 500);

    cout << "Количество слов: " << Kol_Slov(input) << endl;

    Poisk_dlinnogo_slova(input, longest);
    cout << "Самое длинное слово: " << longest << endl;

    return 0;
}