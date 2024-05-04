#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximum(int a[], int n)
{
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    return max;
}

void count_sort(int *a, int n)
{
    int max = maximum(a, n), i, j;
    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }

    i = 0; // Counter for count array
    j = 0; // Counter for given array

    while(i <= max)
    {
        if(count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }

    free(count);
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {9, 1, 4, 14, 4, 15, 6}, n = 7;

    print_array(a, n);
    count_sort(a, n);
    print_array(a, n);

    return 0;
}
