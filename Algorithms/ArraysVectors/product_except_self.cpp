#include <iostream>
#include <vector>
std::vector<int> productExceptSelf(std::vector<int> &nums)
{
    std::vector<int> output(nums.size(), 0);
    int multi{nums[0]};
    int zeros{0};
    int zerosPosition{0};
    for (int i = 1; i < nums.size(); i++)
    {
        if (0 == nums[i])
        {
            zeros++;
            zerosPosition = i;
            continue;
        }
        multi *= nums[i];
    }
    if (0 == multi || zeros > 1)
    {
        return output;
    }
    else if (1 == zeros)
    {
        output[zerosPosition] = multi;
        return output;
    }

    for (int i = 0; i < output.size(); i++)
    {
        output[i] = multi / nums[i];
    }
    return output;
}

void print(std::vector<int> &vec)
{
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> nums = {-1, 1, 0, -3, 3};
    std::vector<int> numsProduct = productExceptSelf(nums);
    print(numsProduct);
    return 0;
}