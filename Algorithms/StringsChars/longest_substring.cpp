#include <iostream>
#include <unordered_map>
#include <assert.h>
int lengthOfLongestSubstring(std::string s)
{
    std::unordered_map<char, std::pair<int, int>> m;
    int counter = 0, max = 0, pos = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i]].first < pos)
            m[s[i]].second = 0;
        if (m[s[i]].second == 0)
            counter++;
        else
        {
            counter = i - m[s[i]].first;
            pos = m[s[i]].first;
        }
        m[s[i]].first = i;
        m[s[i]].second = 1;
        max = std::max(counter, max);
    }
    return max;
}

int main()
{
    std::cout << lengthOfLongestSubstring("abcabcbb") << " 3" << std::endl;
    std::cout << lengthOfLongestSubstring("bbbbb") << " 1" << std::endl;
    std::cout << lengthOfLongestSubstring("pwwkew") << " 3" << std::endl;
    std::cout << lengthOfLongestSubstring("") << " 0" << std::endl;
    std::cout << lengthOfLongestSubstring(" ") << " 1" << std::endl;
    std::cout << lengthOfLongestSubstring("dvdf") << " 3" << std::endl;
    return 0;
}