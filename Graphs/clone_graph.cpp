#include <iostream>
#include <unordered_map>
#include <vector>
class Node
{
public:
    int val;
    std::vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = std::vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node *>();
    }
    Node(int _val, std::vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

std::unordered_map<Node *, Node *> visited;
Node *cloneGraph(Node *node)
{
    if (nullptr == node)
    {
        return nullptr;
    }
    if (visited.count(node))
    {
        return visited[node];
    }

    Node *clone = new Node(node->val);
    clone->neighbors.resize(node->neighbors.size());

    visited[node] = clone;

    for (int i = 0; i < node->neighbors.size(); i++)
    {
        clone->neighbors[i] = cloneGraph(node->neighbors[i]);
    }
    return clone;
}
int main()
{
    return 0;
}