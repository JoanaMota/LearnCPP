#include <iostream>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (NULL == p && NULL == q)
    {
        return true;
    }
    if (q != NULL && p != NULL && q->val == p->val)
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    else
    {
        return false;
    }
}

void preorder(TreeNode *root)
{
    if (NULL == root)
    {
        return;
    }
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    TreeNode *root1 = new TreeNode(0);
    // root1->left = new TreeNode(2);
    // root1->right = new TreeNode(2);
    TreeNode *root2 = new TreeNode(0);
    // root2->left = new TreeNode(2);
    // root2->right = new TreeNode(2);
    std::cout << std::boolalpha << isSameTree(root1, root2) << std::endl;
    return 0;
}