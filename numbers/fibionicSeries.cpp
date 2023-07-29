#include <iostream>
using namespace std;
void fibionicSeries(int n)
{
    int t1 = 0, t2 = 1, next;
    for (int i = 0; i < n; i++)
    {
        cout << t1 << " ";
        next = t1 + t2;
        t1 = t2;
        t2=next;
    }
}
int main()
{
    int n;
    cin >> n;
    fibionicSeries(n);

    return 0;
}