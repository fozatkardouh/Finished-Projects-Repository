#include <stdio.h>
#include <cs50.h>

int ** findthebox(size_t columns, size_t rows);
void print(int ** input);
void freeArray(int ** arrayToBeFreed);

int main(void)
{
    int ** temp = findthebox(3,3);
    print(temp);
    freeArray(temp);
    print(temp);
}

int ** findthebox(size_t columns, size_t rows)
{
    int ** array = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        array[i] = malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = i+j;
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
    printf("\n");
}

void freeArray(int ** arrayToBeFreed)
{
    for (int i = 0; i < 3; ++i)
    {
        free(arrayToBeFreed[i]);
    }
    free(arrayToBeFreed);
}