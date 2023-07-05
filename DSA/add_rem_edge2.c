#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;

// Function to add an edge between two vertices in the graph
void addEdge() {
    int vertex1, vertex2;
    printf("Enter the vertices to add an edge between (0 to %d): ", numVertices - 1);
    scanf("%d %d", &vertex1, &vertex2);

    if (vertex1 < 0 || vertex1 >= numVertices || vertex2 < 0 || vertex2 >= numVertices) {
        printf("Invalid vertex numbers.\n");
        return;
    }

    graph[vertex1][vertex2] = 1;
    graph[vertex2][vertex1] = 1;
    printf("Edge added between vertices %d and %d.\n", vertex1, vertex2);
}

// Function to remove an edge between two vertices in the graph
void removeEdge() {
    int vertex1, vertex2;
    printf("Enter the vertices to remove the edge between (0 to %d): ", numVertices - 1);
    scanf("%d %d", &vertex1, &vertex2);

    if (vertex1 < 0 || vertex1 >= numVertices || vertex2 < 0 || vertex2 >= numVertices) {
        printf("Invalid vertex numbers.\n");
        return;
    }

    if (graph[vertex1][vertex2] == 0 || graph[vertex2][vertex1] == 0) {
        printf("There is no edge between vertices %d and %d.\n", vertex1, vertex2);
        return;
    }

    graph[vertex1][vertex2] = 0;
    graph[vertex2][vertex1] = 0;
    printf("Edge removed between vertices %d and %d.\n", vertex1, vertex2);
}

int main() {
    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        printf("\nGraph Operations:\n");
        printf("1. Add Edge\n");
        printf("2. Remove Edge\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEdge();
                break;
            case 2:
                removeEdge();
                break;
            case 3:
                exitProgram = true;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
