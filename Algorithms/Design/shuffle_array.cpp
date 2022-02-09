#include <iostream>
#include <vector>
#include <algorithm> // std::shuffle
#include <random>    // std::default_random_engine

void print(std::vector<int> &nums)
{
    for (int val : nums)
        std::cout << val << " ";
    std::cout << std::endl;
}
class Solution
{
private:
    std::vector<int> &m_nums;

public:
    Solution(std::vector<int> &nums) : m_nums(nums) {}

    std::vector<int> reset()
    {
        return m_nums;
    }

    std::vector<int> shuffle()
    {
        std::vector<int> shuffled = m_nums;
        for (int i = shuffled.size() - 1; i >= 0; --i)
        {
            int idx = rand() % (i + 1);
            std::swap(shuffled[i], shuffled[idx]);
        }
        return shuffled;
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 3};
    Solution *obj = new Solution(nums);
    std::vector<int> param_1 = obj->reset();
    print(param_1);
    std::vector<int> param_2 = obj->shuffle();
    print(param_2);
    return 0;
}