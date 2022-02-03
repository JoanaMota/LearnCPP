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

int maxPath = INT32_MIN;
int maxPathSumHelper(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = maxPathSumHelper(root->left);
    int rightSum = maxPathSumHelper(root->right);
    leftSum = std::max(0, leftSum);
    rightSum = std::max(0, rightSum);

    // compute max path sum WITH split
    maxPath = std::max(maxPath, root->val + leftSum + rightSum);

    // But we return the max path sum without the split for the recursion
    return root->val + std::max(leftSum, rightSum);
}
int maxPathSum(TreeNode *root)
{
    maxPathSumHelper(root);
    return maxPath;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    std::cout << maxPathSum(root) << std::endl;
    return 0;
}