/*******************************************
* This program calculates the shortest path from the ghost to Pacman.
* It returns the step by step path.
*
* Written for R*c by Fozat Kardouh 29.10.2017
* Reviewed by L 03.11.2017
********************************************/

#include <stdio.h>
#include <cs50.h>

#define SIZE 18
#define MAX_NUMBER_OF_MOVES 50
#define WALL 1
#define GHOST 2
#define PACKMAN 3

#define STATIONARY 0
#define RIGHT 1
#define UP 2
#define LEFT 3
#define DOWN 4

void locateGhost();
bool findThePackman(int ghost[2], int currentRoute[MAX_NUMBER_OF_MOVES][2], int moves, int lastDirection);
bool isGhostMakingTooMany(int moves);
bool isPackmanFound(int ghost[2]);
bool isShortestPathFound(int ghost[2], int currentRoute[MAX_NUMBER_OF_MOVES][2], int moves);
void updateShortestPath(int ghost[2], int currentRoute[MAX_NUMBER_OF_MOVES][2], int moves);
void move(int ghost[2], int direction, int lastDirection, int currentRoute[MAX_NUMBER_OF_MOVES][2], int moves);
int comingFrom(int direction);
bool isValidDirection(int ghost[2], int direction, int lastDirection);
bool isPathFound();
void printTheRoute();

int map[SIZE][SIZE] =   {
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
                            {1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,1,0,1} ,
                            {1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1} ,
                            {1,0,1,1,1,1,1,0,1,1,1,1,0,1,0,1,0,1} ,
                            {1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1} ,
                            {1,0,1,0,1,0,1,1,1,1,1,0,1,1,0,0,0,1} ,
                            {1,0,1,0,1,0,1,0,0,0,1,0,1,1,1,1,0,1} ,
                            {1,0,0,0,1,0,0,0,1,0,0,0,1,2,0,0,0,1} , //ghost here at 16.13
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} ,
                        };

int locationOfGhost[2] = {0, 0};
int route[50][2];

int minNumberOfMoves = MAX_NUMBER_OF_MOVES;

int main(void)
{
    int tempPath[MAX_NUMBER_OF_MOVES][2];

    locateGhost();
    bool packmanFound = findThePackman(locationOfGhost, tempPath, STATIONARY, STATIONARY);
    if (!packmanFound)
    {
        printf("Shit\n");
        return 1;
    }

    printf("Success in %i moves.\n", minNumberOfMoves);
    printTheRoute();
    return 0;
}

void locateGhost()
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int column = 0; column < SIZE; column++)
        {
            if (map[row][column] == GHOST)
            {
                locationOfGhost[0] = row;
                locationOfGhost[1] = column;
                return;
            }
        }
    }
}

bool findThePackman(int ghost[2], int currentRoute[MAX_NUMBER_OF_MOVES][2], int moves, int lastDirection)
{
    if(isGhostMakingTooMany(moves))
    {
        return false;
    }

    if(isPackmanFound(ghost))
    {
        return isShortestPathFound(ghost, currentRoute, moves);
    }

    move(ghost, UP, lastDirection, currentRoute, moves);
    move(ghost, DOWN, lastDirection, currentRoute, moves);
    move(ghost, RIGHT, lastDirection, currentRoute, moves);
    move(ghost, LEFT, lastDirection, currentRoute, moves);

    return isPathFound();
}

bool isGhostMakingTooMany(int moves)
{
    return moves >= MAX_NUMBER_OF_MOVES;
}

bool isPackmanFound(int ghost[2])
{
    return map[ghost[0]][ghost[1]] == PACKMAN;
}

bool isShortestPathFound(int ghost[2], int currentRoute[MAX_NUMBER_OF_MOVES][2], int moves)
{
    if (moves < minNumberOfMoves)
    {
        updateShortestPath(ghost, currentRoute, moves);
        return true;
    }
    return false;
}

void updateShortestPath(int ghost[2], int currentRoute[MAX_NUMBER_OF_MOVES][2], int moves)
{
    minNumberOfMoves = moves;
    currentRoute[moves][0] = ghost[0];
    currentRoute[moves][1] = ghost[1];
    for (int x = 0; x < minNumberOfMoves; x++)
    {
        route[x][0] = currentRoute[x][0];
        route[x][1] = currentRoute[x][1];
    }
}

void move(int ghost[2], int direction, int lastDirection, int currentRoute[MAX_NUMBER_OF_MOVES][2], int moves)
{
    int nextStep[2] = {ghost[0], ghost[1]};
    switch (direction)
    {
        case RIGHT:
            nextStep[1] += 1;
        break;

        case LEFT:
            nextStep[1] -= 1;
        break;

        case UP:
            nextStep[0] -= 1;
        break;

        case DOWN:
            nextStep[0] += 1;
        break;

        default:
        break;
    }

    if(!isValidDirection(nextStep, direction, lastDirection))
    {
        return;
    }

    currentRoute[moves][0] = nextStep[0];
    currentRoute[moves][1] = nextStep[1];
    int newDirection = comingFrom(direction);
    findThePackman(nextStep, currentRoute, moves + 1, newDirection);
}

int comingFrom(int direction)
{
    switch (direction)
    {
        case RIGHT:
            return LEFT;
        case LEFT:
            return RIGHT;
        case UP:
            return DOWN;
        case DOWN:
            return UP;
    }
    return 0;
}

bool isValidDirection(int nextStep[2], int direction, int lastDirection)
{
    return map[nextStep[0]][nextStep[1]] != WALL && direction != lastDirection;
}

bool isPathFound()
{
    return minNumberOfMoves < MAX_NUMBER_OF_MOVES;
}

void printTheRoute()
{
    printf("%i, %i\n", locationOfGhost[0], locationOfGhost[1]);
    for (int moveNumber = 0; moveNumber < minNumberOfMoves; moveNumber++)
    {
        printf("%i, %i\n", route[moveNumber][0], route[moveNumber][1]);
    }
}