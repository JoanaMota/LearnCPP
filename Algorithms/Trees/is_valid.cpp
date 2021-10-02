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

bool isBST(TreeNode *root, TreeNode *l = NULL, TreeNode *r = NULL)
{
    if (root == NULL)
        return true;

    if (l != NULL && root->data <= l->data)
        return false;

    if (r != NULL && root->data >= r->data)
        return false;

    return isBST(root->left, l, root) &&
           isBST(root->right, root, r);
}

bool isValidBST(TreeNode *root)
{
    return isBST(root);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    std::cout << "PreOrder: ";
    preOrderDFS(root);
    std::cout << std::endl;

    std::cout << "Is Valid: " << std::boolalpha << isValidBST(root) << std::endl;
    return 0;
}