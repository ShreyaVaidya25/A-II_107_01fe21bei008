#include <stdio.h>

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the knapsack problem using dynamic programming
void knapsack(int maxWeight, int weights[], int values[], int numItems) {
    // Create a table to store the computed values
    int table[numItems + 1][maxWeight + 1];

    // Initialize the table with 0 values
    for (int i = 0; i <= numItems; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else
                table[i][j] = -1;
        }
    }

    // Fill the table using dynamic programming
    for (int i = 1; i <= numItems; i++) {
        for (int j = 1; j <= maxWeight; j++) {
            if (weights[i - 1] > j)
                table[i][j] = table[i - 1][j];
            else
                table[i][j] = max(values[i - 1] + table[i - 1][j - weights[i - 1]], table[i - 1][j]);
        }
    }

    // Find the items included in the knapsack
    int selectedItems[numItems];
    int currentItem = numItems;
    int currentWeight = maxWeight;
    int itemCount = 0;

    while (currentItem > 0 && currentWeight > 0) {
        if (table[currentItem][currentWeight] != table[currentItem - 1][currentWeight]) {
            selectedItems[itemCount] = currentItem;
            itemCount++;
            currentWeight -= weights[currentItem - 1];
        }
        currentItem--;
    }

    // Print the maximum value and selected items
    printf("Maximum Value: %d\n", table[numItems][maxWeight]);
    printf("Selected Items: ");
    for (int i = itemCount - 1; i >= 0; i--) {
        printf("%d ", selectedItems[i]);
    }
    printf("\n");
}

int main() {
    int numItems, maxWeight;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    int weights[numItems], values[numItems];

    printf("Enter the weight and value for each item:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &weights[i]);
        printf("Value: ");
        scanf("%d", &values[i]);
    }

    printf("Enter the maximum weight the knapsack can hold: ");
    scanf("%d", &maxWeight);

    knapsack(maxWeight, weights, values, numItems);

    return 0;
}
