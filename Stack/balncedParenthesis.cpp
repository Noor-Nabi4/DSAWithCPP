#include <iostream>
#include <stack>
using namespace std;
bool isBalnced(string);
int main()
{
    string s = "{([])}";
    if (isBalnced(s))
    {
        cout << "valid";
    }
    else
    {
        cout << "invalid";
    }
    return 0;
}
bool isBalnced(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            if (st.top() == '(')
                st.pop();
            else
                return false;
        }
        else if (s[i] == '}')
        {
            if (st.top() == '{')
                st.pop();
            else
                return false;
        }
        else if (s[i] == ']')
        {
            if (st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    return true;
}