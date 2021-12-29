#include <iostream>
#include <vector>
#include <unordered_set>
void print(std::unordered_multiset<std::string> &set)
{
    for (auto it = set.begin(); it != set.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void checkMagazine(std::vector<std::string> magazine, std::vector<std::string> note)
{
    std::unordered_multiset<std::string> magazineSet;
    for (std::string word : magazine)
    {
        magazineSet.insert(word);
    }
    for (std::string word : note)
    {
        const auto it = magazineSet.find(word);
        if (it != magazineSet.end())
        {
            magazineSet.erase(it);
        }
        else
        {
            std::cout << "No" << std::endl;
            return;
        }
    }
    std::cout << "Yes" << std::endl;
    return;
}

int main()
{
    std::vector<std::string> magazine = {"give", "me", "one", "grand", "today", "give"};
    std::vector<std::string> note = {"give", "one", "grand", "today"};
    checkMagazine(magazine, note);
    return 0;
}