#include <iostream>
#include <queue>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *invertTree(TreeNode *root)
{
    if (NULL == root)
    {
        return NULL;
    }
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}
void preOderDFS(TreeNode *root)
{
    if (NULL == root)
    {
        return;
    }
    std::cout << root->val << " ";
    preOderDFS(root->left);
    preOderDFS(root->right);
}

void bfs(TreeNode *root)
{
    std::cout << " BFS " << std::endl;
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        std::cout << temp->val << " ";
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    std::cout << std::endl;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    preOderDFS(root);
    std::cout << std::endl;
    bfs(root);
    TreeNode *inverted = invertTree(root);
    preOderDFS(inverted);
    std::cout << std::endl;
    bfs(inverted);
    return 0;
}