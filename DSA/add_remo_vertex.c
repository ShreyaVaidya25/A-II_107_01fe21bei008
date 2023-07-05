#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;

// Function to add a vertex to the graph
void addVertex() {
    if (numVertices == MAX_VERTICES) {
        printf("Cannot add more vertices. Graph is full.\n");
        return;
    }

    numVertices++;
    printf("Vertex added. Total vertices: %d\n", numVertices);
}

// Function to remove a vertex from the graph
void removeVertex() {
    if (numVertices == 0) {
        printf("Cannot remove vertex. Graph is empty.\n");
        return;
    }

    int vertexToRemove;
    printf("Enter the vertex to remove (0 to %d): ", numVertices - 1);
    scanf("%d", &vertexToRemove);

    if (vertexToRemove < 0 || vertexToRemove >= numVertices) {
        printf("Invalid vertex number.\n");
        return;
    }

    // Shift rows and columns to delete the vertex
    for (int i = vertexToRemove; i < numVertices - 1; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = graph[i + 1][j];
        }
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = vertexToRemove; j < numVertices - 1; j++) {
            graph[i][j] = graph[i][j + 1];
        }
    }

    numVertices--;
    printf("Vertex removed. Total vertices: %d\n", numVertices);
}

int main() {
    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        printf("\nGraph Operations:\n");
        printf("1. Add Vertex\n");
        printf("2. Remove Vertex\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVertex();
                break;
            case 2:
                removeVertex();
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
