#include <iostream>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int f_data) : data(f_data), left(nullptr), right(nullptr) {}
};

void preOrderDFS(TreeNode *root)
{
    if (root == nullptr)
        return;
    std::cout << root->data << " ";
    preOrderDFS(root->left);
    preOrderDFS(root->right);
}

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);

    if (maxLeft > maxRight)
        return maxLeft + 1;
    else
        return maxRight + 1;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::cout << "PreOrder: ";
    preOrderDFS(root);
    std::cout << std::endl;

    std::cout << "Max Depth: " << maxDepth(root) << std::endl;
    return 0;
}