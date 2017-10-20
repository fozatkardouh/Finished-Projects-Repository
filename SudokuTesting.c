#include <stdio.h>
#include <cs50.h>

int (*findthebox(void))[3][3];
void print(int * input);

int main(void)
{
    int * temp = findthebox()[0][0];
    print(temp);
}

int (*findthebox(void))[3][3]
{
    static int arr[3][3] =
    {
        { 0,0,0 },
        { 0,5,0 },
        { 0,0,0 },
    };
    return &arr;
}

void print(int * input)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i,%i = %i\n",i , j , *(input + i + j));
        }
    }
    printf("\n");
}