#include <stdio.h>
#include <stdlib.h>
void dijkstras(int n, int cost[10][10], int source, int dist[10])
{
    int count = 1, min, visited[10], v;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        dist[i] = cost[source][i];
    }
    visited[source] = 1;
    dist[source] = 0;
    while (count <= n)
    {
        min = 999;
        for (int i = 0; i <= n; i++)
        {
            if ((dist[i] < min) && (visited[i] == 0)) // means if its not zero and also not visitednode then
            {
                min = dist[i];
                v = i;
            }
            visited[v] = 1;
        }
        count++;
        for (int i = 0; i <= n; i++)
        {
            if ((dist[i]) > (dist[v] + cost[v][i]))
            {
                dist[i] = dist[v] + cost[v][i];
            }
        }
    }
}
int main()
{
    int cost[10][10], dist[10], n, source;
    printf("\nEnter no of nodes/vertices : ");
    scanf("%d", &n);
    printf("\nRead The matrix : ");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    printf("\nRead Source vertex : \n");
    scanf("%d", &source);
    dijkstras(n, cost, source, dist);
    printf("\nShortest Path from %d is \n", source);
    for (int i = 1; i <= n; i++)
    {
        if (source != i)
        {
            printf("\n%d -> %d = %d ", source, i, dist[i]);
        }
    }
    return 0;
}