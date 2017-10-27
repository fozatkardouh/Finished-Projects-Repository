#include <stdio.h>
#include <cs50.h>

int locationOfPackman[2];
int locationOfGhost[2];
int rout[][2] =
{
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },
};
int heading = 0; //stationary|| 1 moving to the right || 2 moving up || 3 moving to the left || 4 moving down
int mainArray[18][18] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} ,
    {1,3,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1} , //Packman here at 1.1
    {1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1} ,
    {1,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1} ,
    {1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1} ,
    {1,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,0,1} ,
    {1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1} ,
    {1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1} ,
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1} ,
    {1,0,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1} ,
    {1,1,1,0,1,0,1,0,1,1,0,1,0,0,0,1,0,1} ,
    {1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1} ,
    {1,0,1,1,1,1,1,0,1,1,1,1,0,1,0,1,0,1} ,
    {1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1} ,
    {1,0,1,0,1,0,1,1,1,1,1,0,1,1,0,0,0,1} ,
    {1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,1} ,
    {1,0,0,0,1,0,0,0,1,0,0,0,1,2,0,0,0,1} , //ghost here at 16.13
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} ,
};
int minNumberOfMoves = 100;

void LocateGhost()
{
    bool breakMe = false;
    for (int row = 0; row < 18; row++)
    {
        if (breakMe){ break; }
        for (int column = 0; column < 18; column++)
        {
            if (mainArray[row][column] == 2)
            {
                locationOfGhost[0] = row;
                locationOfGhost[1] = column;
                breakMe = true;
                break;
            }
        }
    }
}

void LocatePackman()
{
    bool breakMe = false;
    for (int row = 0; row < 18; row++)
    {
        if (breakMe){ break; }
        for (int column = 0; column < 18; column++)
        {
            if (mainArray[row][column] == 3)
            {
                locationOfPackman[0] = row;
                locationOfPackman[1] = column;
                breakMe = true;
                break;
            }
        }
    }
}

void copyArray(int currentRout[35][2])
{
    for (int x = 0; x < 35; x++)
    {
        if (currentRout[x][0] != 0)
        {
            rout[x][0] = currentRout[x][0];
            rout[x][1] = currentRout[x][1];
        }
        else
        {
            break;
        }
    }
}

bool RunTheGhost(int locOfGhost[2], int currentRout[35][2], int counterOfMoves, int lastHeading)
{
    if (counterOfMoves == 8)
    {
        printf("8\n");
    }
    if (mainArray[locOfGhost[0]][locOfGhost[1] + 1] == 0 && lastHeading != 3)
    {
        int newLocationOfGhost[2] = {locOfGhost[0], locOfGhost[1] + 1};
        currentRout[counterOfMoves][0] = newLocationOfGhost[0];
        currentRout[counterOfMoves][1] = newLocationOfGhost[1];
        if (mainArray[newLocationOfGhost[0]][newLocationOfGhost[1]] == 3)
        {
            if (counterOfMoves > minNumberOfMoves)
            {
                minNumberOfMoves = counterOfMoves;
                copyArray(currentRout);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return RunTheGhost(newLocationOfGhost, currentRout, ++counterOfMoves, 1);
        }
    }
    if (mainArray[locOfGhost[0] - 1][locOfGhost[1]] == 0 && lastHeading != 4)
    {
        int newLocationOfGhost[2] = {locOfGhost[0] - 1, locOfGhost[1]};
        currentRout[counterOfMoves][0] = newLocationOfGhost[0];
        currentRout[counterOfMoves][1] = newLocationOfGhost[1];
        if (mainArray[newLocationOfGhost[0]][newLocationOfGhost[1]] == 3)
        {
            if (counterOfMoves > minNumberOfMoves)
            {
                minNumberOfMoves = counterOfMoves;
                copyArray(currentRout);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return RunTheGhost(newLocationOfGhost, currentRout, ++counterOfMoves, 2);
        }
    }
    if (mainArray[locOfGhost[0]][locOfGhost[1] - 1] == 0 && lastHeading != 1)
    {
        int newLocationOfGhost[2] = {locOfGhost[0], locOfGhost[1] - 1};
        currentRout[counterOfMoves][0] = newLocationOfGhost[0];
        currentRout[counterOfMoves][1] = newLocationOfGhost[1];
        if (mainArray[newLocationOfGhost[0]][newLocationOfGhost[1]] == 3)
        {
            if (counterOfMoves > minNumberOfMoves)
            {
                minNumberOfMoves = counterOfMoves;
                copyArray(currentRout);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return RunTheGhost(newLocationOfGhost, currentRout, ++counterOfMoves, 3);
        }
    }
    if (mainArray[locOfGhost[0] + 1][locOfGhost[1]] == 0 && lastHeading != 2)
    {
        int newLocationOfGhost[2] = {locOfGhost[0] + 1, locOfGhost[1]};
        currentRout[counterOfMoves][0] = newLocationOfGhost[0];
        currentRout[counterOfMoves][1] = newLocationOfGhost[1];
        if (mainArray[newLocationOfGhost[0]][newLocationOfGhost[1]] == 3)
        {
            if (counterOfMoves > minNumberOfMoves)
            {
                minNumberOfMoves = counterOfMoves;
                copyArray(currentRout);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return RunTheGhost(newLocationOfGhost, currentRout, ++counterOfMoves, 4);
        }
    }
    return false;;
}

int main(void)
{
    LocatePackman();
    LocateGhost();
    if (RunTheGhost(locationOfGhost,rout, 0, heading))
    {
        printf("Success\n");
        return 0;
    }
    else
    {
        printf("Shit\n");
        return 1;
    }
}