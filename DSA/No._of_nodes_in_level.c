#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void printTreeStructure(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    int i;
    space += 5;

    printTreeStructure(root->right, space);

    printf("\n");
    for (i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTreeStructure(root->left, space);
}

void countNodesAtEachLevel(struct Node* root, int level, int* count) {
    if (root == NULL) {
        return;
    }

    count[level]++;

    countNodesAtEachLevel(root->left, level + 1, count);
    countNodesAtEachLevel(root->right, level + 1, count);
}

int getTreeHeight(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    else {
        int leftHeight = getTreeHeight(root->left);
        int rightHeight = getTreeHeight(root->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }
        else {
            return rightHeight + 1;
        }
    }
}

int main() {
    struct Node* root = NULL;
    int numNodes, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the values of the nodes: ");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("Tree Structure:\n");
    printTreeStructure(root, 0);

    int treeHeight = getTreeHeight(root);
    int* count = (int*)calloc(treeHeight + 1, sizeof(int));

    countNodesAtEachLevel(root, 0, count);

    printf("\nLevel\tNumber of Nodes\n");
    for (int i = 0; i <= treeHeight; i++) {
        printf("%d\t%d\n", i, count[i]);
    }

    free(count);
    return 0;
}
