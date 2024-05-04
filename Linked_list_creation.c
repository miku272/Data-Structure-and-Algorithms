#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node * insert_at_beginning(int n, node *head){
    node *tmp = (node*) malloc(sizeof(node));
    
    tmp->data = n;
    tmp->next = head;

    return tmp;
}

node * insert_at_between( int n, node *head, int index){
    node *tmp = (node*) malloc(sizeof(node));
    node *p = head;
    int i =0;

    while(i != index - 1){
        p = p->next;
        i++;
    }
    
    tmp->data = n;
    tmp->next = p->next;
    p->next = tmp;

    return head;
}

node * insert_at_end( int n, node *head){
    node *tmp = (node*) malloc(sizeof(node));
    node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    tmp->data = n;
    p->next = tmp;
    tmp->next = NULL;

    return head;
}

void getdata(node *head){
    node *temp = (node*) malloc(sizeof(node));
    temp = head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
    free(temp);
}

int main(){
    node *head = (node*) malloc(sizeof(node));
    head = NULL;

    head = insert_at_beginning(1, head);
    // head = insert_at_between(2, head, 1);
    // head = insert_at_between(4, head, 2);
    // head = insert_at_between(3, head, 2);
    head = insert_at_end(2, head);
    head = insert_at_end(3, head);

    getdata(head);

    free(head);

    return 0;
}