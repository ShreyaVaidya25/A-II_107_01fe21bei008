#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;
bool visited[MAX_VERTICES];

bool DFS(int source, int destination) {
    if (source == destination) {
        return true;  // Found a path
    }

    visited[source] = true;

    for (int i = 0; i < numVertices; i++) {
        if (graph[source][i] && !visited[i]) {
            if (DFS(i, destination)) {
                return true;  // Found a path
            }
        }
    }

    return false;  // Path does not exist
}

int main() {
    int source, destination;

    // Input the graph values
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input source and destination vertices
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    // Initialize visited array
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Perform DFS traversal
    if (DFS(source, destination)) {
        printf("A path exists from vertex %d to vertex %d.\n", source, destination);
    } else {
        printf("No path exists from vertex %d to vertex %d.\n", source, destination);
    }

    return 0;
}
