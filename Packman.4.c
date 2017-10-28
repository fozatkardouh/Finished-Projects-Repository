#include <stdio.h>
#include <cs50.h>

int locationOfPackman[2];
int locationOfGhost[2];
int route[50][2] =
{
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },
    { 0, 0 },    { 0, 0 },    { 0, 0 },     { 0, 0 },    { 0, 0 },
};
int mainArray[18][18] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} ,
    {1,3,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1} , //Packman here at 1.1
    {1,0,1,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1} ,
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
int heading = 0; //stationary|| 1 moving to the right || 2 moving up || 3 moving to the left || 4 moving down
int minNumberOfMoves = 50;

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

bool runTheGhost(int locOfGhost[2], int currentRoute[50][2], int counterOfMoves, int lastHeading)
{
    //looping like an idiot
    if (counterOfMoves >= 50)
    {
        return false;
    }
    int newLocationOfGhost[2] = { 0, 0 };
    //reached packman
    if (mainArray[locOfGhost[0]][locOfGhost[1]] == 3)
    {
        //new shortest path found
        if (counterOfMoves < minNumberOfMoves)
        {
            minNumberOfMoves = counterOfMoves;
            currentRoute[counterOfMoves][0] = locOfGhost[0];
            currentRoute[counterOfMoves][1] = locOfGhost[1];
            for (int x = 0; x < minNumberOfMoves + 10; x++)
            {
                route[x][0] = currentRoute[x][0];
                route[x][1] = currentRoute[x][1];
            }
            return true;
        }
        //not the shortest path yet
        else
        {
            return false;
        }
    }
    else
    {
        // going right
        if (mainArray[locOfGhost[0]][locOfGhost[1] + 1] != 1 && lastHeading != 3)
        {
            newLocationOfGhost[0] = locOfGhost[0];
            newLocationOfGhost[1] = locOfGhost[1] + 1;
            currentRoute[counterOfMoves][0] = newLocationOfGhost[0];
            currentRoute[counterOfMoves][1] = newLocationOfGhost[1];
            runTheGhost(newLocationOfGhost, currentRoute, counterOfMoves + 1, 1);
        }
        //going up
        if (mainArray[locOfGhost[0] - 1][locOfGhost[1]] != 1 && lastHeading != 4)
        {
            newLocationOfGhost[0] = locOfGhost[0] - 1;
            newLocationOfGhost[1] = locOfGhost[1];
            currentRoute[counterOfMoves][0] = newLocationOfGhost[0];
            currentRoute[counterOfMoves][1] = newLocationOfGhost[1];
            runTheGhost(newLocationOfGhost, currentRoute, counterOfMoves + 1, 2);
        }
        // going left
        if (mainArray[locOfGhost[0]][locOfGhost[1] - 1] != 1 && lastHeading != 1)
        {
            newLocationOfGhost[0] = locOfGhost[0];
            newLocationOfGhost[1] = locOfGhost[1] - 1;
            currentRoute[counterOfMoves][0] = newLocationOfGhost[0];
            currentRoute[counterOfMoves][1] = newLocationOfGhost[1];
            runTheGhost(newLocationOfGhost, currentRoute, counterOfMoves + 1, 3);
        }
        // going down
        if (mainArray[locOfGhost[0] + 1][locOfGhost[1]] != 1 && lastHeading != 2)
        {
            newLocationOfGhost[0] = locOfGhost[0] + 1;
            newLocationOfGhost[1] = locOfGhost[1];
            currentRoute[counterOfMoves][0] = newLocationOfGhost[0];
            currentRoute[counterOfMoves][1] = newLocationOfGhost[1];
            runTheGhost(newLocationOfGhost, currentRoute, counterOfMoves + 1, 4);
        }
        // no path found at all
        if (minNumberOfMoves == 50)
        {
            return false;
        }
        // because C is dump as shit
        else
        {
            return true;
        }
    }
}

void printTheRoute()
{
    printf("%i, %i\n", locationOfGhost[0], locationOfGhost[1]);
    for (int i = 0; i < minNumberOfMoves; i++)
    {
        printf("%i, %i\n", route[i][0], route[i][1]);
    }
}

int main(void)
{
    LocatePackman();
    LocateGhost();
    int tempPath[50][2];
    if (runTheGhost(locationOfGhost, tempPath, 0, heading))
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