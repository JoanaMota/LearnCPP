#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>

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

std::vector<std::vector<int>> levelOrderFaster(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    if (!root)
        return res;

    std::queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        res.push_back({});

        for (int i = 0; i < n; i++)
        {
            TreeNode *r = q.front();
            q.pop();
            res[level].push_back(r->data);

            if (r->left)
                q.push(r->left);
            if (r->right)
                q.push(r->right);
        }
        level++;
    }
    return res;
}
std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> output;
    if (root == NULL)
    {
        return output;
    }

    std::vector<int> level;
    std::queue<TreeNode *> qCurr;
    std::queue<TreeNode *> qNext;
    qCurr.push(root);
    bool levelChanged{true};
    while (qCurr.empty() == false)
    {
        TreeNode *temp = qCurr.front();
        level.push_back(temp->data);
        std::cout << "data: " << temp->data << " level size: " << level.size() << " qCurr size: " << qCurr.size() << " |";
        qCurr.pop();
        if (temp->left != NULL)
        {
            qNext.push(temp->left);
        }
        if (temp->right != NULL)
        {
            qNext.push(temp->right);
        }
        if (qCurr.empty() == true)
        {
            std::cout << " CURRENT EMPTY ";
            qCurr = qNext;
            levelChanged = true;
            while (qNext.empty() == false)
                qNext.pop();
        }
        if (levelChanged)
        {
            std::cout << " PUSH LEVEL ";
            output.push_back(level);
            while (level.empty() == false)
                level.pop_back();
            levelChanged = false;
        }
    }
    return output;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->right = new TreeNode(10);
    root->left->left = new TreeNode(8);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);
    std::cout << "PreOrder: ";
    preOrderDFS(root);
    std::cout << std::endl;

    std::vector<std::vector<int>> treeData = levelOrderFaster(root);
    std::cout << treeData.size() << std::endl;
    std::cout << treeData[0].size() << std::endl;
    for (int level = 0; level < treeData.size(); level++)
    {
        std::cout << "level: " << level << " ->";
        for (int element = 0; element < treeData[level].size(); element++)
        {
            std::cout << treeData[level][element] << " ";
        }
    }

    return 0;
}