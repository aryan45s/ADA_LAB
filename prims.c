#include<stdio.h>

#define INF 9999

void prim(int cost[10][10], int n)
{
    int visited[10]={0};

    int edges=0;
    int mincost=0;

    visited[0]=1;

    while(edges < n-1)
    {
        int min=INF;
        int u=-1,v=-1;

        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<n;j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }

        printf("%d -> %d : %d\n",u,v,min);

        mincost += min;

        visited[v]=1;

        edges++;
    }

    printf("Minimum Cost = %d\n",mincost);
}

int main()
{
    int n;
    int cost[10][10];

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0)
                cost[i][j]=INF;
        }
    }

    prim(cost,n);

    return 0;
}