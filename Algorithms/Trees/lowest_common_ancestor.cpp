#include <iostream>
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL){};
};

Node *lca(Node *root, int v1, int v2)
{
    if (root->data < v1 && root->data < v2)
    {
        return lca(root->right, v1, v2);
    }
    if (root->data > v1 && root->data > v2)
    {
        return lca(root->left, v1, v2);
    }
    return root;
}

int main()
{
    Node *node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(7);
    node->left->right = new Node(3);
    node->left->left = new Node(1);
    node->right->left = new Node(6);
    Node *output = lca(node, 1, 3);
    std::cout << output->data << std::endl;
    return 0;
}