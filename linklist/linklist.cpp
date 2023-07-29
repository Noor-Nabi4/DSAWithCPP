#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int);
};
void insert(Node *&, int);
Node *reverseItretive(Node *&);
Node *reverseRecursive(Node *&);
Node *reverseKNode(Node *&, int);
void deletebyValue(Node *&, int);
void makecircle(Node *&);
void makeCycle(Node *&);
bool detectCycle(Node *&);
void removeCycle(Node *&);
int length(Node *);
Node *kAppend(Node *&, int);
void evenAfterOdd(Node *&);
int countNodeInCircle(Node *&);
void print(Node *&);
int main()
{
    Node *head = NULL;
    for (int i = 1; i <= 10; i++)
        insert(head, i);
    // makecircle(head);
    // cout<<countNodeInCircle(head);
    // print(head);
    // Node *reverse = reverseItretive(head);
    // Node *reverse = reverseRecursive(head);
    // Node *reverseK = reverseKNode(head, 3);
    // makeCycle(head);
    // detectCycle(head);
    // removeCycle(head);
    print(head);
    // Node *k = kAppend(head, 3);
    evenAfterOdd(head);
    print(head);
    return 0;
}
Node::Node(int value)
{
    data = value;
    next = NULL;
}
void insert(Node *&head, int value)
{
    Node *new_node = new Node(value);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
Node *reverseItretive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node *reverseRecursive(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *new_head = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}
Node *reverseKNode(Node *&head, int k)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
        head->next = reverseKNode(next, k);
    return prev;
}
void deletebyValue(Node *&head, int value)
{
    if (head == NULL)
    {
        cout << "linklist is empty";
        return;
    }
    Node *temp = head;
    Node *prev = head;
    if (temp->data == value)
    {
        head = temp->next;
        delete prev;
        return;
    }
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data == value)
    {
        prev->next = temp->next;
        delete temp;
        return;
    }

    cout << value << " : Not Found";
}
void makecircle(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
}
void makeCycle(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head->next->next;
}
bool detectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
void removeCycle(Node *&head)
{
    if (detectCycle(head))
    {
        Node *slow = head;
        Node *fast = head;
        do
        {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        fast = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = NULL;
    }
}
int countNodeInCircle(Node *&head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 1;
    Node *temp = head->next;
    while (temp != head && temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
Node *kAppend(Node *&head, int k)
{
    Node *new_head;
    Node *newtail;
    Node *tail = head;
    int l = length(head);
    k = k % l;
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newtail = tail;
        }
        if (count == l - k + 1)
        {
            new_head = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return new_head;
}
void evenAfterOdd(Node *&head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenStart = even;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    if (odd->next == NULL)
    {
        even->next = NULL;
    }
}
void print(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}