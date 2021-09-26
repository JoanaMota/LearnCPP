#include <iostream>
#include <queue>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int f_data)
    {
        this->data = f_data;
        left = NULL;
        right = NULL;
    }
};

void preorderTraversal(TreeNode *node)
{
    if (node == NULL)
        return;

    std::cout << node->data << "->";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(TreeNode *node)
{
    if (node == NULL)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << "->";
}

void inorderTraversal(TreeNode *node)
{
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    std::cout << node->data << "->";
    inorderTraversal(node->right);
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

bool isFullBinaryTree(TreeNode *root)
{
    // Checking for emptiness
    if (root == NULL)
        return true;

    // Checking for the presence of children
    if (root->left == NULL && root->right == NULL)
        return true;

    if ((root->left) && (root->right))
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

    return false;
}

int depth(TreeNode *node)
{
    TreeNode *temp = node;
    int d = 0;
    while (temp != NULL)
    {
        d++;
        temp = temp->left;
    }
    return d;
}

bool isPerfectR(TreeNode *root, int d, int level = 0)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return (d == level + 1);

    if (root->left == NULL || root->right == NULL)
        return false;

    return isPerfectR(root->left, d, level + 1) &&
           isPerfectR(root->right, d, level + 1);
}

bool isPerfect(TreeNode *root)
{
    int d = depth(root);
    return isPerfectR(root, d);
}

int countNumNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

// Check if the tree is a complete binary tree
bool checkComplete(TreeNode *root, int index)
{
    // Total number os nodes at the beginning, thus the static
    static int numberNodes = countNumNodes(root);
    // Check if the tree is empty
    if (root == NULL)
        return true;

    if (index >= numberNodes)
        return false;

    return (checkComplete(root->left, 2 * index + 1) && checkComplete(root->right, 2 * index + 2));
}

bool checkHeightBalance(TreeNode *root, int height)
{
    // Check for emptiness
    int leftHeight = 0, rightHeight = 0;

    int l = 0, r = 0;

    if (root == NULL)
    {
        height = 0;
        return 1;
    }

    l = checkHeightBalance(root->left, leftHeight);
    r = checkHeightBalance(root->right, rightHeight);

    height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    if (std::abs(leftHeight - rightHeight >= 2))
        return 0;

    else
        return l && r;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    std::cout << "Inorder traversal ";
    inorderTraversal(root);

    std::cout << "\nPreorder traversal ";
    preorderTraversal(root);

    std::cout << "\nPostorder traversal ";
    postorderTraversal(root);

    std::cout << "\nBreadth First Search ";
    bfs(root);
    std::cout << std::endl;

    std::cout << "Full ? " << std::boolalpha << isFullBinaryTree(root) << std::endl;
    std::cout << "Perfect ? " << std::boolalpha << isPerfect(root) << std::endl;
    std::cout << "Complete ? " << std::boolalpha << checkComplete(root, 0) << std::endl;
    std::cout << "Balanced ? " << std::boolalpha << checkHeightBalance(root, 0) << std::endl;
}