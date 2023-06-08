#include <stdio.h>

#define FILENAME "stack.txt"

void push(int value) {
    FILE* file = fopen(FILENAME, "a");
    fprintf(file, "%d\n", value);
    fclose(file);
}

int pop() {
    int value;
    int last_value;
    FILE* file = fopen(FILENAME, "r");
    while (fscanf(file, "%d", &value) != EOF) {
        last_value = value;
    }
    fclose(file);
    if (remove(FILENAME) != 0) {
        perror("Error deleting file");
    }
    return last_value;
}

int main() {
    push(5);
    push(3);
    push(7);

    printf("%d\n", pop()); // Output: 7
    printf("%d\n", pop()); // Output: 3
    printf("%d\n", pop()); // Output: 5

    return 0;
}
