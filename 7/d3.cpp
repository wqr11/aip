#include <cstring>
#include <iostream>

using namespace std;

char string1[] = "A string\tof ,,tokens\nand some more tokens";
char string2[] = "Another string\n\tparsed at the same time.";
char separators[] = " ,\t\n";
char *token1, *token2, *next_token1, *next_token2;

int main()
{
    cout << "Tokens:" << endl;
    token1 = strtok_r(string1, separators, &next_token1);
    token2 = strtok_r(string2, separators, &next_token2);
    while ((token1 != NULL) || (token2 != NULL))
    {
        if (token1 != NULL)
        {
            cout << token1 << endl;
            token1 = strtok_r(NULL, separators, &next_token1);
        }
        if (token2 != NULL)
        {
            cout << " " << token2 << endl;
            token2 = strtok_r(NULL, separators, &next_token2);
        }
    }

    return 0;
}