#include <stdio.h>
#include <cs50.h>

char inputArray[2][100] =
{
    {
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '0',
    } ,
    {
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '1',

    }
};

int tempRotation[] =
{
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,

};

void setRotationOfTempArray();
void copyTempArrayToInput(int targetArr);
void addTheTwoArrays();
void printInputArray(int targetArr);

int main()
{
    for (int i = 0; i < 479; i++)
    {
        addTheTwoArrays();
        setRotationOfTempArray();
        if (i % 2 == 0)
        {
            copyTempArrayToInput(0);
            printInputArray(0);
        }
        else
        {
            copyTempArrayToInput(1);
            printInputArray(1);
        }
    }
}

void setRotationOfTempArray()
{
    for (int x = 99; x != -1; x--)
    {
        if (tempRotation[x] >= 10)
        {
            tempRotation[x] -= 10;
            if (tempRotation[x - 1] == -1)
            {
                tempRotation[x - 1] += 2;
            }
            else
            {
                tempRotation[x - 1]++;
            }
        }
        if (tempRotation[x] == -1)
        {
            break;
        }
    }

}

void copyTempArrayToInput(int targetArr)
{
    for (int x = 99; x != -1; x--)
    {
        if (tempRotation[x] == -1)
        {
            break;
        }
        inputArray[targetArr][x] = tempRotation[x] + 48;
    }
}

void addTheTwoArrays()
{
    for (int j = 99; j != -1; j--)
    {
        if (inputArray[0][j] != '\0' && inputArray[1][j] != '\0')
        {
            tempRotation[j] = inputArray[0][j] - 48 + inputArray[1][j] - 48;
        }
        else
        {
            break;
        }

        /* doesn't work (don't know why)
        if (inputArray[0][j] == '\0' && inputArray[1][j] == '\0')
        {
            break;
        }
        tempRotation[j] = inputArray[0][j] - 48 + inputArray[1][j] - 48;
        */
    }
}

void printInputArray(int targetArr)
{
    for (int x = 0; x < 100; x++)
    {
        if (inputArray[targetArr][x] != '\0')
        {
            printf("%c", inputArray[targetArr][x]);
        }
    }
    printf("\n");
}