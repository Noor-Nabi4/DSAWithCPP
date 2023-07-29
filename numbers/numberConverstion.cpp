#include <iostream>
#include <math.h>
using namespace std;
int DescimailToBinary(int n)
{
    int ans = 0, i = 0;
    while (n != 0)
    {
        int bit = n % 2;
        // ans = (bit * pow(10, i)) + ans;
        ans = (ans * 10) + bit;
        // n = n >> 1;
        n/=2;
        // i++;
    }
    cout << ans << '\n';
    return ans;
}
int main()
{
    int n;
    cin >> n;
    DescimailToBinary(n);

    return 0;
}