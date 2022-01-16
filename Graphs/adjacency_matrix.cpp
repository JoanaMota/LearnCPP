#include <iostream>
#include <queue>
#include <stack>

class Graph
{
private:
    bool **adjMatrix;
    int numVertices;
    bool *visited;

public:
    // Initialize the matrix to zero
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix = new bool *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;
        }
        visited = new bool[numVertices];
    }

    void addEdge(int i, int j)
    {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    void removeEdge(int i, int j)
    {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

    void print()
    {
        for (int i = 0; i < numVertices; i++)
        {
            std::cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                std::cout << adjMatrix[i][j] << " ";
            std::cout << std::endl;
        }
    }

    void dfs(int startVertex)
    {
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;
        visited[startVertex] = true;

        std::stack<int> s;
        s.push(startVertex);
        while (!s.empty())
        {
            int currentVertex = s.top();
            std::cout << currentVertex << " ";
            s.pop();
            for (int i = 0; i < numVertices; i++)
            {
                if (adjMatrix[currentVertex][i] && !visited[i])
                {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
        std::cout << std::endl;
    }

    void bfs(int startVertex)
    {
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;
        visited[startVertex] = true;

        std::queue<int> q;
        q.push(startVertex);
        while (!q.empty())
        {
            int currentVertex = q.front();
            std::cout << currentVertex << " ";
            q.pop();
            for (int i = 0; i < numVertices; i++)
            {
                if (adjMatrix[currentVertex][i] && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        std::cout << std::endl;
    }

    ~Graph()
    {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    g.print();
    std::cout << " DFS " << std::endl;
    g.dfs(0);
    std::cout << std::endl;
    std::cout << " BFS " << std::endl;
    g.bfs(0);
}