#include <iostream>
#include <vector>
#include <cmath>
void reverseString(std::vector<char> &s)
{
    char temp;
    for (int i = 0; i < std::floor(s.size() / 2); i++)
    {
        temp = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = temp;
    }
}

void print(std::vector<char> &string)
{
    for (int i = 0; i < string.size(); ++i)
    {
        std::cout << string[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<char> str = {'a', 'b', 'c', 'd', 'e'};
    print(str);
    reverseString(str);
    print(str);
    return 0;
}