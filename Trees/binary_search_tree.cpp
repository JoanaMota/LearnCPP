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

bool isBST(TreeNode *root)
{
    if (root == NULL)
        return true;

    /* false if left is > than root */
    if (root->left != NULL && root->left->data > root->data)
        return false;

    /* false if right is < than root */
    if (root->right != NULL && root->right->data < root->data)
        return false;

    /* false if, recursively, the left or right is not a BST */
    if (!isBST(root->left) || !isBST(root->right))
        return false;

    /* passing all that, it's a BST */
    return true;
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
void inorderTraversal(TreeNode *node)
{
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    std::cout << node->data << "->";
    inorderTraversal(node->right);
}
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

bool search(TreeNode *root, int number)
{
    if (root == NULL)
        return false;
    if (number == root->data)
        return true;
    if (number < root->data)
        return search(root->left, number);
    if (number > root->data)
        return search(root->right, number);
}
TreeNode *insert(TreeNode *root, int data)
{
    if (search(root, data))
    {
        std::cout << "Element already present in tree" << std::endl;
        return root;
    }
    if (root == NULL)
        return new TreeNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
// Find the inorder successor
TreeNode *minValueNode(TreeNode *node)
{
    TreeNode *current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
TreeNode *deleteNode(TreeNode *root, int data)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        // If the node is with only one child or no child
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        TreeNode *temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    std::cout << "Breadth First Search: ";
    bfs(root);
    std::cout << std::endl;
    std::cout << "Is a Binary Search Tree: " << std::boolalpha << isBST(root) << std::endl;

    // Search
    int number = 5;
    std::cout << "Search for " << number << " " << std::boolalpha << search(root, number) << std::endl;

    // Insertion
    int newData = 5;
    TreeNode *newRoot = insert(root, newData);
    bfs(root);
    std::cout << std::endl;
    std::cout << "Search for " << newData << " " << std::boolalpha << search(root, newData) << std::endl;
    newData = 2;
    newRoot = insert(root, newData);
    bfs(root);
    std::cout << std::endl;
    inorderTraversal(root);
    std::cout << std::endl;
    std::cout << "Search for " << newData << " " << std::boolalpha << search(root, newData) << std::endl;

    // Deletion
    int toDelete = 7;
    std::cout << "Search for " << toDelete << " " << std::boolalpha << search(root, toDelete) << std::endl;
    TreeNode *newRoot2 = deleteNode(root, toDelete);
    bfs(root);
    std::cout << std::endl;
    inorderTraversal(root);
    std::cout << std::endl;
    std::cout << "Search for " << toDelete << " " << std::boolalpha << search(root, toDelete) << std::endl;

    std::cout << "Preorder: ";
    preorderTraversal(root);
    std::cout << std::endl;
    std::cout << "Postorder: ";
    postorderTraversal(root);
    std::cout << std::endl;
}