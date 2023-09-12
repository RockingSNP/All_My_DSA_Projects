#include <stdio.h>
#include<stdlib.h>

int *stack, top = -1, choice,N;

void push(int *top, int stack[]);
void pop(int *top, int stack[]);
void display(int *top, int stack[]);

int main()
{
    printf("What Size of Stack to You Want? : \t");
    scanf("%d",&N);
    stack = (int*)malloc(N*sizeof(int));
 while (1) {
    printf("\nWhat operation do you want to perform?\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Reset The Queue \n5.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            push(&top, stack);
            
            break;
        case 2:
            pop(&top, stack);
            break;
        case 3:
            display(&top, stack);
            break;
        case 4:
                free(stack);
                top = -1;
                stack = NULL;
                printf("Queue reset.\n");
                break;
        case 5:
            free(stack); // Deallocate memory before exiting
            printf("Exiting.\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
    }
    }
}

// Push Function.
void push(int *top, int stack[])
{
    if (*top == N - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        int x;
        printf("Enter an element:\t");
        scanf("%d", &x);
        stack[++*top] = x;
    }
}

// Pop function
void pop(int *top, int stack[])
{
    if (*top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("The popped item is %d\n", stack[--*top]);
    }
}

// display
void display(int *top, int stack[])
{
    printf("The Recorded Stack is: {");
    for (int i = 0; i <= *top; i++)
    {
        printf("%d  ", stack[i]);
    }
    printf("}\n\n");
}
