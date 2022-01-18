#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int f_val) : val(f_val), left(nullptr), right(nullptr) {}
    TreeNode(int f_val, TreeNode *f_left, TreeNode *f_right) : val(f_val), left(f_left), right(f_right) {}
};

bool isSame(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    if (root1->val != root2->val)
    {
        return false;
    }
    return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == nullptr)
    {
        return false;
    }
    return isSame(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

void printPreOrderDFS(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->val << " ";
    printPreOrderDFS(root->left);
    printPreOrderDFS(root->right);
}

int main()
{
    TreeNode *subtree = new TreeNode(1);
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(1);

    printPreOrderDFS(root);
    std::cout << std::endl;
    printPreOrderDFS(subtree);

    std::cout << std::boolalpha << isSubtree(root, subtree) << std::endl;
    return 0;
}