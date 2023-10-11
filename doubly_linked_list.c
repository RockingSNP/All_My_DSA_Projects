#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail;

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode != NULL) {
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    }
    return newnode;
}
void insertAtBeginning(struct node** head,struct node** tail, int data) {
    struct node* newnode = createnode(data);
    if (*head == NULL) {
        *head = newnode;
        *tail = newnode;
    } else {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
}
void insertAtEnd(struct node** head,struct node** tail, int data){
    struct node* newnode = createnode(data);
    if(*head==NULL){
        *head = newnode;
        *tail = newnode;
    }else{
        newnode->prev = *tail;
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

// Function to insert a node at a specified position
void insertAtPosition(struct node** head,struct node** tail, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head,tail, data);
    } else {
        struct node* newnode = createnode(data);
        struct node* current = (*head);
        int currentPosition = 1;

        while (current != NULL && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL) {
            printf("Position exceeds the length of the head\n");
        }else{
            newnode->next = current->next;
            if (current->next == NULL) {
                insertAtEnd(head,tail,data);}
            else{
                current->next->prev = newnode;
            }
            current->next = newnode;
            newnode->prev = current;
        }
    }
}

void deleteFromBeginning(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    } else {
        struct node* current = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
    }
}


void deleteFromEnd(struct node** head,struct node** tail){
    
    if(*head==NULL){
        printf("Nothing To Delete Empty Linked head!!!\n");
        return;
    }else{
        struct node* currrent = *tail;
        currrent->next = NULL;
        free(*tail);
        (*tail) = currrent;
    }
}

void deleteFromPosition(struct node** head, struct node** tail, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    if (*head == NULL) {
        printf("head is empty, nothing to delete\n");
    } else {
        if (position == 1) {
            deleteFromBeginning(head);
        } else {
            struct node* current = *head;
            int currentPosition = 1;

            while (current != NULL && currentPosition < position) {
                current = current->next;
                currentPosition++;
            }

            if (current == NULL) {
                printf("Position exceeds the length of the head\n");
            } else {
                current->prev->next = current->next;
                if (current->next == NULL) {
                    deleteFromEnd(head,tail);
                }
                else{
                    current->next->prev = current->prev;
                }
                free(current);
            }
        }
    }
}

// Function to display the doubly linked head
void display(struct node* head) {
    struct node* current = head;
    printf("LIST -> ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void freeList(struct node* head,struct node* tail) {
    struct node* current = head;
    while (current != NULL) {
        struct node* current = current;
        current = current->next;
        free(current);
    }
    head = NULL;
    tail = NULL;
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;

    while (1)
    {   int choice,x,pos;
        printf("\nChoose What Expression you desire:\n");
        printf("Press 1 for Inserting at Beginning\nPress 2 for Inserting at End\nPress 3 for Inserting at any position\nPress 4 for Deleting from Beginning\nPress 5 for Deleting from End\nPress 6 for Deleting from any Position\nPress 7 for Getting a Fresh linkedlist\nYour Choice->\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Data U want to insert at the Beginning:\n");
            scanf("%d",&x);
            insertAtBeginning(&head,&tail, x);
            printf("After Inserting %d at Beginning ...\t",x);
            display(head);
            break;
        case 2:
            printf("Enter the Data U want to insert at the End:\n");
            scanf("%d",&x);
            insertAtEnd(&head,&tail, x);
            printf("After Inserting %d at End ...\t",x);
            display(head);
            break;
        case 3:
            printf("Enter the Data U want to insert \n:");
            scanf("%d",&x);
            printf("Enter the Position where U want to insert:\n");
            scanf("%d",&pos);
            insertAtPosition(&head,&tail, x,pos);
            printf("After Inserting %d at position %d ...\t",x,pos);
            display(head);
            break;
        case 4:
            deleteFromBeginning(&head);
            printf("After deleting from the Beginning\n");
            display(head);
            break;
        case 5:
            deleteFromEnd(&head,&tail);
            printf("After deleting from the End\n");
            display(head);
            break;
        case 6:
            printf("Enter the Position which U want to delete:\n");
            scanf("%d",&pos);
            deleteFromPosition(&head,&tail,pos);
            printf("After deleting Postion %d\t",pos);
            display(head);
            break;
        case 7:
            printf("Fresh List Has been Prepared...\n");
            freeList(head,tail);
            display(head);
            break;

        default:
            printf("Invalid Input!!!\n");
            return 0;
        }
    }
    return 0;
}
