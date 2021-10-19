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

void inorder(TreeNode *root, std::vector<int> &output)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, output);
    output.push_back(root->val);
    inorder(root->right, output);
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> data;
    inorder(root, data);
    return data;
}

void print(std::vector<int> &data)
{
    for (int i : data)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    std::vector<int> data = inorderTraversal(root);
    print(data);
    return 0;
}