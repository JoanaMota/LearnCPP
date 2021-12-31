#include <iostream>
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL){};
};

bool check(Node *node, Node *left = NULL, Node *right = NULL)
{
    if (node == NULL)
    {
        return true;
    }
    if (left != NULL && node->data <= left->data)
    {
        return false;
    }
    if (right != NULL && node->data >= right->data)
    {
        return false;
    }
    return check(node->left, left, node) && check(node->right, node, right);
}

bool checkBST(Node *root)
{
    return check(root);
}

int main()
{
    Node *node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(6);
    node->left->left = new Node(1);
    node->left->right = new Node(3);
    node->right->left = new Node(8);
    node->right->right = new Node(7);
    std::cout << std::boolalpha << checkBST(node) << std::endl;
    return 0;
}