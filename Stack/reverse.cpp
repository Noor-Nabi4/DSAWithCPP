#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &, int);
void reverseStack(stack<int> &);
void reverseSentence(string);
int main()
{
    string s = "Hey, how are you doing? ";
    // reverseSentence(s);
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
void reverseSentence(string s)
{
    stack<string> st;
    string word = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            word += s[i];
        }
        else
        {
            st.push(word);
            word = "";
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topele);
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, ele);
}
