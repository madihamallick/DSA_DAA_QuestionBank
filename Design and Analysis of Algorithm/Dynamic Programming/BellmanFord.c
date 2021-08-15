#include <stdio.h>
#define INFINITY 99999

int n;

void setAdj(int arr[][50])
{
    int i, j, scanned;
    for (i = 0; i < n; i++)
    {
        printf("Enter elements of row %d: (99 for infinity): ", i + 1);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &scanned);
            arr[i][j] = scanned == 99 ? INFINITY : scanned;
        }
    }
}

void printAdj(int arr[][50])
{
    int i, j, scanned;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

void initDistList(int d[], int pred[])
{
    int i, s;
    printf("\nEnter source vertex: ");
    scanf("%d", &s);
    for (i = 0; i < n; i++)
    {
        d[i] = INFINITY;
    }
    d[s - 1] = 0;
    pred[s - 1] = 0;
}

void relaxVertex(int c[][50], int d[], int pred[], int u, int v)
{
    if ((d[u] != INFINITY) && ((d[u] + c[u][v]) < d[v]))
    {
        d[v] = d[u] + c[u][v];
        pred[v] = u + 1;
    }
}

void bellmanFordAlgo(int cost[][50], int d[], int pred[])
{
    int i, j, k;
    for (k = 0; k < n - 1; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((i != j) && (cost[i][j] != INFINITY))
                {
                    relaxVertex(cost, d, pred, i, j);
                }
            }
        }
    }
}

void printList(int arr[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ---> %d \n", i + 1, arr[i]);
    }
}

int main()
{
    int cost[50][50], s;
    printf("Enter the number of vertex in the graph: ");
    scanf("%d", &n);
    int d[n], pred[n];
    setAdj(cost);
    initDistList(d, pred);
    bellmanFordAlgo(cost, d, pred);
    printf("\nDistance list: \n");
    printList(d);
    printf("\nPredecessor list: \n");
    printList(pred);
    return 0;
}

