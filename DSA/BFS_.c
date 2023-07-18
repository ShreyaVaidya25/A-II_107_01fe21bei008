#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Queue implementation for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Graph representation using adjacency matrix
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int vertexCount = 0;

// Queue operations
void enqueue(Queue* q, int value) {
    q->items[q->rear] = value;
    q->rear++;
}

int dequeue(Queue* q) {
    int item = q->items[q->front];
    q->front++;
    return item;
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

// Add an edge to the graph
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
    if (start > vertexCount)
        vertexCount = start;
    if (end > vertexCount)
        vertexCount = end;
}

// Breadth-First Search traversal
void BFS(int startVertex, bool visited[]) {
    Queue q;

    q.front = 0;
    q.rear = 0;

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = true;
    enqueue(&q, startVertex);

    while (!isQueueEmpty(&q)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        // Visit all the adjacent vertices of the dequeued vertex
        for (int i = 0; i <= vertexCount; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int edges, startVertex;

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    bool visited[MAX_VERTICES] = { false };

    printf("Enter the edges (format: vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS traversal: ");
    for (int i = 0; i <= vertexCount; i++) {
        if (!visited[i]) {
            BFS(i, visited);
        }
    }

    return 0;
}

