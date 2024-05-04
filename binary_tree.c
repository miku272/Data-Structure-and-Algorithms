#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data); // For preorder

        preorder(root->left);

        // printf("%d ", root->data); // For inorder

        preorder(root->right);

        // printf("%d ", root->data); // for postorder
    }
}

int main()
{
    system("cls");

    struct Node *root = create_node(4);
    struct Node *p1 = create_node(1);
    struct Node *p2 = create_node(6);
    struct Node *p3 = create_node(5);
    struct Node *p4 = create_node(2);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    preorder(root);

    return 0;
}