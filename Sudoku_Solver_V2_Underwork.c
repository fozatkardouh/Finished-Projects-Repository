#include <stdio.h>
#include <cs50.h>


int mainArray[9][9] =
{
    {4, 5, 1, 2, 0, 7, 3, 6, 0} ,
    {0, 0, 7, 6, 0, 9, 1, 2, 4} ,
    {0, 2, 0, 4, 0, 0, 0, 5, 0} ,

    {0, 9, 0, 0, 0, 2, 0, 0, 0} ,
    {0, 0, 0, 0, 7, 6, 0, 0, 0} ,
    {0, 0, 0, 1, 4, 0, 9, 0, 2} ,

    {7, 0, 4, 0, 6, 0, 2, 9, 8} ,
    {0, 6, 8, 3, 2, 0, 7, 0, 0} ,
    {0, 1, 2, 0, 9, 0, 6, 4, 3} ,
};

void printall()
{
    for (int row = 0; row < 9; row++)
    {
        for (int coulmn = 0; coulmn < 9; coulmn++)
        {
            printf("%i  ", mainArray[row][coulmn]);
        }
        printf("\n");
    }
}

bool checkNumInRow (int row, int column, int num)
{
    if (column == 9)
    {
        return true;
    }
    if (mainArray[row][column] != num)
    {
        checkNumInRow(row, ++column, num);
    }
    return false;
}

bool checkNumInColumn (int row, int column , int num)
{
    if (row == 9)
    {
        return true;
    }
    if (mainArray[row][column] != num)
    {
        checkNumInRow(++row, column, num);
    }
    return false;
}

bool checkNumberInArray(int row, int column, int num)
{
    int startOfRow = row - (row % 3);
    int startOfColumn = column - (column % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mainArray[i + startOfRow][j + startOfColumn] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool checkIt(int row, int column, int numberToTest)
{
    if (checkNumberInArray(row, column, numberToTest) && checkNumInColumn(row, column, numberToTest) && checkNumInRow(row, column, numberToTest))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isNotSolvedYet()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(mainArray[i][j] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void solveIt(int row, int column, int numberToTest)
{
    if (column == 9)
    {
        column = 0;
        row++;
    }
    if (row == 9)
    {
        return;
    }
    if (mainArray[row][column] == 0)
    {
        if (checkIt(row, column, numberToTest))
        {
            mainArray[row][column] = numberToTest;
            solveIt(row, ++column, numberToTest);
        }
    }
    else
    {
        solveIt(row, ++column, numberToTest);
    }
}

int main(void)
{
    int numberToPut = 0;
    while (isNotSolvedYet())
    {
        numberToPut = numberToPut % 9;
        solveIt(0, 0, ++numberToPut);
    }
    printall();
}