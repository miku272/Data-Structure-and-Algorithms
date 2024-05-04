#include <iostream>

using namespace std;

class QuickSort
{
private:
    int arr[10];

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(int low, int high)
    {
        int pivot = this->arr[low], i_low = low, j_high = high;

        while (i_low < j_high)
        {
            while (this->arr[i_low] <= pivot)
            {
                i_low++;
            }
            while (this->arr[j_high] > pivot)
            {
                j_high--;
            }

            if (i_low < j_high)
            {
                swap(this->arr[i_low], this->arr[j_high]);
            }
        }

        swap(this->arr[low], this->arr[j_high]);

        return j_high;
    }

public:
    QuickSort()
    {
        for (int i = 0; i < 10; i++)
        {
            this->arr[i] = 0;
        }
    }

    QuickSort(int arr[])
    {
        for (int i = 0; i < 10; i++)
        {
            this->arr[i] = arr[i];
        }
    }

    void print()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << "\n"
             << endl;
    }

    void quick_sort(int low, int high)
    {
        if (low < high)
        {
            int p = partition(low, high);
            quick_sort(low, p - 1);
            quick_sort(p + 1, high);
        }
    }
};

int main()
{
    int arr[] = {12, 53, 54, 65, 72, 10, 98, 52, 1, 55};
    QuickSort qs(arr);

    qs.print();
    qs.quick_sort(0, 10 - 1);
    qs.print();

    return 0;
}
