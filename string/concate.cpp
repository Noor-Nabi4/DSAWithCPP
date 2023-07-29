#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string s1 = "NoorNpl";
    string s2 = "Nabi";
    s1 += s2;
    s2 = s1.substr(0, (s1.size() - s2.size()));
    s1 = s1.substr(s2.size());

    cout << "s1 " << s1 << "  s2 " << s2;

    return 0;
}