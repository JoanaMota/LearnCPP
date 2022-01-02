#include <iostream>
#include <unordered_set>

std::string twoStrings(std::string s1, std::string s2)
{
    std::unordered_set<char> letters;
    for (int i = 0; i < s1.size(); i++)
    {
        letters.insert(s1[i]);
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (letters.count(s2[i]))
        {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    std::cout << twoStrings("be", "art") << std::endl;
    return 0;
}