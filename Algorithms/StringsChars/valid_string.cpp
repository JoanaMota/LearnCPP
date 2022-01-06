#include <iostream>
#include <unordered_map>
#include <math.h>

std::string isValid(std::string s)
{
    std::unordered_map<char, int> letters;
    for (char letter : s)
    {
        letters[letter]++;
    }
    bool removedOne{false};

    std::unordered_map<int, int> frequency;
    for (std::unordered_map<char, int>::iterator it = letters.begin(); it != letters.end(); it++)
    {
        frequency[it->second]++;
    }
    if (1 == frequency.size())
    {
        return "YES";
    }
    else if (frequency.size() > 2)
    {
        return "NO";
    }

    std::unordered_map<int, int>::iterator it = frequency.begin();
    std::unordered_map<int, int>::iterator it2 = it++;
    if (it->second * it->first == 1)
    {
        return "YES";
    }
    if ((it->first - 1) == it2->first && it->second == 1)
    {
        return "YES";
    }
    if (it2->second * it2->first == 1)
    {
        return "YES";
    }
    if ((it2->first - 1) == it->first && it2->second == 1)
    {
        return "YES";
    }

    return "NO";
}

int main()
{
    std::cout << isValid("aabbcd") << std::endl;
    return 0;
}