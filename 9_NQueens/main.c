#include <stdio.h>
#include <stdlib.h>

int n;
int count = 0;
int board[20];
int printed = 0;   // NEW: to print only first solution

int safe(int row, int col)
{
    for(int i=0; i<row; i++)
    {
        if (board[i]==col)
            return 0;
        if (abs(board[i]-col)==abs(i-row))
            return 0;
    }
    return 1;
}

void printBoard()
{
    for(int r=0; r<n; r++)
    {
        for(int c=0; c<n; c++)
        {
            if(board[r] == c)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}


void solve(int row)
{
    if (row==n)
    {
        count++;

        // Print only first solution
        if (printed == 0)
        {
            printBoard();
            printed = 1;
        }

        return;
    }

    for(int col=0; col<n; col++)
    {
        if (safe(row, col))
        {
            board[row]=col;
            solve(row+1);
        }
    }
}

int main()
{
    printf("Enter the number of rows\n");
    scanf("%d", &n);

    solve(0);

    printf("Total solutions are %d\n", count);

    return 0;
}