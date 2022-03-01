#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int k = 0, end = 1;
void draw()
{
    printf("\n\n\n\t\t\t\t---|---|---\n"); // drawing the shape of the number :
    printf("\t\t\t\t %c | %c | %c\n", a[0], a[1], a[2]);
    printf("\t\t\t\t---|---|---\n");
    printf("\t\t\t\t %c | %c | %c\n", a[3], a[4], a[5]);
    printf("\t\t\t\t---|---|---\n");
    printf("\t\t\t\t %c | %c | %c\n", a[6], a[7], a[8]);
    printf("\t\t\t\t---|---|---\n");
}

void getInput()
{
    char ch;
    int i;
    printf("\nEnter the position : ");
    scanf("%c", &ch);

    for (int n = 1; n < 9; n++)
    {
        /* code here */

        if (k == 0) //k=0 to switch beteween the players
        {
            for (i = 0; i <= 8; i++)
            {
                if (a[i] == ch)
                {
                    a[i] = 'x';
                    k = 1;
                    n++;
                    break;
                }
            }
        }
        else
        {
            for (i = 0; i <= 8; i++)
            {
                if (a[i] == ch)
                {
                    a[i] = 'o';
                    k = 0;
                    n++;
                    break;
                }
                printf("%d", n);
            }
        }
        if (n == 9)
        {
            break;
            printf("the match is a draw !!");
        }
    }

    // if(chance == 9){
    //     printf("The Game is Draw");
    // }
}
int gameOver() //conditional statements to solve the game5
{
    if (a[0] == 'x' && a[1] == 'x' && a[2] == 'x' || a[3] == 'x' && a[4] == 'x' && a[5] == 'x' || a[6] == 'x' && a[7] == 'x' && a[8] == 'x')
        return 1;
    else if (a[0] == 'o' && a[1] == 'o' && a[2] == 'o' || a[3] == 'o' && a[4] == 'o' && a[5] == 'o' || a[6] == 'o' && a[7] == 'o' && a[8] == 'o')
        return 2;
    else if (a[0] == 'x' && a[3] == 'x' && a[6] == 'x' || a[1] == 'x' && a[4] == 'x' && a[7] == 'x' || a[2] == 'x' && a[5] == 'x' && a[8] == 'x')
        return 1;
    else if (a[0] == 'o' && a[3] == 'o' && a[6] == 'o' || a[1] == 'o' && a[4] == 'o' && a[7] == 'o' || a[2] == 'o' && a[5] == 'o' && a[8] == 'o')
        return 2;
    else if (a[0] == 'x' && a[4] == 'x' && a[8] == 'x' || a[2] == 'x' && a[4] == 'x' && a[6] == 'x')
        return 1;
    else if (a[0] == 'o' && a[4] == 'o' && a[8] == 'o' || a[2] == 'o' && a[4] == 'o' && a[6] == 'o')
        return 2;
    else
    {
    }
}
void final()
{
    int var;
    var = gameOver();
    if (var == 1)
    {
        printf("\nPlayer 1 won.");
        end = 0;
    }
    else if (var == 2)
    {
        printf("\nPlayer 2 won.");
        end = 0;
    }
    else
        ;
}

int main()
{
    char c;
repeat:
    system("cls");
    draw();
    while (end)
    {
        getInput();
        system("cls"); //calling the function
        draw();
        final();
    }

    printf("\n Do you wanna play again?\n");
    printf("yes/no?(y/n):");
    fflush(stdin); //to get out of the scanning
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
    {
        a[0] = '1';
        a[1] = '2';
        a[2] = '3';
        a[3] = '4';
        a[4] = '5';
        a[5] = '6';
        a[6] = '7';
        a[7] = '8';
        a[8] = '9';
        k = 0;
        end = 1;
        goto repeat; // goes to the Repeat label
    }
    else
    {
        system("cls"); //vs code doesn't support clrscr() ;
        printf("Thank u for playing");
    }

    getch();
}