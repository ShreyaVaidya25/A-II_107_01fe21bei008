#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph representation using adjacency matrix
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int vertexCount = 0;

// Depth-First Search traversal
void DFS(int startVertex) {
    visited[startVertex] = true;
    printf("%d ", startVertex);

    for (int i = 0; i <= vertexCount; i++) {
        if (adjMatrix[startVertex][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, startVertex;

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        adjMatrix[start][end] = 1;
        adjMatrix[end][start] = 1;
        if (start > vertexCount)
            vertexCount = start;
        if (end > vertexCount)
            vertexCount = end;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("DFS traversal: ");
    DFS(startVertex);

    return 0;
}
