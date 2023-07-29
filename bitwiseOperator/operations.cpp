#include <iostream>
using namespace std;
int main()
{
    int a = 4;
    int b = 6;
    cout << "a&b " << (a & b) << '\n';
    cout << "a|b " << (a | b) << '\n';
    cout << "~a " << (~a) << '\n';
    cout << "a^b " << (a ^ b) << '\n';

    return 0;
}