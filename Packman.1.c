#include <stdio.h>
#include <cs50.h>

int locationOfPackman[2];
int locationOfGhost[2];
int rout[108][2] =
{
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },    { 0, 0 },
};
int heading = 0; //stationary|| 1 moving to the right || 2 moving up || 3 moving to the left || 4 moving down
int mainArray[18][18] =
{
    // 1   3   5   7   9   11  13  15  17
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} ,//0
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1} ,
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1} ,//2
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1} ,
    {1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1} ,//4
    {1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1} ,
    {1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1} ,//6
    {1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1} ,
    {1,0,1,0,1,0,1,0,1,1,0,1,1,1,1,1,1,1} ,//8
    {1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,1} ,
    {1,0,1,0,1,0,1,4,1,1,0,1,0,1,1,1,0,1} ,//10
    {1,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1} ,
    {1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1} ,//12
    {1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1} ,
    {1,0,1,0,0,0,0,0,0,0,0,1,0,1,3,1,0,1} ,//14
    {1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1} ,
    {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,2,1} ,//16
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} ,
};
int minNumberOfMoves = 108;

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

void copyArray(int currentRout[108][2])
{
    for (int x = 0; x < 108; x++)
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

bool RunTheGhost(int locOfGhost[2], int currentRout[108][2], int counterOfMoves, int lastHeading)
{
    const int thisStackCounterOfMoves = counterOfMoves;
    int newLocationOfGhost[2] = { 0, 0 };
    //reached packman
    if (mainArray[locOfGhost[0]][locOfGhost[1]] == 3 && thisStackCounterOfMoves < minNumberOfMoves)
    {
        minNumberOfMoves = thisStackCounterOfMoves;
        copyArray(currentRout);
        return true;
    }
    // going right
    if (mainArray[locOfGhost[0]][locOfGhost[1] + 1] != 1 && lastHeading != 3)
    {
        newLocationOfGhost[0] = locOfGhost[0];
        newLocationOfGhost[1] = locOfGhost[1] + 1;
        currentRout[thisStackCounterOfMoves][0] = newLocationOfGhost[0];
        currentRout[thisStackCounterOfMoves][1] = newLocationOfGhost[1];
        RunTheGhost(newLocationOfGhost, currentRout, thisStackCounterOfMoves + 1, 1);
    }
    //going up
    if (mainArray[locOfGhost[0] - 1][locOfGhost[1]] != 1 && lastHeading != 4)
    {
        newLocationOfGhost[0] = locOfGhost[0] - 1;
        newLocationOfGhost[1] = locOfGhost[1];
        currentRout[thisStackCounterOfMoves][0] = newLocationOfGhost[0];
        currentRout[thisStackCounterOfMoves][1] = newLocationOfGhost[1];
        RunTheGhost(newLocationOfGhost, currentRout, thisStackCounterOfMoves + 1, 2);
    }
    // going left
    if (mainArray[locOfGhost[0]][locOfGhost[1] - 1] != 1 && lastHeading != 1)
    {
        newLocationOfGhost[0] = locOfGhost[0];
        newLocationOfGhost[1] = locOfGhost[1] - 1;
        currentRout[thisStackCounterOfMoves][0] = newLocationOfGhost[0];
        currentRout[thisStackCounterOfMoves][1] = newLocationOfGhost[1];
        RunTheGhost(newLocationOfGhost, currentRout, thisStackCounterOfMoves + 1, 3);
    }
    // going down
    if (mainArray[locOfGhost[0] + 1][locOfGhost[1]] != 1 && lastHeading != 2)
    {
        newLocationOfGhost[0] = locOfGhost[0] + 1;
        newLocationOfGhost[1] = locOfGhost[1];
        currentRout[thisStackCounterOfMoves][0] = newLocationOfGhost[0];
        currentRout[thisStackCounterOfMoves][1] = newLocationOfGhost[1];
        RunTheGhost(newLocationOfGhost, currentRout, thisStackCounterOfMoves + 1, 4);
    }
    return true;
}

void printTheRoute()
{
    printf("%i, %i\n", locationOfGhost[0], locationOfGhost[1]);
    for (int i = 0; i < 108; i++)
    {
        if (rout[i][0] != 0 && rout[i][1] != 0)
        {
            printf("%i, %i\n", rout[i][0], rout[i][1]);
        }
        else
        {
            break;
        }
    }
    printf("%i, %i\n", locationOfPackman[0], locationOfPackman[1]);
}

int main(void)
{
    LocatePackman();
    LocateGhost();
    if (RunTheGhost(locationOfGhost,rout, 0, heading))
    {
        printf("Success in %i moves.\n", minNumberOfMoves);
        printTheRoute();
        return 0;
    }
    else
    {
        printf("Shit\n");
        return 1;
    }
}