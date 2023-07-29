#include <iostream>
using namespace std;
void swap(int *, int *);
void bubbleSort(int[], int);
void selectionSort(int[], int);
void insertionSort(int[], int);
void print(int[], int);
int main()
{
    int n = 5;

    int arr[n] = {-2, 45, 0, 11, -9};

    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    insertionSort(arr, n);
    print(arr, n);
    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n)
{
    int i = 1;
    while (i < n)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[i], &arr[i + 1]);
            }
        }
        i++;
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}