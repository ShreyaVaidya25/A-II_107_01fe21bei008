#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize)
        {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        } else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize)
        {
        arr[k] = right[j];
        j++;
        k++;
        }
}

void mergeSort(int arr[], int size)
{
    if (size <= 1)
        return;

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);

    merge(arr, left, mid, right, size - mid);
}

int main()
{
    FILE *outputFile;
    int arr[100], n, i;


    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, n);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Failed to open the output file.\n");
        return 1;
    }

    fprintf(outputFile, "%d\n", n);
    for (i = 0; i < n; i++)
    {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fclose(outputFile);

    printf("Sorting completed. The sorted data is written to the output file.\n");

    return 0;
}
