#include <iostream>
#include <unordered_map>
#include <math.h>

int characterReplacement(std::string s, int k)
{
    std::unordered_map<char, int> lettersCount;

    int leftIt{0}, max_count{0}, max{0};
    for (int rightIt = 0; rightIt < s.size(); rightIt++)
    {
        lettersCount[s[rightIt]]++;
        max_count = std::max(max_count, lettersCount[s[rightIt]]); // letter with max count;
        // if substring size (rightIt - leftIt + 1) - max letter count <= k we continue
        // else while this is not valid we move the leftIt
        while (rightIt - leftIt + 1 - max_count > k)
        {
            lettersCount[s[leftIt]]--;
            leftIt++;
        }
        max = std::max(max, rightIt - leftIt + 1);
    }
    return max;
}

int main()
{
    std::cout << characterReplacement("ABAB", 2) << std::endl;
    return 0;
}