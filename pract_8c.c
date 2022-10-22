#include <stdio.h>
#include <stdlib.h>
int parent[10];
// void prims(int, int);
int fipar(int);
int unionn(int, int);
void prims(int n, int cost[10][10])
{
    int visited[10], ne = 1, u, v, minCost = 0, min; // ne = Number of edges
    for (int p = 1; p <= n; p++)
    {
        visited[p] = 0;
    }
    printf("\nThe Edges consist for MST are : \n");
    visited[1] = 1;
    while (ne < n)
    {
        for (int i = 1, min = 999; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] == 0)
                    {
                        continue;
                    }
                    else
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                    if (visited[u] == 0 || visited[v] == 0)
                    {
                        printf("%d Edge (%d,%d) = %d \n", ne++, u, v, min);
                        minCost = minCost + min;
                        visited[v] = 1;
                    }
                    cost[u][v] = cost[v][u] = 999;
                }
            }
        }
    }
    printf("\nCost of Construrcting MST is %d ", minCost);
}
void Kruskals(int n, int cost[10][10])
{
    int visited[10], ne = 1, u, v, minCost = 0, min, a, b;
    printf("\nThe Edges consist for MST from Kruskal algo are : \n");
    while (ne < n)
    {
        for (int i = 1, min = 999; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                    u = fipar(u);
                    v = fipar(v);
                    if (unionn(u, v)) // if orignal parent different
                    {
                        printf("\n%d Edge ( %d , %d ) = %d \n", ne++, a, b, min);
                        minCost = minCost + min;
                    }
                    cost[a][b] = cost[b][a] = 999;
                }
            }
        }
    }
    printf("Minnimum cost = %d", minCost);
}
int fipar(int i)
{
    while (parent[i])
    {
        i = parent[i];
        return i;
    }
}
int unionn(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
int main()
{
    int n; // number of nodes
    int cost[10][10];
    printf("Number of Nodes : ");
    scanf("%d", &n);
    printf("Enter Cost of %d %d Matrix : \n", n, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] == 999;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cost[i][j] != 0)
            {
                parent[j] = i;
            }
        }
    }
    prims(n, cost);
    Kruskals(n, cost);
    return 0;
}
