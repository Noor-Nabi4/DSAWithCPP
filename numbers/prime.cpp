#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void markasnotPrime(vector<bool> &v, int i, int n)
{
    for (int j = 2 * i; j < n; j = j + i)
    {
        v[j] = 0;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = 0;
    long long int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            // cout << i << endl;
            count++;
            markasnotPrime(prime, i, n);
        }
    }
    cout << count;

    return 0;
}