#include <iostream>
using namespace std;
#define Max 10
class Queue
{
    int arr[Max];
    int front, rear;

public:
    Queue();
    bool Enqueue(int);
    bool Dequeue();
    bool isEmpty();
    bool isFull();
    void peek();
};
int main()
{
    Queue q;
    q.Enqueue(6);
    q.peek();
    q.Dequeue();
    if (q.isEmpty())
    {
        cout << "Queue is Empty";
    }
    return 0;
}
Queue::Queue()
{
    front = -1;
    rear = -1;
}
bool Queue::Enqueue(int data)
{
    if (isFull())
    {
        cout << "queue is full";
        return false;
    }
    if (front == -1)
        front = 0;
    arr[++rear] = data;
    return true;
}
bool Queue::Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty";
        return false;
    }
    int element = arr[front];
    if (front >= rear)
    {
        front = rear = -1;
    }
    front++;
    cout << "pop from queue: " << element << endl;
    return true;
}
bool Queue::isEmpty()
{
    if (front == -1)
        return true;
    return false;
}
bool Queue::isFull()
{
    if (front == 0 && rear == Max - 1)
        return true;
    return false;
}
void Queue::peek()
{
    if (isEmpty())
    {
        cout << "Queue is Empty";
        return;
    }
    cout << arr[front] << endl;
}