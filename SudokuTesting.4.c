#include <stdio.h>
#include <cs50.h>

int ** initialiseTempAarray();
int ** findtheArray(size_t row, size_t column);
void print(int ** input);
void freeTempArray(int ** arrayToBeFreed);
bool isNotSolvedYet();
void printall();

int mainArray[9][9] =
{
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    /*================================*/
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    /*================================*/
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,
};

int main(void)
{
    /*
    now we can get the coresponding box by changing 0,0 to whatever we want
    testing methods (to be deleted later)
    int ** findMeThisArr = findtheArray(0, 0);
    print(findMeThisArr);
    freeTempArray(findMeThisArr);
    */
    while (isNotSolvedYet())
    {
        /*
        here we start solving
        first we see the row if only one number is missing =1=
        then we see the column if only one number is missing =2=
        and then we see the internal box where the we are if only one number is missing =3=
        last, we use logic to elemniate impossible numbers =4=
        */
        for (int i = 0; i < 9; i++)
        {
            //=1=
            for (int j = 0; j < 9; j++)
            {
                //=2=
                //=3=
                //=4=
            }
        }
    }
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
    switch (row)
    {
        case 0 ... 2:
            switch (column)
            {
                case 0 ... 2:
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            array[i][j] = mainArray[i][j];
                        }
                    }
                    break;
                case 3 ... 5:
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            array[i][j] = mainArray[i][3 + j];
                        }
                    }
                    break;
                case 6 ... 8:
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            array[i][j] = mainArray[i][6 + j];
                        }
                    }
            }
            break;
        case 3 ... 5:
            switch (column)
            {
                case 0 ... 2:
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            array[i][j] = mainArray[3 + i][j];
                        }
                    }
                    break;
                case 3 ... 5:
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            array[i][j] = mainArray[3 + i][3 + j];
                        }
                    }
                    break;
                case 6 ... 8:
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            array[i][j] = mainArray[3 + i][6 + j];
                        }
                    }
            }
            break;
        case 6 ... 8:
            switch (column)
            {
                case 0 ... 2:
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            array[i][j] = mainArray[6 + i][j];
                        }
                    }
                    break;
                case 3 ... 5:
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            array[i][j] = mainArray[6 + i][3 + j];
                        }
                    }
                    break;
                case 6 ... 8:
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            array[i][j] = mainArray[6 + i][6 + j];
                        }
                    }
            }
    }
    return array;
}

void print(int ** input)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i,%i = %i\n",i , j , input[i][j]);
        }
    }
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

bool checkThisRow(int row)
{
    bool onlyOnePossibility = false;
    int columnOfThisOnePossibility = -1;
    int valueToBeSet = 0;
    for (int currentColumn = 0; currentColumn < 9; currentColumn++)
    {
        if (mainArray[row][currentColumn] == 0 && columnOfThisOnePossibility == -1)
        {
            onlyOnePossibility = true;
            columnOfThisOnePossibility = currentColumn;
        }
        else
        {
            onlyOnePossibility = false
            break;
        }
    }
    if (onlyOnePossibility)
    {
        for (int currentColumn = 0; currentColumn < 9; currentColumn++)
        {
            for (int numberToBeSet = 1; numberToBeSet <= 9; numberToBeSet++)
            {
                if (numberToBeSet != mainArray[row][currentColumn])
                {

                }
            }
        }
        //mainArray[row][columnOfThisOnePossibility] =
    }
}