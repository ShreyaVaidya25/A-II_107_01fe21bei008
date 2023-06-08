#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
         {
            if (arr[j] > arr[j + 1])
                {
                  temp = arr[j];
                  arr[j] = arr[j + 1];
                  arr[j + 1] = temp;
                }
        }
    }
}

int main() {
    FILE *outputFile;
    int arr[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);


    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

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
