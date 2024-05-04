#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *a, int n)
{
    int key, j;

    for (int i = 1; i <= n - 1; i++) // Loop for passes
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

int main()
{
    int a[] = {12, 54, 65, 7, 23, 9}, n = 6;
    system("cls");

    printArray(a, n); //Printing array before insertion sorting
    insertionSort(a, n);
    printArray(a, n); // Printing array after insertion sorting

    // system("pause>null");
    return 0;
}
