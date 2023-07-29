#include <iostream>
#include <stack>
using namespace std;
class Queue
{
    stack<int> st;

public:
    void push(int);
    int pop();
};
int main()
{
    Queue q;
    for (int i = 1; i <= 5; i++)
        q.push(i);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}
void Queue::push(int data)
{
    st.push(data);
}
int Queue::pop()
{
    if (st.empty())
    {
        cout << "stack underflow";
        return -1;
    }
    int top = st.top();
    st.pop();
    if (st.empty())
    {
        return top;
    }
    int x = pop();
    st.push(top);
    return x;
}