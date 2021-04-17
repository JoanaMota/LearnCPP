#include <iostream>
#include <vector>
int main()
{
    auto texts = {"one", "two", "three"};
    for (auto text: texts)
    {
        std::cout << text << std::endl;
    }

    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(8);
    numbers.push_back(9);
    for (auto number: numbers)
    {
        std::cout << number << std::endl;
    }
    
    std::string text = "Hello";
    for (auto c: text)
    {
        std::cout << c << std::endl;
    }
    
    
    return 0;
}