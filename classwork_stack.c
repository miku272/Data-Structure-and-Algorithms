#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1, arr[5];

int push(int input)
{
    if (top >= 4)
    {
        printf("\n\nStack is overflown. Can't add any more items");
    }
    else
    {
        arr[top + 1] = input;
        top++;
    }

    return input;
}

int pop()
{
    if (top < 0)
    {
        printf("\n\nStack is empty. Can't pop anything from an empty stack!");
        return -99;
    }
    else
    {
        top--;
        return arr[top + 1];
    }
}

int peep(int index)
{
    if (top < 0)
    {
        printf("\n\nStack is underflow. Can't peep on the desired location!");
        return -99;
    }
    else
    {
        if (index > 5)
        {
            printf("\n\nEnter a valid position!");
            return -99;
        }
        else
        {
            return arr[top - index + 1];
        }
    }
}

int change(int data, int index)
{
    int temp = arr[top - index + 1];
    arr[top - index + 1] = data;
}

void showAllStack()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    char inp;
    do
    {
        int choice, data, index;
        system("cls");

        printf("1. Push\n2. Pop\n3. peep\n4. Change\n5. Show All Data\n6. Exit\n\n\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\nEnter the value you want to push: ");
            scanf("%d", &data);

            push(data);

            break;

        case 2:
            pop();

            break;

        case 3:
            printf("\n\nEnter the position you want to look at: ");
            scanf("%d", &index);

            printf("\n\nThe data at postion %d is %d", index, peep(index));

            break;

        case 4:
            printf("\n\nEnter the position whose element you want to change: ");
            scanf("%d", &index);
            printf("\n\nEnter the data: ");
            scanf("%d", &data);

            change(data, index);

            break;

        case 5:
            printf("\n\nShowing all the elements:\n");
            showAllStack();

            break;

        case 6:
            exit(0);

        default:
            printf("\n\nError! Please Choose a correct option!");
        }

        getchar();

        printf("\n\nDo you want to continue? (Y/y) ");
        scanf("%c", &inp);

    } while (inp == 'Y' || inp == 'y');

    system("pause>nul");
    return 0;
}
