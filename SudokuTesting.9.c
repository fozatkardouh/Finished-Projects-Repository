#include <stdio.h>
#include <cs50.h>

int ** initialiseTempAarray();
int ** findtheArray(size_t row, size_t column);
void freeTempArray(int ** arrayToBeFreed);
bool isNotSolvedYet();
bool findNumberInArray(int num, int arr[9]);
void printall();
void finishThisRow(int row);
void finishThisColumn(int column);
void finishThisBox(int numOfBox);

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
        finishThisRow(i);
        finishThisColumn(i);
        finishThisBox(i);
    }
    //while (isNotSolvedYet())
    //{
        //
    //}
    printall();
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

bool findNumberInArray(int num, int arr[9])
{
    for (int i = 0; i < 9; i++)
    {
        if(arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

int ** initialiseTempAarray()
{
    int ** array = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        array[i] = malloc(3 * sizeof(int));
    }
    return array;
}

int ** findtheArray(size_t row, size_t column)
{
    int ** array = initialiseTempAarray();
    int adjustingVariableForRow = 0;
    int adjustingVariableForColumn = 0;
    switch (row)
    {
        case 3 ... 6:
            adjustingVariableForRow = 3;
            break;
        case 7 ... 8:
            adjustingVariableForRow = 6;
            break;
        default:
            break;
    }
    switch (column)
    {
        case 3 ... 6:
            adjustingVariableForColumn = 3;
            break;
        case 7 ... 8:
            adjustingVariableForColumn = 6;
            break;
        default:
            break;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = mainArray[adjustingVariableForRow+i][adjustingVariableForColumn+j];
        }
    }
    return array;
}

void freeTempArray(int ** arrayToBeFreed)
{
    for (int i = 0; i < 3; ++i)
    {
        free(arrayToBeFreed[i]);
    }
    free(arrayToBeFreed);
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

void finishThisRow(int row)
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

void finishThisColumn(int column)
{
    bool onlyOnePossibility = false;
    int rowOfThisOnePossibility = -1;
    for (int currentRow = 0; currentRow < 9; currentRow++)
    {
        if (mainArray[currentRow][column] == 0)
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
            numberToBeSet -= mainArray[row][column];
        }
        mainArray[rowOfThisOnePossibility][column] = numberToBeSet;
    }
}

void finishThisBox(int numOfBox)
{
    bool onlyOnePossibility = false;
    int locationThisOnePossibility[2] = { -1, -1 };
    int toComper[2] = { -1, -1 };
    switch (numOfBox)
    {
        case 0:
            for (int row = 0; row < 3; row++)
            {
                for (int column = 0; column < 3; column++)
                {
                    if (mainArray[row][column] == 0)
                    {
                        if (locationThisOnePossibility[0] == toComper[0] && locationThisOnePossibility[1] == toComper[1])
                        {
                            onlyOnePossibility = true;
                            locationThisOnePossibility[0] = row;
                            locationThisOnePossibility[1] = column;
                        }
                        else
                        {
                            onlyOnePossibility = false;
                            break;
                        }
                    }
                }
            }
            break;
        case 1:
            for (int row = 0; row < 3; row++)
            {
                for (int column = 3; column < 6; column++)
                {
                    if (mainArray[row][column] == 0)
                    {
                        if (locationThisOnePossibility[0] == toComper[0] && locationThisOnePossibility[1] == toComper[1])
                        {
                            onlyOnePossibility = true;
                            locationThisOnePossibility[0] = row;
                            locationThisOnePossibility[1] = column;
                        }
                        else
                        {
                            onlyOnePossibility = false;
                            break;
                        }
                    }
                }
            }
            break;
        case 2:
            for (int row = 0; row < 3; row++)
            {
                for (int column = 6; column < 9; column++)
                {
                    if (mainArray[row][column] == 0)
                    {
                        if (locationThisOnePossibility[0] == toComper[0] && locationThisOnePossibility[1] == toComper[1])
                        {
                            onlyOnePossibility = true;
                            locationThisOnePossibility[0] = row;
                            locationThisOnePossibility[1] = column;
                        }
                        else
                        {
                            onlyOnePossibility = false;
                            break;
                        }
                    }
                }
            }
            break;
        case 3:
            for (int row = 3; row < 6; row++)
            {
                for (int column = 0; column < 3; column++)
                {
                    if (mainArray[row][column] == 0)
                    {
                        if (locationThisOnePossibility[0] == toComper[0] && locationThisOnePossibility[1] == toComper[1])
                        {
                            onlyOnePossibility = true;
                            locationThisOnePossibility[0] = row;
                            locationThisOnePossibility[1] = column;
                        }
                        else
                        {
                            onlyOnePossibility = false;
                            break;
                        }
                    }
                }
            }
            break;
        case 4:
            for (int row = 3; row < 6; row++)
            {
                for (int column = 3; column < 6; column++)
                {
                    if (mainArray[row][column] == 0)
                    {
                        if (locationThisOnePossibility[0] == toComper[0] && locationThisOnePossibility[1] == toComper[1])
                        {
                            onlyOnePossibility = true;
                            locationThisOnePossibility[0] = row;
                            locationThisOnePossibility[1] = column;
                        }
                        else
                        {
                            onlyOnePossibility = false;
                            break;
                        }
                    }
                }
            }
            break;
        case 5:
            for (int row = 3; row < 6; row++)
            {
                for (int column = 6; column < 9; column++)
                {
                    if (mainArray[row][column] == 0)
                    {
                        if (locationThisOnePossibility[0] == toComper[0] && locationThisOnePossibility[1] == toComper[1])
                        {
                            onlyOnePossibility = true;
                            locationThisOnePossibility[0] = row;
                            locationThisOnePossibility[1] = column;
                        }
                        else
                        {
                            onlyOnePossibility = false;
                            break;
                        }
                    }
                }
            }
            break;
        case 6:
            for (int row = 6; row < 9; row++)
            {
                for (int column = 0; column < 3; column++)
                {
                    if (mainArray[row][column] == 0)
                    {
                        if (locationThisOnePossibility[0] == toComper[0] && locationThisOnePossibility[1] == toComper[1])
                        {
                            onlyOnePossibility = true;
                            locationThisOnePossibility[0] = row;
                            locationThisOnePossibility[1] = column;
                        }
                        else
                        {
                            onlyOnePossibility = false;
                            break;
                        }
                    }
                }
            }
            break;
        case 7:
            for (int row = 6; row < 9; row++)
            {
                for (int column = 3; column < 6; column++)
                {
                    if (mainArray[row][column] == 0)
                    {
                        if (locationThisOnePossibility[0] == toComper[0] && locationThisOnePossibility[1] == toComper[1])
                        {
                            onlyOnePossibility = true;
                            locationThisOnePossibility[0] = row;
                            locationThisOnePossibility[1] = column;
                        }
                        else
                        {
                            onlyOnePossibility = false;
                            break;
                        }
                    }
                }
            }
            break;
        case 8:
            for (int row = 6; row < 9; row++)
            {
                for (int column = 6; column < 9; column++)
                {
                    if (mainArray[row][column] == 0)
                    {
                        if (locationThisOnePossibility[0] == toComper[0] && locationThisOnePossibility[1] == toComper[1])
                        {
                            onlyOnePossibility = true;
                            locationThisOnePossibility[0] = row;
                            locationThisOnePossibility[1] = column;
                        }
                        else
                        {
                            onlyOnePossibility = false;
                            break;
                        }
                    }
                }
            }
            break;
    }
    if (onlyOnePossibility)
    {
        int numberToBeSet = 45;
        int ** findMeThisArr = findtheArray(locationThisOnePossibility[0], locationThisOnePossibility[1]);
        for (int row = 0; row < 3; row++)
        {
            for (int column = 0 ; column < 3; column++)
            {
                numberToBeSet -= findMeThisArr[row][column];
            }
        }
        freeTempArray(findMeThisArr);
        mainArray[locationThisOnePossibility[0]][locationThisOnePossibility[1]] = numberToBeSet;
    }
}
