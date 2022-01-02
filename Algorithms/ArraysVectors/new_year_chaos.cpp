#include <iostream>
#include <vector>
#include <map>
void print(std::vector<int> vec)
{
    for (int el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}
void minimumBribes(std::vector<int> q)
{
    int nrBribes{0};
    for (int i = 0; i < q.size(); i++)
    {
        if (q[i] - 1 - i > 2)
        {
            std::cout << "Too chaotic" << std::endl;
            return;
        }
        for (int j = std::max(q[i] - 2, 0); j < i; j++)
        {
            if (q[j] > q[i])
            {
                nrBribes++;
            }
        }
    }
    std::cout << nrBribes << std::endl;
}
int main()
{
    std::vector<int> q = {2, 1, 5, 3, 4};
    minimumBribes(q);
    return 0;
}