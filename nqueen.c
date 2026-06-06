#include<stdio.h>

int board[20][20];

int isSafe(int row,int col,int n)
{
    int i,j;

    // Check column
    for(i=0;i<row;i++)
    {
        if(board[i][col])
            return 0;
    }

    // Left diagonal
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return 0;
    }

    // Right diagonal
    for(i=row,j=col;i>=0 && j<n;i--,j++)
    {
        if(board[i][j])
            return 0;
    }

    return 1;
}

int solve(int row,int n)
{
    if(row==n)
        return 1;

    for(int col=0;col<n;col++)
    {
        if(isSafe(row,col,n))
        {
            board[row][col]=1;

            if(solve(row+1,n))
                return 1;

            board[row][col]=0; // backtrack
        }
    }

    return 0;
}

int main()
{
    int n;

    printf("Enter N: ");
    scanf("%d",&n);

    if(solve(0,n))
    {
        printf("\nSolution:\n");

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution exists\n");
    }

    return 0;
}