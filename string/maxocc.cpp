#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    string s = "nOorahmadd";
    unordered_map<char, int> count;
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i]]++;
    }
    unordered_map<char, int>::iterator p;
    for (p = count.begin(); p != count.end(); p++)
    {
        cout<<p->first<<" is "<<p->second<<endl;
    }
    /*int n = s.size();
    char c;
    int count=0;
    int maxchar = 0;

    char currchar;

     for (int i = 0; i < n; i++)
    {

        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[i] == s[j] || s[i] == s[j]-'A'+'a')
            {
                count++;
            }
        }
        if (count > maxchar)
        {
            c = s[i];
            maxchar = count;
        }
    }
cout<<c <<" is "<<maxchar<<" times";*/
    return 0;
}