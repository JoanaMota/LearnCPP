#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

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
void bfs(TreeNode *root)
{
    std::queue<TreeNode *> q;
    q.push(root);
    while (q.empty() == false)
    {
        TreeNode *node = q.front();
        std::cout << node->data << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

TreeNode *sortedArrayToBST(std::vector<int> &nums)
{
    if (0 == nums.size())
        return NULL;

    if (1 == nums.size())
        return (new TreeNode(nums[0]));

    int middle = std::floor(nums.size() / 2);
    TreeNode *root = new TreeNode(nums[middle]);
    std::vector<int> left(nums.begin(), nums.begin() + middle);
    root->left = sortedArrayToBST(left);
    std::vector<int> right(nums.begin() + middle + 1, nums.end());
    root->right = sortedArrayToBST(right);

    return root;
}

void print(std::vector<int> vec)
{
    for (int el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    print(input);
    TreeNode *output = sortedArrayToBST(input);
    preOrderDFS(output);
    std::cout << std::endl;
    bfs(output);
    return 0;
}