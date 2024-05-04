#include<stdio.h>
#include<stdlib.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void selectionSort(int *a, int n)
{
    int indexOfMin, temp;

    for (int i = 0; i <= n - 1; i++)
    {
        indexOfMin = i;

        for (int j = i + 1; j <= n - 1; j++)
        {
            indexOfMin = a[j] < a[indexOfMin] ? j : indexOfMin;
        }
        
        temp = a[i];
        a[i] = a[indexOfMin];
        a[indexOfMin] = temp;
    }
    
}

int main(int argc, char const *argv[])
{
    int a[] = {12, 54, 65, 7, 23, 9}, n = 6;
    system("cls");

    printArray(a, n); // Before sorting the array
    selectionSort(a, n);
    printArray(a, n); // After sorting the array with selection sort

    return 0;
}
