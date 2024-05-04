#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int index;
    int *arr;
} stack;

void push(stack *s, int data)
{
    if (s->index == s->size - 1)
    {
        printf("\nError! Your stack is Full!\n");
    }
    else
    {
        s->index++;
        s->arr[s->index] = data;
    }
}

void pop(stack *s)
{
    if (s->index < 0)
    {
        printf("\nError! There is no element in the stack to delete!\n");
    }
    else
    {
        s->index--;
    }
}

void getdata(stack *s)
{
    for (int i = 0; i <= s->index; i++)
    {
        printf("%d\n", s->arr[i]);
    }
}

int main()
{
    stack *s = (stack *)malloc(sizeof(stack));

    s->size = 100;
    s->index = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 0);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printf("Before popping:\n");
    getdata(s);

    pop(s);
    pop(s);

    printf("After popping:\n");
    getdata(s);

    free(s->arr);
    free(s);
    return 0;
}
