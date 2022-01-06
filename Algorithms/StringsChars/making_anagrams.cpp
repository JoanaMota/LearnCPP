#include <iostream>
#include <unordered_set>
int makeAnagram(std::string a, std::string b)
{
    std::unordered_multiset<char> lettersA;
    for (int i = 0; i < a.size(); i++)
    {
        lettersA.insert(a[i]);
    }
    int nrDeletions{0};
    std::unordered_multiset<char>::iterator it;
    for (int i = 0; i < b.size(); i++)
    {
        it = lettersA.find(b[i]);
        if (it != lettersA.end())
        {
            lettersA.erase(it);
        }
        else
        {
            nrDeletions++;
        }
    }
    return nrDeletions + lettersA.size();
}
int main()
{
    std::cout << makeAnagram("bugexikjevtubidpulaelsbcqlupwetzyzdvjphn", "lajoipfecfinxjspxmevqxuqyalhrsxcvgsdxxkac") << std::endl;
    return 0;
}