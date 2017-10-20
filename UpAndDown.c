#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char input[] = "refugees code is the best";
    bool IsUp = true;
    int counter = 0;
    while (input[counter] != '\0')
    {
        if (input[counter] == ' ')
        {
            counter++;
        }
        else
        {
            if (IsUp)
            {
                input[counter] = toupper(input[counter]);
                counter++;
                IsUp = false;
            }
            else
            {
                IsUp = true;
                counter++;
            }
        }
    }
    printf("%s\n", input);
}