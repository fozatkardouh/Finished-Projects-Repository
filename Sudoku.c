#include <stdio.h>
#include <cs50.h>

//start the array
int arr[9][9] =
{
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,   //  initializers for row 0
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,   //  initializers for row 1
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,   //  initializers for row 2
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,   //  initializers for row 3
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,   //  initializers for row 4
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,   //  initializers for row 5
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,   //  initializers for row 6
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,   //  initializers for row 7
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,   //  initializers for row 8
};
//just to print the result
void print(void);

int main(void)
{
    arr[2][7] = 7;
    print();
}

void print(void)
{
    for (int row = 0; row <= 8; row++)
    {
        if (row % 3 == 0)
        {
            printf(" ==================================\n");
        }
        for (int column = 0; column <= 8; column++)
        {
            if (column % 3 == 0)
            {
                printf(" || %i", arr[row][column]);
            }
            else
            {
                if (column == 8)
                {
                    printf("  %i||", arr[row][column]);
                }
                else
                {
                    printf("  %i", arr[row][column]);
                }
            }
        }
        printf("\n");
        if (row == 8)
        {
            printf(" ==================================\n");
        }
    }
}