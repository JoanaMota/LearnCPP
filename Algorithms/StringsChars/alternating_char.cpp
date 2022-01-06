#include <iostream>

int alternatingCharacters(std::string s)
{
    char previous{s[0]};
    int nrDeletions{0};
    for (int i = 1; i < s.size(); i++)
    {
        if (previous == s[i])
        {
            nrDeletions++;
        }
        else
        {
            previous = s[i];
        }
    }
    return nrDeletions;
}

int main()
{
    std::cout << alternatingCharacters("ABABABAB") << std::endl;
    return 0;
}