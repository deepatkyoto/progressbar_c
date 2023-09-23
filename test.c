#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void backspace(int);
int countStringLength(char *);
void addPostCharacter(int, char *);

int main(int argc, char *argv[])
{
    bool doHalf = false;
    if (strcmp(argv[2], "true"))
    {
        doHalf = true;
    }
    int progress = atoi(argv[1]);
    int totalProgress = 100;
    if (doHalf)
    {
        progress = abs(progress / 2);
        totalProgress = 50;
    }
    char character[] = ">";
    char postCharacter[] = "-";
    char spaceChar[2] = " ";
    char concatenated[totalProgress + 1];
    concatenated[0] = '\0';
    printf("\e[?25l");
    for (int x = 0; x < progress; x++)
    {
        if (x == 0)
        {
            strcat(concatenated, character);
            printf("%s", concatenated);
        }
        else
        {
            backspace(x);
            for (int z = 1; z <= x; z++)
            {
                strcat(concatenated, spaceChar);
            }
            strcat(concatenated, character);
            fflush(stdout);
            usleep(100000);
            printf("%s", concatenated);
        }
        int remainingSpace = totalProgress - countStringLength(concatenated);
        if (remainingSpace > 0)
            addPostCharacter(remainingSpace, postCharacter);
        backspace(remainingSpace);
        strcpy(concatenated, "");
    }
    printf("\n");
    printf("\e[?25h");
    return 0;
}
int countStringLength(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}
void addPostCharacter(int x, char *postChar)
{
    for (int i = 0; i < x; i++)
    {
        putchar(*postChar);
    }
    return;
}
void backspace(int x)
{
    for (int y = 0; y <= x; y++)
    {
        putchar('\b');
    }
}