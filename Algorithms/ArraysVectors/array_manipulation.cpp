#include <iostream>
#include <vector>
#include <chrono> // std::chrono::system_clock

long arrayManipulation(int n, std::vector<std::vector<int>> &queries)
{
    std::vector<long> vec(n, 0);
    long output{0};
    for (int i = 0; i < queries.size(); ++i)
    {
        int a = queries[i][0];
        int b = queries[i][1];
        long k = static_cast<long>(queries[i][2]);
        for (int j = a - 1; j < b; j++)
        {
            vec[j] += k;
            output = std::max(output, vec[j]);
        }
    }
    return output;
}
long arrayManipulationFaster(int n, std::vector<std::vector<int>> &queries)
{
    std::vector<long> vec(n, 0);
    for (int i = 0; i < queries.size(); ++i)
    {
        int a = queries[i][0];
        int b = queries[i][1];
        long k = static_cast<long>(queries[i][2]);
        vec[a - 1] += k;
        vec[b] -= k;
    }
    long temp{vec[0]};
    long output{0};
    for (int i = 1; i < vec.size(); i++)
    {
        temp += vec[i];
        output = std::max(output, temp);
    }
    return output;
}

int main()
{
    std::vector<std::vector<int>> queries = {{1, 2, 100}, {2, 5, 100}, {3, 4, 100}};

    auto begin = std::chrono::high_resolution_clock::now();
    long output = arrayManipulation(5, queries);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Array manipulation: " << output << " Time: " << elapsed.count() << " nanoseconds" << std::endl;
    auto begin2 = std::chrono::high_resolution_clock::now();
    long output2 = arrayManipulationFaster(5, queries);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    std::cout << "Array manipulation Faster: " << output2 << " Time: " << elapsed2.count() << " nanoseconds" << std::endl;
    return 0;
}