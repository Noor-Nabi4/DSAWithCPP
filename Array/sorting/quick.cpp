#include <iostream>
using namespace std;
void swap(int *, int *);
void quickSort(int[], int, int);
int partition(int[], int, int);
int main()
{
    int n = 5;
    int arr[n] = {5, 2, 3, 4, 1};
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int pi = partition(arr, s, e);
        quickSort(arr, s, pi - 1);
        quickSort(arr, pi + 1, e);
    }
}
int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[e]);
    return i + 1;
}