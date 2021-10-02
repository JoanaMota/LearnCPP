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

bool isSymmetric(TreeNode *root)
{
    std::queue<TreeNode *> qRight;
    std::queue<TreeNode *> qLeft;
    if (root->right != NULL)
        qRight.push(root->right);
    if (root->left != NULL)
        qLeft.push(root->left);

    while (qRight.empty() == false && qLeft.empty() == false)
    {
        TreeNode *nodeRight = qRight.front();
        TreeNode *nodeLeft = qLeft.front();
        if (nodeRight->data != nodeLeft->data)
            return false;
        qRight.pop();
        qLeft.pop();
        bool hasLeft{false}, hasRight{false};
        if (nodeRight->left != NULL)
        {
            qRight.push(nodeRight->left);
            hasLeft = true;
        }
        if (nodeLeft->right != NULL)
        {
            qLeft.push(nodeLeft->right);
            hasRight = true;
        }
        if (hasLeft != hasRight)
            return false;

        hasLeft = hasRight = false;

        if (nodeRight->right != NULL)
        {
            qRight.push(nodeRight->right);
            hasRight = true;
        }
        if (nodeLeft->left != NULL)
        {
            qLeft.push(nodeLeft->left);
            hasLeft = true;
        }
        if (hasLeft != hasRight)
            return false;
    }
    if (qRight.empty() == false || qLeft.empty() == false)
        return false;

    return true;
}

bool check(TreeNode *root1, TreeNode *root2)
{

    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->data != root2->data)
        return false;
    return check(root1->left, root2->right) && check(root1->right, root2->left);
}
bool isSymmetricOtherSol(TreeNode *root)
{
    if (root == NULL)
        return true;
    return check(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(3);
    std::cout << "PreOrder: ";
    preOrderDFS(root);
    std::cout << std::endl;

    std::cout << "Is Symmetric: " << std::boolalpha << isSymmetricOtherSol(root) << std::endl;
    return 0;
}