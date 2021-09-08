#include <iostream>
#include <unordered_map>
int firstUniqChar(std::string s)
{
    std::unordered_map<char, int> charsMap;
    for (char ch : s)
    {
        charsMap[ch]++;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if (charsMap[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::string str = "eheolhll";
    int position = firstUniqChar(str);
    std::cout << "First unique char in:" << position << std::endl;
    return 0;
}