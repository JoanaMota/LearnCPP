#include <iostream>
#include <vector>
void print(std::vector<int> vec)
{
    for (int el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}
std::vector<int> rotLeft(std::vector<int> a, int d)
{
    std::vector<int> output(a.size());
    if (d >= a.size())
    {
        d = d % a.size();
    }
    int j{a.size() - d};
    for (int i = 0; i < a.size(); i++)
    {
        output[j] = a[i];
        j++;
        if (j == a.size())
        {
            j = 0;
        }
    }
    return output;
}

int main()
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> output = rotLeft(input, 7);
    print(output);
    return 0;
}