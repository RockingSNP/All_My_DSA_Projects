#include <stdio.h>
#include <stdlib.h>

int choice, size, n;

int len(int arr[], size_t size) {
    // Calculate the length by dividing the size of the whole array by the size of one element
    return (int)size;
}

//Insertion
void insertion(int arr[], int *size)
{   arr = (int *)realloc(arr, (++*size) * (sizeof(int)));
    printf("\nNow the Size of Array: %d\n\n",len(arr, sizeof(arr) / sizeof(arr[0])));
    int index, elt;
insertion:
    printf("Enter The Index Where U  want to Insert:\t");
    scanf("%d", &index);
    if (index > *size || index < 0)
    {
        printf("Invalid Input try Again");
        goto insertion;
    }

    printf("Enter the element U want to enter:\t");
    scanf("%d", &elt);
    for (int i = *size - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = elt;

    printf("Element %d has Been Inserted at %d Index", elt, index);
}

//Deletion
void deletion(int arr[], int *size)
{

    arr = (int *)realloc(arr, (--*size) * (sizeof(int)));
    printf("\nNow the Size of Array: %d\n\n",len(arr, sizeof(arr) / sizeof(arr[0])));
    int index1;
deletion:
    printf("Index U want to Delete\t");
    scanf("%d", &index1);
    if (index1 > *size || index1 < 0)
    {
        printf("Invalid Input try Again");
        goto deletion;
    }
    for (int i = 0; i <= *size; i++)
    {
        arr[i] = arr[i + 1];
    }
}

//Display
void display(int arr[], int *size)
{
    printf("\nNow the Size of Array: %d\n\n",len(arr, sizeof(arr) / sizeof(arr[0])));
    printf("The Outcome Array:\t{");
    for (int i = 0; i < *size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

void main()
{
    printf("Enter the Size of your Desired Array:-->\t");
    scanf("%d", &size);

    // Allocate The Size of Array on Runtime
    int *arr;
    arr = (int *)malloc(size * sizeof(int));

    printf("Enter The Numbers For your Array:\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);//Scanning For the First Elements
    }

selection:

    printf("Which Operation You Want to Perform? \n");
    printf("Press 1 for Insert An Element at any position u want.\n");
    printf("Press 2 for Delete any element.\n");
    printf("Press 3 for Display the Array.\n");
    printf("Press 4 for a Fresh Empty Array.\n\n");

    printf("Your Choice-->\t");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        insertion(arr, &size);
        goto selection;
        break;
    case 2:
        deletion(arr, &size);
        goto selection;
        break;
    case 3:
        display(arr, &size);
        goto selection;
        break;
    case 4: free(arr); goto selection; break;    

    default:
        printf("Invalid Input. Try Again  ..lol\n");
        printf("Start Where You Left off\n\n");
        goto selection;
        break;
    }
    free(arr);
}