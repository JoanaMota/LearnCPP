#include <iostream>
#include <unordered_map>
#include <algorithm>

int sherlockAndAnagrams(std::string s)
{
    std::unordered_map<std::string, int> letters;
    for (int len = 1; len < s.size(); len++)
    {
        for (int j = 0; j <= s.size() - len; j++)
        {
            std::string temp = s.substr(j, len);
            std::sort(temp.begin(), temp.end());
            letters[temp]++;
        }
    }
    int nrAnagrams{0};
    for (auto &it : letters)
    {
        nrAnagrams += it.second * (it.second - 1) / 2;
    }
    return nrAnagrams;
}

int main()
{
    std::cout << sherlockAndAnagrams("kkkk") << std::endl;
    return 0;
}