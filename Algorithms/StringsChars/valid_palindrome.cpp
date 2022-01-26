#include <iostream>
#include <cmath>

bool isPalindrome(std::string s)
{
    if (s.size() == 1)
        return true;
    int left{0}, right{(int)s.size() - 1};
    while (left < right)
    {
        if (!isalnum(s[left]))
        {
            left++;
            continue;
        }

        if (!isalnum(s[right]))
        {
            right--;
            continue;
        }

        if (isalnum(s[left]) && isalnum(s[right]) && std::tolower(s[left]) != std::tolower(s[right]))
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    std::string input = "A man, a plan, a canal: Panama";
    // std::string input = ",,,,,,,,,,,,acva";
    // std::string input = "OP";
    std::cout << std::boolalpha << isPalindrome(input) << std::endl;
    return 0;
}