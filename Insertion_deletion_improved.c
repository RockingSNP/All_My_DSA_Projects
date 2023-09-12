#include <stdio.h>
#include <stdlib.h>

// Function to calculate the length of an integer array
int len(int arr[], int size) {
    return size;
}

// Function to insert an element at a specified index in the array
void insertion(int arr[], int *size) {
    int index, elt;
    printf("Enter the index where you want to insert: ");
    scanf("%d", &index);

    if (index < 0 || index > *size) {
        printf("Invalid index. Insertion failed.\n");
        return;
    }

    printf("Enter the element you want to insert: ");
    scanf("%d", &elt);

    (*size)++;
    arr = (int *)realloc(arr, *size * sizeof(int));

    for (int i = *size - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = elt;

    printf("Element %d has been inserted at index %d.\n", elt, index);
}

// Function to delete an element at a specified index in the array
void deletion(int arr[], int *size) {
    int index;
    printf("Enter the index you want to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= *size) {
        printf("Invalid index. Deletion failed.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    arr = (int *)realloc(arr, *size * sizeof(int));

    printf("Element at index %d has been deleted.\n", index);
}

// Function to display the current state of the array
void display(int arr[], int size) {
    printf("The current size of the array: %d\n", size);
    printf("The array: { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice;

    printf("Enter the initial size of your desired array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size. Exiting.\n");
        return 1;
    }

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    printf("Enter the numbers for your array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nWhich operation do you want to perform?\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the array\n");
        printf("4. Reset the array\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertion(arr, &size);
                break;
            case 2:
                deletion(arr, &size);
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                free(arr);
                size = 0;
                arr = NULL;
                printf("Array reset.\n");
                break;
            case 5:
                free(arr);
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}