#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to read array from a file
int readArrayFromFile(int arr[], const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }

    int size = 0;
    while (!feof(file) && size < MAX_SIZE) {
        fscanf(file, "%d", &arr[size]);
        size++;
    }

    fclose(file);
    return size;
}

int main() {
    int arr[MAX_SIZE];
    int size;
    const char* inputFile = "input.txt";

    // Read the array from the input file
    size = readArrayFromFile(arr, inputFile);
    if (size == 0)
        return 1;

    // Perform Quick Sort
    quickSort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Quick sort completed successfully.\n");

    return 0;
}
