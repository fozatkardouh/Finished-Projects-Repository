#include <stdio.h>
#include <cs50.h>

char inputOne[] =
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

};
char inputTwo[] =
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
void setRotation();
int getIntFromChar(char c);
char getCharFromInt(int i);
void moveTempToInput(bool handel);
bool resetNotCompleted();
void addTheTwo();
void printIt(int inputNumber);

int main()
{
    for (int i = 0; i < 479; i++)
    {
        addTheTwo();
        do
        {
            setRotation();
        } while (resetNotCompleted());
        if (i % 2 == 0)
        {
            moveTempToInput(true);
        }
        else
        {
            moveTempToInput(false);
        }
        if (i % 2 == 0)
        {
            printIt(1);
        }
        else
        {
            printIt(2);
        }
    }
}

int getIntFromChar(char c)
{
    switch (c)
    {
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        default:
            return 0;
            break;
    }
}

char getCharFromInt(int i)
{
    switch (i)
    {
        case 0:
            return '0';
            break;
        case 1:
            return '1';
            break;
        case 2:
            return '2';
            break;
        case 3:
            return '3';
            break;
        case 4:
            return '4';
            break;
        case 5:
            return '5';
            break;
        case 6:
            return '6';
            break;
        case 7:
            return '7';
            break;
        case 8:
            return '8';
            break;
        case 9:
            return '9';
            break;
        default:
            return '0';
            break;
    }
}

void setRotation()
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
    }

}

void moveTempToInput(bool handel)
{
    for (int x = 99; x != -1; x--)
    {
        if (tempRotation[x] != -1)
        {
            if (handel)
            {
                inputOne[x] = getCharFromInt(tempRotation[x]);
            }
            else
            {
                inputTwo[x] = getCharFromInt(tempRotation[x]);
            }
        }
        else
        {
            break;
        }
    }
}

bool resetNotCompleted()
{
    for (int x = 99; x != -1; x--)
    {
        if (tempRotation[x] >= 10)
        {
            return true;
        }
        if (tempRotation[x] == -1)
        {
            return false;
        }
    }
    return false;
}

void addTheTwo()
{
    for (int j = 99; j != -1; j--)
    {
        if (inputOne[j] != '\0' && inputTwo[j] != '\0')
        {
            tempRotation[j] = getIntFromChar(inputOne[j]) + getIntFromChar(inputTwo[j]);
        }
        else
        {
            break;
        }
    }
}

void printIt(int inputNumber)
{
    for (int x = 0; x < 100; x++)
    {
        if (inputNumber == 1 && inputOne[x] != '\0')
        {
            printf("%c", inputOne[x]);
        }
        if (inputNumber == 2 && inputTwo[x] != '\0')
        {
            printf("%c", inputTwo[x]);
        }
    }
    printf("\n");
}