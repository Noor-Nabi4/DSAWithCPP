#include <iostream>
#include <vector>
using namespace std;
vector<int> missAndDup(int *arr, int n)
{
    // code here
    vector<int> v;

    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] > 0)
        {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        else
        {
            v.push_back(abs(arr[i]));
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            v.push_back(i + 1);
        }
    }
    return v;
}
int main()
{
    int Arr[] = {1,2,3,4,5,5,7,8,9};
    int N = sizeof(Arr) / sizeof(int);
    vector<int> v = missAndDup(Arr, N);
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}