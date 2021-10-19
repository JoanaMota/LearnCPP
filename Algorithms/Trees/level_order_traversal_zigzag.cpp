#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> output;
    if (root == NULL)
        return output;

    std::stack<TreeNode *> stack;
    std::stack<TreeNode *> stack_temp;
    stack.push(root);
    int level{0};
    bool left{true};
    while (!stack.empty())
    {
        output.push_back({});
        while (!stack.empty())
        {
            TreeNode *temp = stack.top();
            output[level].push_back(temp->val);
            stack.pop();
            if (left)
            {
                if (temp->left)
                {
                    stack_temp.push(temp->left);
                }
                if (temp->right)
                {
                    stack_temp.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    stack_temp.push(temp->right);
                }
                if (temp->left)
                {
                    stack_temp.push(temp->left);
                }
            }
        }
        stack = std::move(stack_temp);
        left = !left;
        level++;
    }
    return output;
}

void print(std::vector<std::vector<int>> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    // root->right->left = new TreeNode(15);
    // root->left->right = new TreeNode(10);

    std::vector<std::vector<int>> output = zigzagLevelOrder(root);
    print(output);
    return 0;
}