#include<stdio.h>

#define INF 9999

int minDistance(int dist[], int visited[], int n)
{
    int min = INF;
    int minIndex = -1;

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[10][10], int n, int src)
{
    int dist[10];
    int visited[10];

    for(int i=0;i<n;i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int count=0; count<n-1; count++)
    {
        int u = minDistance(dist, visited, n);

        visited[u] = 1;

        for(int v=0; v<n; v++)
        {
            if(!visited[v] &&
               graph[u][v] &&
               dist[u] != INF &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] =
                dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", src);

    for(int i=0;i<n;i++)
    {
        printf("%d -> %d = %d\n",
               src,i,dist[i]);
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

    int src;

    printf("Enter source vertex: ");
    scanf("%d",&src);

    dijkstra(graph,n,src);

    return 0;
}