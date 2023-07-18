#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int vertices[MAX_SIZE];
    int edges[MAX_SIZE][MAX_SIZE];
    int numVertices;
} Graph;

void initializeGraph(Graph *graph) {
    graph->numVertices = 0;
}

void addVertex(Graph *graph, int vertex) {
    if (graph->numVertices >= MAX_SIZE) {
        printf("Graph is full. Cannot add more vertices.\n");
        return;
    }

    graph->vertices[graph->numVertices] = vertex;
    graph->numVertices++;
}

void removeVertex(Graph *graph, int vertex) {
    int i, j, k;

    for (i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i] == vertex) {
            for (j = 0; j < graph->numVertices; j++) {
                graph->edges[i][j] = 0;
                graph->edges[j][i] = 0;
            }

            for (k = i; k < graph->numVertices - 1; k++) {
                graph->vertices[k] = graph->vertices[k + 1];
            }

            graph->numVertices--;
            printf("Vertex %d has been removed.\n", vertex);
            return;
        }
    }

    printf("Vertex %d not found in the graph.\n", vertex);
}

void addEdge(Graph *graph, int start, int end) {
    int i, j;

    for (i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i] == start) {
            for (j = 0; j < graph->numVertices; j++) {
                if (graph->vertices[j] == end) {
                    graph->edges[i][j] = 1;
                    printf("Edge added between %d and %d.\n", start, end);
                    return;
                }
            }

            printf("End vertex %d not found in the graph.\n", end);
            return;
        }
    }

    printf("Start vertex %d not found in the graph.\n", start);
}

void removeEdge(Graph *graph, int start, int end) {
    int i, j;

    for (i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i] == start) {
            for (j = 0; j < graph->numVertices; j++) {
                if (graph->vertices[j] == end) {
                    graph->edges[i][j] = 0;
                    printf("Edge removed between %d and %d.\n", start, end);
                    return;
                }
            }
            printf("End vertex %d not found in the graph.\n", end);
            return;
        }
    }
    printf("Start vertex %d not found in the graph.\n", start);
}

void printGraph(Graph *graph) {
    int i, j;

    printf("Vertices: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d ", graph->vertices[i]);
    }
    printf("\n");

    printf("Edges:\n");
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->edges[i][j]);
        }
        printf("\n");
    }
}
int containsValue(Graph *graph, int value) {
    int i, j;

    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            if (graph->edges[i][j] == value) {
                return 1; // Found value
            }
        }
    }
   return 0; // Value not found
}
int main() {
    Graph graph;
    initializeGraph(&graph);

    int option, vertex, start, end, value;

    do {
        printf("1.Add Vertex\n 2.Remove Vertex\n 3.Add Edge\n 4.Remove Edge\n 5.Print Graph\n 6.Search for a Value\n 0. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the vertex to add: ");
                scanf("%d", &vertex);
                addVertex(&graph, vertex);
                break;
            case 2:
                printf("Enter the vertex to remove: ");
                scanf("%d", &vertex);
                removeVertex(&graph, vertex);
                break;
            case 3:
                printf("Enter the start vertex of the edge: ");
                scanf("%d", &start);
                printf("Enter the end vertex of the edge: ");
                scanf("%d", &end);
                addEdge(&graph, start, end);
                break;
            case 4:
                printf("Enter the start vertex of the edge: ");
                scanf("%d", &start);
                printf("Enter the end vertex of the edge: ");
                scanf("%d", &end);
                removeEdge(&graph, start, end);
                break;
            case 5:
                printGraph(&graph);
                break;
            case 6:
                printf("Enter the value to search for: ");
                scanf("%d", &value);
                if (containsValue(&graph, value)) {
                    printf("Graph contains the value %d.\n", value);
                } else {
                    printf("Graph does not contain the value %d.\n", value);
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
      } while (option != 0);
    return 0;
}
