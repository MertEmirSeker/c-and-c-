#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printmap(char a[15][30]) // printing our map
{

    int i, j;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 30; j++)
        {

            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}
int dice() // generating random number 1 to 6
{
    int roll = 0;

    roll = rand() % 6 + 1;

    return roll;
}

int startGame() // checking which player start first
{
    int p1, p2;
    char i;
    char j;
    char arr[15][30];
    printf("PLAYER 1  Please ENTER to dice");
    scanf("%c", &i);
    p1 = dice();
    p2 = dice();
    printf("DICE : %d", p1);
    printf("\nPLAYER 2  Please ENTER to dice");
    scanf("%c", &j);
    printf("DICE : %d\n", p2);

    if (p1 == p2)
    {
        printf("Same dice values. Please try again.\n\n");
        startGame();
    }
    else if (p1 > p2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{

    srand(time(NULL));
    char arr[15][30];
    int i, j;
    int p1, p2;
    char a, b;
    int x1 = 1, y1 = 1, f1 = 0, f2 = 0, x2 = 3, y2 = 3;

    for (i = 0; i < 15; i++)
    {

        for (j = 0; j < 30; j++)
        {
            if (i == 0 || i == 14 || ((i == 2 || i == 12) && j >= 2 && j <= 27) || ((i == 4 || i == 10) && j >= 4 && j <= 25))
            {
                arr[i][j] = '.';
            }
            else if (((j == 0 || j == 29) && i != 0 && i != 14) || ((i >= 3 && i <= 11) && (j == 2 || j == 27)) || ((i >= 5 && i <= 9) && (j == 4 || j == 25)))
            {
                arr[i][j] = ':';
            }
            else if ((i == 2 && j == 1) || (i == 4 && j == 3)) // finish line
            {
                arr[i][j] = '-';
            }
            else if ((i == 1 && j == 14) || (i == 7 && j == 28) || (i == 13 && j == 14) || (i == 13 && j == 14) || (i == 3 && j == 10) || (i == 3 && j == 18) || (i == 5 && j == 26) || (i == 10 && j == 26) || (i == 11 && j == 10) || (i == 11 && j == 18)) // penalty points
            {
                arr[i][j] = 'X';
            }
            else if (i == 1 && j == 1) // first player
            {

                arr[i][j] = '1';
            }
            else if (i == 3 && j == 3) // second player
            {
                arr[i][j] = '2';
            }
            else
                arr[i][j] = ' ';
        }
    }
    printmap(arr);

    if (startGame() == 0) // if player 1 starts
    {
        printf("Player 1 will start to game.\n");
        printf("PLAYER 1  Please ENTER to dice");
        scanf("%c", &a);
        p1 = dice();
        printf("DICE : %d", p1);
        printf("\nPLAYER 2  Please ENTER to dice");
        scanf("%c", &b);
        p2 = dice();
        printf("DICE : %d\n", p2);
        while (1)
        {

            for (i = 0; i < 15; i++)
            {

                for (j = 0; j < 30; j++)
                {
                    if (i == 0 || i == 14 || ((i == 2 || i == 12) && j >= 2 && j <= 27) || ((i == 4 || i == 10) && j >= 4 && j <= 25))
                    {
                        arr[i][j] = '.';
                    }

                    else if (((j == 0 || j == 29) && i != 0 && i != 14) || ((i >= 3 && i <= 11) && (j == 2 || j == 27)) || ((i >= 5 && i <= 9) && (j == 4 || j == 25)))
                    {
                        arr[i][j] = ':';
                    }

                    else if ((i == 2 && j == 1) || (i == 4 && j == 3)) // finish line
                    {
                        arr[i][j] = '-';
                    }
                    else if ((i == 1 && j == 14) || (i == 7 && j == 28) || (i == 13 && j == 14) || (i == 13 && j == 14) || (i == 3 && j == 10) || (i == 3 && j == 18) || (i == 5 && j == 26) || (i == 10 && j == 26) || (i == 11 && j == 10) || (i == 11 && j == 18)) // penalty points
                    {
                        arr[i][j] = 'X';
                    }

                    else
                        arr[i][j] = ' ';
                }
            }
            if (x1 == 1) // if necessary dice changes the column
            {
                y1 = y1 + p1;
                if (y1 <= 28)
                {
                    arr[x1][y1] = '1';
                }
                else if (y1 > 28)
                {
                    x1 = y1 - 27;
                    y1 = 28;
                    arr[x1][y1] = '1';
                }
            }
            else if (x1 <= 13 && y1 == 28) // if necessary dice changes the row
            {
                x1 = x1 + p1;
                if (x1 <= 13)
                {
                    arr[x1][y1] = '1';
                }

                else if (x1 > 13)
                {
                    y1 = y1 - (x1 - 13);
                    x1 = 13;
                    arr[x1][y1] = '1';
                }
            }
            else if (y1 >= 1 && x1 == 13) // if necessary dice changes the column
            {

                y1 = y1 - p1;
                if (y1 >= 1)
                {
                    arr[x1][y1] = '1';
                    f1++;
                }
                else if (y1 < 1)
                {
                    x1 = x1 + y1 - 1;
                    y1 = 1;
                    arr[x1][y1] = '1';
                }
            }
            else if (x1 >= 1 && y1 == 1) // if necessary dice changes the row
            {

                x1 = x1 - p1;
                if (x1 >= 1)
                {
                    arr[x1][y1] = '1';
                }
                else if (x1 < 1)
                {
                    y1 = y1 - (x1 - 1);
                    x1 = 1;
                    arr[x1][y1] = '1';
                }
            }

            if (x1 == 1 && y1 == 14) // penalty points for player 1
            {
                printf("Penalty for Player 1\n");
                arr[x1][y1] = 'X';
                arr[x1][y1 - 2] = '1';
            }
            if (x1 == 7 && y1 == 28)
            {
                printf("Penalty for Player 1\n");
                arr[x1][y1] = 'X';
                arr[x1 - 2][y1] = '1';
            }
            if (x1 == 13 && y1 == 14)
            {
                printf("Penalty for Player 1\n");
                arr[x1][y1] = 'X';
                arr[x1][y1 + 2] = '1';
            }
            if (x2 == 3)
            { // PLAYER 2

                y2 = y2 + p2;
                if (y2 <= 26)
                {

                    arr[x2][y2] = '2';
                }
                else if (y2 > 26)
                {
                    x2 = y2 - 23;
                    y2 = 26;
                    arr[x2][y2] = '2';
                }
            }
            else if (x2 <= 11 && y2 == 26) // if necessary dice changes the row
            {

                x2 = x2 + p2;
                if (x2 <= 11)
                {
                    arr[x2][y2] = '2';
                }

                else if (x2 > 11)
                {
                    y2 = y2 - (x2 - 11);
                    x2 = 11;
                    arr[x2][y2] = '2';
                }
            }
            else if (y2 >= 3 && x2 == 11) // if necessary dice changes the column
            {

                y2 = y2 - p2;
                if (y2 >= 3)
                {
                    arr[x2][y2] = '2';
                    f2++;
                }
                else if (y2 < 3)
                {
                    x2 = x2 + y2 - 3;
                    y2 = 3;
                    arr[x2][y2] = '2';
                }
            }
            else if (x2 >= 3 && y2 == 3) // if necessary dice changes the row
            {

                x2 = x2 - p2;
                if (x2 >= 3)
                {
                    arr[x2][y2] = '2';
                }
                else if (x2 < 3)
                {
                    y2 = y2 - (x2 - 1);
                    x2 = 3;
                    arr[x2][y2] = '2';
                }
            }

            if (x2 == 3 && y2 == 10) // penalty points for player 2
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2][y2 - 2] = '2';
            }
            if (x2 == 3 && y2 == 18)
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2][y2 - 2] = '2';
            }
            if (x2 == 5 && y2 == 26)
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2 - 2][y2] = '2';
            }
            if (x2 == 10 && y2 == 26)
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2 - 2][y2] = '2';
            }
            if (x2 == 11 && y2 == 10)
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2][y2 + 2] = '2';
            }
            if (x2 == 11 && y2 == 18)
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2][y2 + 2] = '2';
            }
            printmap(arr);
            if (x1 <= 2 && y1 >= 1 && f1 != 0)
            {
                printf("Player 1 won!");
                return 0;
            }
            else if (x2 <= 4 && y2 >= 3 && f2 != 0)
            {
                printf("Player 2 won!");
                return 0;
            }
            printf("PLAYER 1  Please ENTER to dice");
            scanf("%c", &a);
            p1 = dice();
            printf("DICE : %d", p1);
            printf("\nPLAYER 2  Please ENTER to dice");
            scanf("%c", &b);
            p2 = dice();
            printf("DICE : %d\n", p2);
        }
    }
    else if (startGame() == 1) // if player 2 starts
    {
        printf("Player 2 will start to game.\n");
        printf("PLAYER 2  Please ENTER to dice");
        scanf("%c", &a);
        p2 = dice();
        printf("DICE : %d", p2);
        printf("\nPLAYER 1  Please ENTER to dice");
        scanf("%c", &b);
        p1 = dice();
        printf("DICE : %d\n", p1);
        while (1)
        {

            for (i = 0; i < 15; i++)
            {

                for (j = 0; j < 30; j++)
                {
                    if (i == 0 || i == 14 || ((i == 2 || i == 12) && j >= 2 && j <= 27) || ((i == 4 || i == 10) && j >= 4 && j <= 25))
                    {
                        arr[i][j] = '.';
                    }

                    else if (((j == 0 || j == 29) && i != 0 && i != 14) || ((i >= 3 && i <= 11) && (j == 2 || j == 27)) || ((i >= 5 && i <= 9) && (j == 4 || j == 25)))
                    {
                        arr[i][j] = ':';
                    }

                    else if ((i == 2 && j == 1) || (i == 4 && j == 3)) // finish line
                    {
                        arr[i][j] = '-';
                    }
                    else if ((i == 1 && j == 14) || (i == 7 && j == 28) || (i == 13 && j == 14) || (i == 13 && j == 14) || (i == 3 && j == 10) || (i == 3 && j == 18) || (i == 5 && j == 26) || (i == 10 && j == 26) || (i == 11 && j == 10) || (i == 11 && j == 18)) // penalty points
                    {
                        arr[i][j] = 'X';
                    }

                    else
                        arr[i][j] = ' ';
                }
            }
            if (x1 == 1) // if necessary dice changes the column
            {
                y1 = y1 + p1;
                if (y1 <= 28)
                {
                    arr[x1][y1] = '1';
                }
                else if (y1 > 28)
                {
                    x1 = y1 - 27;
                    y1 = 28;
                    arr[x1][y1] = '1';
                }
            }
            else if (x1 <= 13 && y1 == 28) // if necessary dice changes the row
            {
                x1 = x1 + p1;
                if (x1 <= 13)
                {
                    arr[x1][y1] = '1';
                }

                else if (x1 > 13)
                {
                    y1 = y1 - (x1 - 13);
                    x1 = 13;
                    arr[x1][y1] = '1';
                }
            }
            else if (y1 >= 1 && x1 == 13) // if necessary dice changes the column
            {

                y1 = y1 - p1;
                if (y1 >= 1)
                {
                    arr[x1][y1] = '1';
                    f1++;
                }
                else if (y1 < 1)
                {
                    x1 = x1 + y1 - 1;
                    y1 = 1;
                    arr[x1][y1] = '1';
                }
            }
            else if (x1 >= 1 && y1 == 1) // if necessary dice changes the row
            {

                x1 = x1 - p1;
                if (x1 >= 1)
                {
                    arr[x1][y1] = '1';
                }
                else if (x1 < 1)
                {
                    y1 = y1 - (x1 - 1);
                    x1 = 1;
                    arr[x1][y1] = '1';
                }
            }

            if (x1 == 1 && y1 == 14) // penalty points for player 1
            {
                printf("Penalty for Player 1\n");
                arr[x1][y1] = 'X';
                arr[x1][y1 - 2] = '1';
            }
            if (x1 == 7 && y1 == 28)
            {
                printf("Penalty for Player 1\n");
                arr[x1][y1] = 'X';
                arr[x1 - 2][y1] = '1';
            }
            if (x1 == 13 && y1 == 14)
            {
                printf("Penalty for Player 1\n");
                arr[x1][y1] = 'X';
                arr[x1][y1 + 2] = '1';
            }
            if (x2 == 3)
            { // PLAYER 2

                y2 = y2 + p2;
                if (y2 <= 26)
                {

                    arr[x2][y2] = '2';
                }
                else if (y2 > 26)
                {
                    x2 = y2 - 23;
                    y2 = 26;
                    arr[x2][y2] = '2';
                }
            }
            else if (x2 <= 11 && y2 == 26) // if necessary dice changes the row
            {

                x2 = x2 + p2;
                if (x2 <= 11)
                {
                    arr[x2][y2] = '2';
                }

                else if (x2 > 11)
                {
                    y2 = y2 - (x2 - 11);
                    x2 = 11;
                    arr[x2][y2] = '2';
                }
            }
            else if (y2 >= 3 && x2 == 11) // if necessary dice changes the column
            {

                y2 = y2 - p2;
                if (y2 >= 3)
                {
                    arr[x2][y2] = '2';
                    f2++;
                }
                else if (y2 < 3)
                {
                    x2 = x2 + y2 - 3;
                    y2 = 3;
                    arr[x2][y2] = '2';
                }
            }
            else if (x2 >= 3 && y2 == 3) // if necessary dice changes the row
            {

                x2 = x2 - p2;
                if (x2 >= 3)
                {
                    arr[x2][y2] = '2';
                }
                else if (x2 < 3)
                {
                    y2 = y2 - (x2 - 1);
                    x2 = 3;
                    arr[x2][y2] = '2';
                }
            }

            if (x2 == 3 && y2 == 10) // penalty points for player 2
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2][y2 - 2] = '2';
            }
            if (x2 == 3 && y2 == 18)
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2][y2 - 2] = '2';
            }
            if (x2 == 5 && y2 == 26)
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2 - 2][y2] = '2';
            }
            if (x2 == 10 && y2 == 26)
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2 - 2][y2] = '2';
            }
            if (x2 == 11 && y2 == 10)
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2][y2 + 2] = '2';
            }
            if (x2 == 11 && y2 == 18)
            {
                printf("Penalty for Player 2\n");
                arr[x2][y2] = 'X';
                arr[x2][y2 + 2] = '2';
            }
            printmap(arr);
            if (x1 <= 2 && y1 >= 1 && f1 != 0)
            {
                printf("Player 1 won!");
                return 0;
            }
            else if (x2 <= 4 && y2 >= 3 && f2 != 0)
            {
                printf("Player 2 won!");
                return 0;
            }
            printf("PLAYER 2  Please ENTER to dice");
            scanf("%c", &a);
            p2 = dice();
            printf("DICE : %d", p2);
            printf("\nPLAYER 1  Please ENTER to dice");
            scanf("%c", &b);
            p1 = dice();
            printf("DICE : %d\n", p1);
        }
    }

    return 0;
}