#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *delete_at_first(node *head)
{
    node *ptr = head;
    head = head->next;

    free(ptr);

    return head;
}

node *delete_at_index(node *head, int index)
{
    node *p = head, *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

node *delete_at_value(node *head, int value)
{
    node *p = head, *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("\nError! Element not found!\n");
    }

    return head;
}

node *delete_at_end(node *head)
{
    node *p = head, *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

void getdata(node *head)
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    free(temp);
}

int main()
{
    node *head = (node *)malloc(sizeof(node));
    node *one = (node *)malloc(sizeof(node));
    node *two = (node *)malloc(sizeof(node));
    node *three = (node *)malloc(sizeof(node));
    node *four = (node *)malloc(sizeof(node));

    head->data = 0;
    head->next = one;

    one->data = 1;
    one->next = two;

    two->data = 2;
    two->next = three;

    three->data = 3;
    three->next = four;

    four->data = 4;
    four->next = NULL;

    // head = delete_at_first(head);
    // head = delete_at_index(head, 2);
    // head = delete_at_end(head);
    // head = delete_at_value(head, 1);

    getdata(head);

    free(head);
    free(one);
    free(two);
    free(three);
    free(four);

    return 0;
}