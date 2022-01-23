#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root, std::vector<int> &numbers)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, numbers);
    numbers.push_back(root->val);
    inorder(root->right, numbers);
}

int kthSmallest(TreeNode *root, int k)
{
    std::vector<int> numbers;
    inorder(root, numbers);
    return numbers[k - 1];
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);

    std::cout << kthSmallest(root, 3) << std::endl;
    return 0;
}