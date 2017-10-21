#include <stdio.h>
#include <cs50.h>

void checkThisRow(int row);
void printall();

int mainArray[9][9] =
{
    {1, 2, 3,/**/ 4, 0, 6,/**/ 7, 8, 9} ,
    {4, 5, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {7, 8, 9,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    /*================================*/
    {3, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {6, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    /*================================*/
    {9, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {8, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {2, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
};

int main(void)
{
    for (int i = 0; i < 9; i++)
    {
        checkThisRow(i);
    }
    printall();
}

void checkThisRow(int row)
{
    bool onlyOnePossibility = false;
    int columnOfThisOnePossibility = -1;
    for (int currentColumn = 0; currentColumn < 9; currentColumn++)
    {
        if (mainArray[row][currentColumn] == 0)
        {
            if (columnOfThisOnePossibility == -1)
            {
                onlyOnePossibility = true;
                columnOfThisOnePossibility = currentColumn;
            }
            else
            {
                onlyOnePossibility = false;
                break;
            }
        }
    }
    if (onlyOnePossibility)
    {
        int numberToBeSet = 45;
        for (int column = 0; column < 9; column++)
        {
            numberToBeSet -= mainArray[row][column];
        }
        mainArray[row][columnOfThisOnePossibility] = numberToBeSet;
    }
}

void printall()
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
                printf(" || %i", mainArray[row][column]);
            }
            else
            {
                if (column == 8)
                {
                    printf("  %i||", mainArray[row][column]);
                }
                else
                {
                    printf("  %i", mainArray[row][column]);
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