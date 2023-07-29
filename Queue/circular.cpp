#include <iostream>
using namespace std;
#define Max 5
class Queue
{
    int arr[Max], front, rear;

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
    q.Enqueue(5);
    q.Enqueue(5);
    q.Enqueue(5);
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    return 0;
}
Queue::Queue()
{
    front = -1;
    rear = -1;
}
bool Queue::isFull()
{
    if (front == 0 && rear == Max - 1)
        return true;
    if (front == rear + 1 || rear == Max - 1)
        return true;
    return false;
}
bool Queue::isEmpty()
{
    if (front == -1)
        return true;
    return false;
}
bool Queue::Enqueue(int data)
{
    if (isFull())
    {
        "Queue is Full\n";
        return false;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % Max;
    arr[rear] = data;
    return true;
}
bool Queue::Dequeue()
{
    int element;
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        return false;
    }
    element = arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % Max;
    }
    cout << element << " pop from queue\n";
    return true;
}