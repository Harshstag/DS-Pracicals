#include <stdio.h>
#include <stdlib.h>
#define no_vertices 7
int visited[no_vertices];
int visited2[no_vertices];
int adj[no_vertices][no_vertices], arr[40];
static int k = 0, count = 0;
void BFS(int);
void DFS(int);
void BFS(int vertes) // node
{
    printf("%d\t", vertes);
    visited[vertes] = 1;
    for (int j = 0; j < no_vertices; j++)
    {
        if (!visited[j] && adj[vertes][j] == 1)
        {
            BFS(j);
        }
    }
}
void DFS(int vertes)
{
    int c = 0;
    count++;
    printf("%d\t", vertes);
    visited2[vertes] = 1;
    for (int j = 0; j < no_vertices; j++)
    {
        if ((!visited2[j]) && (adj[vertes][j] == 1))
        {
            arr[++k] = j;
            c = 1;
        }
        if (count == no_vertices)
        {
            exit(0);
        }
    }
    if (c == 1)
    {
        DFS(arr[k]);
    }
    else
    {
        k--;
        DFS(arr[k]);
    }
}
void printGraphMatrix(int adj[][no_vertices])
{
    for (int i = 0; i < no_vertices; i++)
    {
        for (int j = 0; j < no_vertices; j++)
        {
            printf("%d\t", adj[i][j]);
        }
        printf("\n \n");
    }
}
int main()
{
    int s, d; // source to destination
    for (int i = 0; i < no_vertices; i++)
    {
        for (int j = 0; j < no_vertices; j++)
        {
            adj[i][j] = 0; // initalizing the matix with 0
        }
    }
    while ((s != -1) && (d != -1)) // making the connection here and declaring the connection as 1
    {
        printf("Enter and Edge from node (0 to %d) to node (0 to %d) : ", no_vertices, no_vertices);
        scanf("%d%d", &s, &d);
        adj[s][d] = 1;
        adj[d][s] = 1;
    }
    printf("\n");
    printGraphMatrix(adj);
    printf("\nBFS : ");
    BFS(0); // we are taking 0 as a root to graph for BSF travelser
    printf("\nDFS : ");
    DFS(0);
    return 0;
}