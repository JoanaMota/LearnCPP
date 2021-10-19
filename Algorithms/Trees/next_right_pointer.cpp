#include <iostream>
#include <vector>
#include <queue>
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connected(Node *root)
{
    std::queue<Node *> q;
    if (root)
        q.push(root);
    while (q.empty() == false)
    {
        int size = q.size();
        while (size != 0)
        {
            size--;
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            if (size != 0)
                temp->next = q.front();
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *rootConnected = connected(root);
    return 0;
}