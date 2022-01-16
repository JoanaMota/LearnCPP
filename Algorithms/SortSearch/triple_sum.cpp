#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

long triplets(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    long unsigned int itA{0}, itC{0};
    long counter{0};
    for (long unsigned int i = 0; i < b.size(); i++)
    {
        if (i != 0 && b[i] == b[i - 1])
        {
            continue;
        }
        while (a[itA] <= b[i] && itA < a.size())
        {
            itA++;
        }
        while (c[itC] <= b[i] && itC < c.size())
        {
            itC++;
        }
        counter += (long)itA * itC;
        // itA and itC don't need to be zero again because it will only be a smaller value than b in that position
    }
    return counter;
}
long tripletsBruteForce(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
    std::unordered_set<std::string> triplets;
    long counter{0};
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            for (int k = 0; k < c.size(); k++)
            {
                if (a[i] <= b[j] && c[k] <= b[j])
                {
                    std::string temp = std::to_string(a[i]) + std::to_string(b[j]) + std::to_string(c[k]);
                    if (!triplets.count(temp))
                    {
                        triplets.insert(temp);
                        // std::cout << "a: " << a[i] << " b: " << b[j] << " c: " << c[k] << std::endl;
                        counter++;
                    }
                }
            }
        }
    }
    return counter;
}

int main()
{
    std::vector<int> a = {1, 4, 5};
    std::vector<int> b = {2, 3, 3};
    std::vector<int> c = {1, 2, 3};

    std::cout << triplets(a, b, c) << std::endl;
    return 0;
}