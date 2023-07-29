#include <iostream>
using namespace std;
#define Max 10
class Stack
{
    int top;

public:
    int arr[Max];
    Stack();
    int Top();
    void push(int);
    void pop();
    bool isEmpty();
    bool isFull();
};
int main()
{
    Stack s;
    s.push(5);
    s.push(6);
    s.Top();
    s.push(7);
    s.Top();
    s.pop();
    s.Top();
    s.push(10);
    s.Top();
    s.push(9);
    s.Top();
    s.pop();

    return 0;
}
Stack::Stack()
{
    top = -1;
}
int Stack::Top()
{
    if (isEmpty())
    {
        cout << "Stack Is Empty\n";
        return -1;
    }
    cout << arr[top] << endl;
    return top;
}
void Stack::push(int data)
{
    if (isFull())
    {
        cout << "Stack Is Full\n";
        return;
    }
    arr[++top] = data;
}
void Stack::pop()
{
    if (isEmpty())
    {
        cout << "No Element for pop\n";
        return;
    }
    cout<<"pop from stack : "<<arr[top--]<<endl;
}
bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    return false;
}
bool Stack::isFull()
{
    if (top == Max - 1)
        return true;
    return false;
}