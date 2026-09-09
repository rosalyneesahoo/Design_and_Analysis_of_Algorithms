//Prims algorithm (MST)


#include <stdio.h>
#include <stdlib.h>

void prims(int a[10][10], int n)
{
    int i, j, min, mincost = 0, ne = 1, u, v, x, y, visited[10];

    for(i = 1; i <= n; i++)
        visited[i] = 0;

    visited[1] = 1;

    printf("\n The edges considered are \n");

    while(ne < n)
    {
        for(i = 1, min = 999; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(visited[i] != 0)
                {
                    if(a[i][j] < min)
                    {
                        min = a[i][j];
                        x = u = i;
                        y = v = j;
                    }
                }
            }
        }

        if(visited[u] == 0 || visited[v] == 0)
        {
            printf("\n Edge %d, (%d,%d) cost = %d",
                   ne++, x, y, min);

            mincost = mincost + min;
            visited[y] = 1;
        }

        a[x][y] = a[y][x] = 999;
    }

    printf("\n Cost of spanning tree = %d", mincost);
}

int main()
{
    int n, i, j, a[10][10];

    printf("\n Read no. of vertices: ");
    scanf("%d", &n);

    printf("\n Read cost matrix : \n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);

            if(a[i][j] == 0)
                a[i][j] = 999;
        }
    }

    prims(a, n);

    return 0;
}


