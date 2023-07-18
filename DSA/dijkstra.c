#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure to represent a graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
     return graph;
}

// Add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; ++v)
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void printSolution(int dist[], int V) {
    printf("Vertex\t\tDistance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d\t\t%d\n", i, dist[i]);
}

void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V];     // Array to store the shortest distance from src to i
    bool sptSet[V];  // Set to track vertices included in shortest path tree
    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
     // Find shortest path for all vertices
    for (int count = 0; count < V - 1; ++count) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, V);
        // Mark the picked vertex
        sptSet[u] = true;
        // Update dist value of the adjacent vertices of the picked vertex
        struct AdjListNode* adjNode = graph->array[u].head;
        while (adjNode != NULL) {
            int v = adjNode->dest;
            int weight = adjNode->weight;
      if (sptSet[v] == false && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
                adjNode = adjNode->next;
        }
    }
    printSolution(dist, V);
}

int main() {
    int V, E;
    int src;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    struct Graph* graph = createGraph(V);
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        printf("Enter edge %d (source destination weight): ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(graph, src);
    return 0;
}
