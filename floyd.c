#include <stdio.h>

#define INF 9999

void floyd(int graph[10][10], int n)
{
    int i,j,k;

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] =
                    graph[i][k] + graph[k][j];
                }
            }
        }
    }

    printf("\nShortest Path Matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%4d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int graph[10][10];

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    floyd(graph,n);

    return 0;
}