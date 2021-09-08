#include <iostream>
#include <cmath>

bool isPalindrome(std::string s)
{
    if (s.size() == 1)
        return true;

    int backwards = s.size() - 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (backwards < 0 || backwards == i)
            break;
        while (backwards >= 0)
        {
            if ((isalpha(s[backwards]) || isdigit(s[backwards])))
                break;
            backwards--;
        }
        if (isalpha(s[i]))
        {
            if (std::tolower(s[i]) != std::tolower(s[backwards]))
            {
                return false;
                break;
            }
        }
        else if (isdigit(s[i]))
        {
            if (s[i] != s[backwards])
            {
                return false;
                break;
            }
        }
        else
        {
            continue;
        }

        backwards--;
    }
    return true;
}

int main()
{
    // std::string input = "A man, a plan, a canal: Panama";
    // std::string input = ",,,,,,,,,,,,acva";
    std::string input = "0";
    std::cout << std::boolalpha << isPalindrome(input) << std::endl;
    return 0;
}