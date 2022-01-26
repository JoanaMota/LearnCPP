#include <iostream>

int countSubstrings(std::string s)
{
    int output{0}, left{0}, right{1};
    for (int i = 0; i < s.size(); i++)
    {
        left = i;
        right = i;
        while (left >= 0 && right < s.size())
        {
            if (s[left] == s[right])
            {
                output++;
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
        left = i;
        right = i + 1;
        while (left >= 0 && right < s.size())
        {
            if (s[left] == s[right])
            {
                output++;
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
    }
    return output;
}

int main()
{
    std::cout << countSubstrings("aaaaa") << std::endl;
    return 0;
}