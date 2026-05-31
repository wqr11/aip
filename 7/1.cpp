#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    char delimiter[] = " ";
    char *f = nullptr;

    fgets(text, 100, stdin);

    char *token = strtok_r(text, delimiter, &f);

    while (token != nullptr)
    {
        int count_e = 0;

        int i = 0;
        while (token[i] != 0)
        {
            if (token[i] == 'e')
                ++count_e;

            if (token[i] == 10)
            {
                token[i] = 0;
            }

            ++i;
        }

        printf("%s - %i раз(а)\n", token, count_e);

        token = strtok_r(nullptr, delimiter, &f);
    }

    return 0;
}