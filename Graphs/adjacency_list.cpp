#include <iostream>
#include <list>

class Graph
{
private:
    std::list<int> *adjlist;
    int vertices;

public:
    Graph(int vertices)
    {
        adjlist = new std::list<int>[vertices];
        this->vertices = vertices;
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
}