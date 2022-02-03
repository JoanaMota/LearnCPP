#include <iostream>
#include <queue>
#include <math.h>

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL){};
};

int getHeight(Node *root)
{
    if (NULL == root)
    {
        return -1;
    }
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    int output = left >= right ? left + 1 : right + 1;
    return output;
}

int height(Node *root)
{
    // base case: empty tree has a height of 0
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    // recur for the left and right subtree and consider maximum depth
    return 1 + std::max(left, right);
}

int getHeightIterative(Node *root)
{
    if (NULL == root)
    {
        return 0;
    }
    std::queue<Node *> nodeQ;
    nodeQ.push(root);
    int height{0};
    while (!nodeQ.empty())
    {
        int sizeQ = nodeQ.size();
        for (int i = 0; i < sizeQ; i++)
        {
            Node *temp = nodeQ.front();
            nodeQ.pop();

            if (temp->left != NULL)
            {
                nodeQ.push(temp->left);
            }
            if (temp->right != NULL)
            {
                nodeQ.push(temp->right);
            }
        }
        height++;
    }
    return height;
}

void bfs(Node *head)
{
    std::queue<Node *> q;
    q.push(head);
    while (!q.empty())
    {
        int n = q.size();
        while (n > 0)
        {
            Node *temp = q.front();
            std::cout << temp->data << " ";
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            n--;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    Node *node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(6);
    node->right->right = new Node(8);
    node->right->right->right = new Node(9);
    bfs(node);
    std::cout << getHeight(node) << std::endl;
    std::cout << height(node) << std::endl;
    std::cout << getHeightIterative(node) << std::endl;
    return 0;
}