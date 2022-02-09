#include <iostream>
#include <unordered_map>

long substrCount(int n, std::string s)
{
    long counter{n};
    for (int i = 0; i < n; i++)
    {
        char startChar{s[i]};
        int middle{-1};
        for (int j = i + 1; j < n; j++)
        {
            if (startChar == s[j])
            {
                if (-1 == middle || (j - middle) == (middle - i))
                {
                    counter++;
                }
            }
            else
            {
                if (-1 == middle)
                {
                    middle = j;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return counter;
}

int main()
{
    std::cout << substrCount(8, "mnonopoo") << std::endl;
    return 0;
}