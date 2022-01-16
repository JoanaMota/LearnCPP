#include <iostream>
#include <list>
#include <queue>

class Graph
{
private:
    std::list<int> *adjlist;
    int vertices;
    bool *visited;

public:
    Graph(int vertices)
    {
        adjlist = new std::list<int>[vertices];
        this->vertices = vertices;
        visited = new bool[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = false;
    }

    void addedge(int source, int destination, bool bidirectional)
    {
        adjlist[source].push_back(destination);
        if (bidirectional)
        {
            adjlist[destination].push_back(source);
        }
    }

    void print(void)
    {
        for (int i = 0; i < this->vertices; i++)
        {
            std::cout << i << "-->";
            for (auto it : adjlist[i])
            {
                std::cout << it << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void dfs(int startVertex)
    {
        visited[startVertex] = true;
        std::list<int> vertexList = adjlist[startVertex];

        std::cout << startVertex << " ";

        for (std::list<int>::iterator it = vertexList.begin(); it != vertexList.end(); it++)
        {
            if (!visited[*it])
            {
                dfs(*it);
            }
        }
    }

    void bfs(int startVertex)
    {
        for (int i = 0; i < vertices; i++)
            visited[i] = false;
        visited[startVertex] = true; // For this bfs solution the visited array does not necessarily need to be a private member of the class and could be a local member of the the bfs method
        std::queue<int> queue;
        queue.push(startVertex);
        std::list<int>::iterator it;
        while (!queue.empty())
        {
            int currentVextex = queue.front();
            std::cout << currentVextex << " ";
            queue.pop();
            for (it = adjlist[currentVextex].begin(); it != adjlist[currentVextex].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = true;
                    queue.push(*it);
                }
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addedge(0, 2, true);
    g.addedge(4, 2, true);
    g.addedge(1, 3, true);
    g.addedge(4, 3, true);
    g.addedge(1, 4, true);
    g.print();
    std::cout << " DFS " << std::endl;
    g.dfs(0);
    std::cout << std::endl;
    std::cout << " BFS " << std::endl;
    g.bfs(0);
}