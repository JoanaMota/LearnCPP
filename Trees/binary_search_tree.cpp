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

bool isBST(TreeNode *root, TreeNode *l = NULL, TreeNode *r = NULL)
{
    // Base condition
    if (root == NULL)
        return true;

    // if left node exist then check it has
    // correct data or not i.e. left node's data
    // should be less than root's data
    if (l != NULL && root->data <= l->data)
        return false;

    // if right node exist then check it has
    // correct data or not i.e. right node's data
    // should be greater than root's data
    if (r != NULL && root->data >= r->data)
        return false;

    // check recursively for every node.
    return isBST(root->left, l, root) &&
           isBST(root->right, root, r);
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
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);

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