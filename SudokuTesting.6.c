#include <stdio.h>
#include <cs50.h>

void checkThisRow(int row);
void checkThisColumn(int Column);
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
        checkThisColumn(i);
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

void checkThisColumn(int Column)
{
    bool onlyOnePossibility = false;
    int rowOfThisOnePossibility = -1;
    for (int currentRow = 0; currentRow < 9; currentRow++)
    {
        if (mainArray[currentRow][Column] == 0)
        {
            if (rowOfThisOnePossibility == -1)
            {
                onlyOnePossibility = true;
                rowOfThisOnePossibility = currentRow;
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
        for (int row = 0; row < 9; row++)
        {
            numberToBeSet -= mainArray[row][Column];
        }
        mainArray[rowOfThisOnePossibility][Column] = numberToBeSet;
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