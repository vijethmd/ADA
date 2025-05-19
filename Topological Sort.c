#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int inDegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void topologicalSort(int n) {
    for (int i = 0; i < n; i++)
        inDegree[i] = 0;

    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            if (graph[u][v])
                inDegree[v]++;

    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            enqueue(i);

    int count = 0;
    printf("Topological Order:\n");

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for (int v = 0; v < n; v++) {
            if (graph[u][v]) {
                inDegree[v]--;
                if (inDegree[v] == 0)
                    enqueue(v);
            }
        }
    }

    if (count != n)
        printf("\nGraph contains a cycle. Topological sort not possible.\n");
    else
        printf("\n");
}

int main() {
    int n, e, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort(n);

    return 0;
}
