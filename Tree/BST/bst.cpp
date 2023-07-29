#include <iostream>
#include <queue>
using namespace std;
class Node
{
    int data;
    Node *left, *right;

public:
    Node() : data(0),
             left(NULL),
             right(NULL)
    {
    }
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
    Node *insert(Node *, int);
    void Inorder(Node *);
    void LevelOrder(Node *);
    void buildFromLevelOrder(Node *&);
    int countLeafNode(Node *, int &);
    int height(Node *);
    bool checkIdenticalTrees(Node *, Node *);
    int Diameter(Node *, int *);
};
int main()
{
    Node b, *root = NULL;
    root = b.insert(root, 10);
    b.insert(root, 20);
    b.insert(root, 15);
    b.insert(root, 25);
    b.insert(root, 30);
    b.insert(root, 35);
    b.insert(root, 29);
    b.insert(root, 7);
    b.insert(root, 6);
    b.insert(root, 8);
    // b.buildFromLevelOrder(root);
    // b.LevelOrder(root);
    int count = 0;
    // cout<<b.countLeafNode(root,count);
    // cout << b.height(root);
    cout << b.Diameter(root, &count);
    // b.Inorder(root);
    //
    /*
                10
                /  \
               7     20
              / \     / \
             6   8   15   25
                          \
                            30
                            /  \
                           29   35
    */
    // 10 7 20 6 8 15 25 -1 -1 -1 -1 -1 -1 -1 30 29 35 -1 -1 -1 -1 -1

    return 0;
}
Node *Node::insert(Node *root, int value)
{
    if (!root)
    {
        return new Node(value);
    }
    if (value > root->data)
        root->right = insert(root->right, value);
    else if (value < root->data)
        root->left = insert(root->left, value);
    return root;
}
void Node::buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    int data;
    cout << "enter data for root :";
    cin >> data;
    cout << endl;
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter left node for :" << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right node for :" << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
void Node::Inorder(Node *root)
{
    if (!root)
        return;
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
int Node::countLeafNode(Node *root, int &count)
{
    if (root == NULL)
        return count;
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    countLeafNode(root->left, count);
    countLeafNode(root->right, count);
}
int Node::height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
bool Node::checkIdenticalTrees(Node *t1, Node *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return true;
    }
    if (t1 != NULL && t2 != NULL)
    {
        return (t1->data == t2->data && checkIdenticalTrees(t1->left, t2->left) && checkIdenticalTrees(t1->right, t2->right));
    }
}
int Node::Diameter(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int left = Diameter(root->left, &lh);
    int right = Diameter(root->right, &rh);
    int currDia = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDia, max(left, right));
}
void Node::LevelOrder(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}