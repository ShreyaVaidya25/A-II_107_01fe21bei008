#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node* hashTable[], int key) {
    int index = key % SIZE;

    Node* newNode = createNode(key);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* temp = hashTable[index];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(Node* hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* hashTable[SIZE] = {NULL};

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert(hashTable, data);
    }

    printf("\nHash Table:\n");
    display(hashTable);

    return 0;
}
