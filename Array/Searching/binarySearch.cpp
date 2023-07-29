#include <iostream>
using namespace std;
int binarySearch(int arr[], int key, int s, int e)
{
    if (s >= e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] < key)
    {
        binarySearch(arr, key, mid + 1, e);
    }
    else
    {
        binarySearch(arr, key, s, mid - 1);
    }
}
int firstOccurence(int arr[], int key, int s, int e)
{
    int mid = s + (e - s) / 2;
    int index = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            index = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return index;
}
int lastOccurence(int arr[], int key, int s, int e)
{
    int mid = s + (e - s) / 2;
    int index = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            index = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return index;
}

int main()
{
    int arr[] = {
        3,
        3,
        3,
        3,
        3,
        3,
        4,
        4,
        5,
        4,
        6,
        7,
        8,
        9,
    };
    int n = sizeof(arr) / sizeof(int) - 1;
    cout << n << endl;
    int key = 3;
    // cout << iterativeMethod(arr, key, 0, 6);
    cout << "found " << key << " at " << binarySearch(arr, key, 0, n) << endl;
    cout << "first occurence " << key << " at " << firstOccurence(arr, key, 0, n) << " complete" << endl;
    cout << "last occurence " << key << " at " << lastOccurence(arr, key, 0, n) << " complete" << endl;

    return 0;
}