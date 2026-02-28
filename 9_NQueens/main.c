#include <stdio.h>
#include <stdlib.h>

int n;
int count = 0;
int board[20];

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

void solve(int row)
{
    if (row==n)
    {
        count++;
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
    printf("Total solutions are %d", count);
    return 0;
    
}