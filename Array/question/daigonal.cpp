#include <iostream>
#define Max 100
using namespace std;
int Diagonal(int arr[][Max], int n)
{
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l += arr[i][i];
        r += arr[i][n - i - 1];
    }
    return abs(l - r);
}
int main()
{
    int n = 3;
    int arr[][Max] = {
        {1, 2, 4},
        {4, 5, 6},
        {7, 8, 9}};
    cout << Diagonal(arr, n);

    return 0;
}