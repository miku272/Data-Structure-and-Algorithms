#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low], i = low + 1, j = high, temp = 0;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quick_sort(int a[], int low, int high)
{
    int partition_index;

    if (low < high)
    {
        partition_index = partition(a, low, high);
        quick_sort(a, low, partition_index - 1);  // Sort left subarray
        quick_sort(a, partition_index + 1, high); // Sort right subarray
    }
}

void print_array(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {3, 5, 2, 13, 12}; // size = 5

    print_array(a, 5);
    quick_sort(a, 0, 4); // size - 1 = 4
    print_array(a, 5);

    return 0;
}
