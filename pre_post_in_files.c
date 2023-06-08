#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data)
 {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}


void inorderTraversal(struct Node* root, FILE* outputFile)
{
    if (root != NULL)
    {
        inorderTraversal(root->left, outputFile);
        printf("%d ", root->data);
        fprintf(outputFile, "%d ", root->data);
        inorderTraversal(root->right, outputFile);
    }
}

void preorderTraversal(struct Node* root, FILE* outputFile)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        fprintf(outputFile, "%d ", root->data);
        preorderTraversal(root->left, outputFile);
        preorderTraversal(root->right, outputFile);
    }
}


void postorderTraversal(struct Node* root, FILE* outputFile)
{
    if (root != NULL)
    {
        postorderTraversal(root->left, outputFile);
        postorderTraversal(root->right, outputFile);
        printf("%d ", root->data);
        fprintf(outputFile, "%d ", root->data);
    }
}


int main()
{
    struct Node* root = NULL;
    int data, i, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Failed to open the output file.\n");
        return 1;
    }

    printf("Inorder traversal: ");
    inorderTraversal(root, outputFile);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root, outputFile);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root, outputFile);
    printf("\n");



    fclose(outputFile);

    return 0;
}
