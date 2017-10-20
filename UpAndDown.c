#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string input;
    do
    {
        input = get_string();
    }
    while (input == NULL);

    bool isUp = true;
    for (int i = 0, j = strlen(input); i < j; i++)
    {
        if (input[i] == ' ')
        {
            printf("%c", input[i]);
        }
        else
        {
            if (isUp)
            {
                printf("%c", toupper(input[i]));
                isUp = false;
            }
            else
            {
                printf("%c", input[i]);
                isUp = true;
            }
        }
    }
    printf("\n");
}