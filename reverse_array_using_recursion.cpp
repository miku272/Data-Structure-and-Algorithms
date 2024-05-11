#include <iostream>

void swap(int *arr, int *indexA, int *indexB)
{
    int temp = arr[*indexA];
    arr[*indexA] = arr[*indexB];
    arr[*indexB] = temp;
}

void reverseArray(int *arr, int *len, int *currPosition)
{
    if (*len % 2 == 0)
    {
        if (*currPosition == *len / 2)
        {
            return;
        }
        else
        {
            int swapIndex = *len - *currPosition - 1;
            swap(arr, currPosition, &swapIndex);
            *currPosition += 1;
            reverseArray(arr, len, currPosition);
        }
    }
    else
    {
        if (*currPosition - 1 == *len / 2)
        {
            return;
        }
        else
        {
            int swapIndex = *len - *currPosition - 1;
            swap(arr, currPosition, &swapIndex);
            *currPosition += 1;
            reverseArray(arr, len, currPosition);
        }
    }
}

void printArray(int *arr, int *len)
{
    for (int i = 0; i < *len; i++)
    {
        std::cout << arr[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    int len = 10;
    int *arr = new int[len];
    int currPosition = 0;

    for (int i = 0; i < len; i++)
    {
        arr[i] = i;
    }

    printArray(arr, &len);

    reverseArray(arr, &len, &currPosition);

    std::cout << "\n";
    printArray(arr, &len);

    return 0;
}
