#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

void print(std::vector<int> &vec)
{
    for (int el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int fibRecursion(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fibRecursion(n - 1) + fibRecursion(n - 2);
}

int fibMemo(int n, std::vector<int> &memo)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }
    if (n == 0 || n == 1)
    {
        memo[n] = n;
    }
    else
    {
        memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    }
    return memo[n];
}

int fibMemoized(int n)
{
    std::vector<int> memo(n + 1, -1);
    int result = fibMemo(n, memo);
    return result;
}

int fibBottomUp(int n)
{
    int t1 = 0, t2 = 1, nextTerm = 0;
    for (int i = 0; i < n; i++)
    {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return t1;
}
int fibBottomUpMemoized(int n)
{
    std::vector<int> memo(n + 1);
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i < memo.size(); i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}
int fibBottomUpMemoizedNoResize(int n)
{
    std::vector<int> memo;
    memo.push_back(0);
    memo.push_back(1);
    for (int i = 2; i < n + 1; i++)
    {
        memo.push_back(memo[i - 1] + memo[i - 2]);
    }
    return memo[n];
}

int main()
{

    auto begin = std::chrono::high_resolution_clock::now();
    int result = fibRecursion(40);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Fibonacci Recursion: " << result << " Time: " << elapsed.count() << " nanoseconds" << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    result = fibMemoized(40);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Fibonacci Recursion Memoized: " << result << " Time: " << elapsed.count() << " nanoseconds" << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    result = fibBottomUp(40);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Fibonacci Bottom Up: " << result << " Time: " << elapsed.count() << " nanoseconds" << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    result = fibBottomUpMemoized(40);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Fibonacci Bottom Up Memoized: " << result << " Time: " << elapsed.count() << " nanoseconds" << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    result = fibBottomUpMemoizedNoResize(40);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Fibonacci Bottom Up Memoized No Resize: " << result << " Time: " << elapsed.count() << " nanoseconds" << std::endl;

    return 0;
}