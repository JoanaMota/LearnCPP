#include <iostream>
#include <vector>
#include <initializer_list>
class Test
{
public:
    Test(std::initializer_list<std::string> texts)
    {
        for (auto value : texts)
        {
            std::cout << value << std::endl;
        }
    };
    void print(std::initializer_list<int> list)
    {
        for (auto value : list)
        {
            std::cout << value << std::endl;
        }
    }
};

int main()
{
    std::vector<int> numbers{1, 2, 3, 4};

    Test test{"orange", "banana"};
    test.print({1, 5, 8, 9});

    return 0;
}