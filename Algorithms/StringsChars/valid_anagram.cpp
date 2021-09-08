#include <iostream>
#include <unordered_map>
bool isAnagram(std::string s, std::string t)
{
    if (s.size() != t.size())
    {
        return false;
    }

    std::unordered_map<char, int> mapS, mapT;
    for (size_t i = 0; i < s.size(); i++)
    {
        mapS[s[i]]++;
        mapT[t[i]]++;
    }
    if (mapS.size() != mapT.size())
    {
        return false;
    }

    for (std::unordered_map<char, int>::iterator it = mapS.begin(); it != mapS.end(); it++)
    {
        if (mapT[it->first] != it->second)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string s = "angram";
    std::string t = "nagaram";
    std::cout << std::boolalpha << isAnagram(s, t) << std::endl;
    return 0;
}