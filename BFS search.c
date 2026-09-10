//BFS search


#include <stdio.h>
#include <stdlib.h>

void bfs(int a[10][10], int n, int visited[10], int source)
{
    int queue[10], front = 0, rear = -1, i, del_node;

    visited[source] = 1;
    queue[++rear] = source;

    while(front <= rear)
    {
        del_node = queue[front++];

        for(i = 0; i < n; i++)
        {
            if(a[del_node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int n, a[10][10], i, j, visited[10], count = 0;

    printf("\nRead no. of nodes : ");
    scanf("%d", &n);

    printf("\nRead adjacency matrix \n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            bfs(a, n, visited, i);
            count++;
        }
    }

    if(count == 1)
        printf("\nGraph is Connected");
    else
        printf("\nGraph is not connected and %d components", count);

    return 0;
}

