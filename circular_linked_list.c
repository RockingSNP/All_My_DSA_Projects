#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct node
{
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = newnode; // Point to itself for a new node
    return newnode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct node **head, int data)
{
    struct node *newnode = createnode(data);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *tail = (*head)->next; // Find the tail node
        while (tail->next != *head)
        {
            tail = tail->next;
        }
        newnode->next = *head; // New node points to the current head
        *head = newnode;       // Update the head
        tail->next = *head;    // Update the tail to maintain circularity
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct node **head, int data)
{
    struct node *newnode = createnode(data);
    if (*head == NULL)
    {
        *head = newnode;
        newnode->next = *head; // Circular link to itself
    }
    else
    {
        struct node *tail = (*head)->next; // Find the tail node
        while (tail->next != *head)
        {
            tail = tail->next;
        }
        tail->next = newnode;  // Update the current tail node to point to the new node
        newnode->next = *head; // New node points to the head to maintain circularity
    }
}

// Function to insert a node at a specified position in the circular linked list
void insertAtPosition(struct node **head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        insertAtBeginning(head, data);
    }
    else
    {
        struct node *newnode = createnode(data);
        struct node *current = *head;
        int currentPosition = 1;

        while (currentPosition < position - 1 && current->next != *head)
        {
            current = current->next;
            currentPosition++;
        }

        newnode->next = current->next;
        current->next = newnode;
    }
}

// Function to delete a node from the beginning of the circular linked list
void deleteFromBeginning(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to delete\n");
        return;
    }

    if ((*head)->next == *head)
    {
        // Only one node in the list
        free(*head);
        *head = NULL;
    }
    else
    {
        struct node *tail = (*head)->next; // Find the tail node
        while (tail->next != *head)
        {
            tail = tail->next;
        }
        struct node *temp = *head;
        *head = (*head)->next;
        tail->next = *head; // Update the tail to maintain circularity
        free(temp);
    }
}
// Delete From End
void deleteFromEnd(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to delete\n");
        return;
    }

    if ((*head)->next == *head)
    {
        // Only one node in the list
        free(*head);
        *head = NULL;
    }
    else
    {
        struct node *current = *head;
        struct node *previous = NULL;

        while (current->next != *head)
        {
            previous = current;
            current = current->next;
        }

        previous->next = *head; // Update the last node to point to the head
        free(current);
    }
}

// Function to delete a node from a specified position in the circular linked list
void deleteFromPosition(struct node **head, int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (*head == NULL)
    {
        printf("List is empty, nothing to delete\n");
        return;
    }

    if (position == 1)
    {
        deleteFromBeginning(head);
    }
    else
    {
        struct node *current = *head;
        int currentPosition = 1;

        while (currentPosition < position - 1 && current->next != *head)
        {
            current = current->next;
            currentPosition++;
        }

        struct node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

// Function to display the circular linked list
void display(struct node *head)
{
    struct node *current = head;
    if (current != NULL)
    {
        do
        {
            printf("%d -> ", current->data);
            current = current->next;
        } while (current != head);
        printf("... (Circular)\n");
    }
    else
    {
        printf("List is empty\n");
    }
}

// Function to free the memory allocated for the circular linked list
void freeList(struct node *head)
{
    if (head != NULL)
    {
        struct node *current = head;
        struct node *next;
        do
        {
            next = current->next;
            free(current);
            current = next;
        } while (current != head);
    }
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;

    while (1)
    {
        int choice, x, pos;
        printf("\nChoose What Expression you desire:\n");
        printf("Press 1 for Inserting at Beginning\nPress 2 for Inserting at End\nPress 3 for Inserting at any position\nPress 4 for Deleting from Beginning\nPress 5 for Deleting from End\nPress 6 for Deleting from any Position\nPress 7 for Getting a Fresh linkedlist\nYour Choice->\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Data U want to insert at the Beginning:\n");
            scanf("%d", &x);
            insertAtBeginning(&head, x);
            printf("After Inserting %d at Beginning ...\t", x);
            display(head);
            break;
        case 2:
            printf("Enter the Data U want to insert at the End:\n");
            scanf("%d", &x);
            insertAtEnd(&head, x);
            printf("After Inserting %d at End ...\t", x);
            display(head);
            break;
        case 3:
            printf("Enter the Data U want to insert \n:");
            scanf("%d", &x);
            printf("Enter the Position where U want to insert:\n");
            scanf("%d", &pos);
            insertAtPosition(&head, x, pos);
            printf("After Inserting %d at position %d ...\t", x, pos);
            display(head);
            break;
        case 4:
            deleteFromBeginning(&head);
            printf("After deleting from the Beginning\n");
            display(head);
            break;
        case 5:
            deleteFromEnd(&head);
            printf("After deleting from the End\n");
            display(head);
            break;
        case 6:
            printf("Enter the Position which U want to delete:\n");
            scanf("%d", &pos);
            deleteFromPosition(&head, pos);
            printf("After deleting Postion %d\t", pos);
            display(head);
            break;
        case 7:
            printf("Fresh List Has been Prepared...\n");
            freeList(head);
            display(head);
            break;

        default:
            printf("Invalid Input!!!\n");
            return 0;
        }
    }
    return 0;
}
