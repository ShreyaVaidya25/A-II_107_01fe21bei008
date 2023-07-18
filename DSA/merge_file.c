#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to merge two sorted arrays
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int size) {
    if (size <= 1)
        return;

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Divide the array into two halves
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    // Recursively sort the two halves
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted halves
    merge(arr, left, mid, right, size - mid);
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

    // Perform merge sort
    mergeSort(arr, size);

    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Merge sort completed successfully.\n");

    return 0;
}
