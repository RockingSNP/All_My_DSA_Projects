#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int x, choice, count;
int height = 1;

struct node *createNode()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data:\t");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    else
    {
        newnode->data = x;
        printf("\nEnter the Left Child of %d  ", newnode->data);
        newnode->left = createNode();
        printf("\nEnter the Right Child of %d  ", newnode->data);
        newnode->right = createNode();
        height += 1;
        return newnode;
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// void print_tree(struct node *root)
// {
//     if (root != NULL)
//     {
//         count = height * 2 - 1;
//         printf("%d ", root->data);
//         printf("");
//         preorder(root->left);
//         preorder(root->right);
//     }

//     printf("%d", root->data);
//     for (int i = 1; i <= count; i++)
//     {
//         for (j = count - i + 1; j > 1; j--)
//         {
//             printf(" ");
//         }

//         for (j = 1; j <= i; j++)
//         {
//             printf("* ");
//         }

//         printf("\n");
//     }
//     return 0;
// }

int main()
{
    struct node *root;
    printf("\nHave a new Bin Tree\n");
    root = createNode();
    while (1)
    {
        printf("\nChoose What Expression you desire:\n");
        printf("Press 1 for preorder\nPress 2 for postorder\nPress 3 for Inorder\n\nYour Choice->\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Your Preorder Expression is  :");
            preorder(root);
            break;

        case 2:
            printf("Your Postorder Expression is  :");
            postorder(root);
            break;

        case 3:
            printf("Your Inorder Expression is  :");
            inorder(root);
            break;

        default:
            printf("Invalid Input!!!");
            return 0;
        }
    }
}