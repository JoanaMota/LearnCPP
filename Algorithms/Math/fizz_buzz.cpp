#include <iostream>
#include <vector>

std::vector<std::string> fizzBuzz(int n)
{
    std::vector<std::string> output;
    for (int i = 1; i < n + 1; i++)
    {
        std::string el{""};
        if (0 == (i % 3))
        {
            el = "Fizz";
        }
        if (0 == (i % 5))
        {
            el += "Buzz";
        }
        if (0 != (i % 3) && 0 != (i % 5))
        {
            el = std::to_string(i);
        }
        output.push_back(el);
    }
    return output;
}

int main()
{
    std::vector<std::string> output = fizzBuzz(15);
    for (std::string el : output)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}