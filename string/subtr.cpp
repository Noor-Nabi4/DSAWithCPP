#include <iostream>
using namespace std;
string removeaccourance(string &strng, string sub)
{
    if (strng.find(sub) < strng.length())
    {
        strng.erase(strng.find(sub), sub.length());
        removeaccourance(strng,sub);
    }
    return strng;
}
int main()
{
    string any, sub;
    cout << "Enter String : ";
    cin >> any;
    cout << "Enter SubString : ";
    cin >> sub;
    removeaccourance(any, sub);
    cout<<any;
    // cout << "After remover substring : " << \removeaccourance(any, sub);
    return 0;
}