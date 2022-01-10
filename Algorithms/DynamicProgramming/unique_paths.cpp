#include <iostream>
#include <vector>

int uniquePathsHelper(int m, int n, std::vector<std::vector<int>> &cache)
{
    if (cache[m][n] != -1)
    {
        return cache[m][n];
    }
    if (n == 0 && m == 0)
    {
        cache[m][n] = 1;
    }
    else if (n == 0)
    {
        cache[m][n] = uniquePathsHelper(m - 1, 0, cache);
    }
    else if (m == 0)
    {
        cache[m][n] = uniquePathsHelper(0, n - 1, cache);
    }
    else
    {
        cache[m][n] = uniquePathsHelper(m, n - 1, cache) + uniquePathsHelper(m - 1, n, cache);
    }

    return cache[m][n];
}

int uniquePaths(int m, int n)
{
    std::vector<std::vector<int>> cache(m, std::vector<int>(n, -1));
    return uniquePathsHelper(m - 1, n - 1, cache);
}

int main()
{
    std::cout << uniquePaths(3, 7) << std::endl;
    return 0;
}