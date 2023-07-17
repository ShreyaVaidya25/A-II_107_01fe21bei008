#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        // Empty tree, create a new node and return it
        return createNode(value);
    }

    // If the value is less than the root's data, go to the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If the value is greater than the root's data, go to the right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the modified root pointer
    return root;
}

// Function to find the minimum value node in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Traverse down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a value from the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    // If the value is less than the root's data, go to the left subtree
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    // If the value is greater than the root's data, go to the right subtree
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    // If the value is equal to the root's data, delete the node
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* minValue = minValueNode(root->right);
        root->data = minValue->data;
        root->right = deleteNode(root->right, minValue->data);
    }

    return root;
}

// Function to perform left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Function to perform right rotation
struct Node* rightRotate(struct Node* x) {
    struct Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Function to balance the BST using rotation operations
struct Node* balanceBST(struct Node* root) {
    if (root == NULL) {
        return root;
    }

    int balanceFactor = getBalanceFactor(root);

    // Left-Left case (perform right rotation)
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    // Right-Right case (perform left rotation)
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    // Left-Right case (perform left and right rotation)
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Left case (perform right and left rotation)
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to calculate the height of a BST node
int calculateHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    }

    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to calculate the balance factor of a BST node
int getBalanceFactor(struct Node* node) {
    if (node == NULL) {
        return 0;
    }

    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    return leftHeight - rightHeight;
}

// Function to perform in-order traversal of the BST (ascending order)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value, n;

    printf("Enter the number of elements in the initial tree: ");
    scanf("%d", &n);

    printf("Enter the elements of the initial tree: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Balance the tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                root = balanceBST(root);
                printf("Tree balanced successfully.\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("BST: ");
        inorderTraversal(root);
        printf("\n");
    }

    return 0;
}


