#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
    Node *newnode(int data)
    {
        Node *x = new Node(data);
        return x;
    }

public:
    struct Node *addTwoLists(struct Node *l1, struct Node *l2)
    {

        Node *prev = NULL;
        stack<Node *> s1, s2, s3;
        while (l1 != NULL)
        {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            s2.push(l2);
            l2 = l2->next;
        }
        int carry = 0;
        while (!s1.empty() && !s2.empty())
        {
            int sum = s1.top()->data + s2.top()->data + carry;
            Node *temp = newnode(sum % 10);
            s3.push(temp);
            if (sum > 9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            s1.pop();
            s2.pop();
        }
        while (!s1.empty())
        {
            int sum = carry + s1.top()->data;
            Node *temp = newnode(sum % 10);
            s3.push(temp);
            if (sum > 9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            s1.pop();
        }
        while (!s2.empty())
        {
            int sum = carry + s2.top()->data;
            Node *temp = newnode(sum % 10);
            s3.push(temp);
            if (sum > 9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            s2.pop();
        }
        if (carry == 1)
        {
            Node *temp = newnode(1);
            s3.push(temp);
        }
        if (!s3.empty())
            prev = s3.top();
        while (!s3.empty())
        {
            Node *temp = s3.top();
            s3.pop();
            if (s3.size() == 0)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = s3.top();
            }
        }
        return prev;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
