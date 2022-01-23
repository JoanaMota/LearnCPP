#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec2
{
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        std::string treeStr{""};
        if (NULL == root)
        {
            return treeStr;
        }
        std::queue<TreeNode *> q;
        q.push(root);
        int level{0};
        while (!q.empty())
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (NULL == temp)
                {
                    treeStr.append("n ");
                }
                else
                {
                    treeStr.append(std::to_string(temp->val) + " ");
                }
                if (temp != NULL)
                {
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        }
        return treeStr;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        if (0 == data.size())
        {
            return NULL;
        }
        std::string numberStr = data.substr(0, data.find(" "));
        data = data.substr(data.find(" ") + 1);

        TreeNode *root = new TreeNode(std::stoi(numberStr));
        std::queue<TreeNode *> q;
        q.push(root);
        int level{0};
        while (!q.empty())
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                numberStr = data.substr(0, data.find(" "));
                data = data.substr(data.find(" ") + 1);
                if ("n" == numberStr)
                {
                    temp->left = NULL;
                }
                else
                {
                    TreeNode *tempLeft = new TreeNode(std::stoi(numberStr));
                    temp->left = tempLeft;
                    q.push(temp->left);
                }
                numberStr = data.substr(0, data.find(" "));
                data = data.substr(data.find(" ") + 1);
                if ("n" == numberStr)
                {
                    temp->right = NULL;
                }
                else
                {
                    TreeNode *tempRight = new TreeNode(std::stoi(numberStr));
                    temp->right = tempRight;
                    q.push(temp->right);
                }
            }
        }
        return root;
    }
};

void preorderPrint(TreeNode *node)
{
    if (NULL == node)
    {
        return;
    }

    std::cout << node->val << " ";
    preorderPrint(node->left);
    preorderPrint(node->right);
}
void print(std::string data)
{
    for (char el : data)
    {
        std::cout << el << ".";
    }
    std::cout << std::endl;
}

class Codec
{
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        std::string treeS;
        serializePreOrder(root, treeS);
        return treeS;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        if (0 == data.size())
        {
            return nullptr;
        }
        return deserializePreOrder(data);
    }

private:
    void serializePreOrder(TreeNode *root, std::string &treeS)
    {
        if (root == nullptr)
        {
            treeS.append("n ");
            return;
        }
        treeS.append(std::to_string(root->val) + " ");
        serializePreOrder(root->left, treeS);
        serializePreOrder(root->right, treeS);
    }

    TreeNode *deserializePreOrder(std::string &data)
    {
        if (data.empty())
        {
            return nullptr;
        }

        std::string numberStr = data.substr(0, data.find(" "));
        data = data.substr(data.find(" ") + 1);
        if ("n" == numberStr)
        {
            return nullptr;
        }

        TreeNode *node = new TreeNode(std::stoi(numberStr));
        node->left = deserializePreOrder(data);
        node->right = deserializePreOrder(data);
        return node;
    }
};

int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->right->left = new TreeNode(10);
    node->right->right = new TreeNode(5);

    preorderPrint(node);
    std::cout << std::endl;

    Codec codec;
    // print(ser.serialize(node));
    std::string treeString = codec.serialize(node);
    std::cout << treeString << std::endl;
    preorderPrint(codec.deserialize(treeString));
    // std::cout << std::endl;
    return 0;
}