#include <iostream>
#include <unordered_map>

// I = 1
// V = 5
// X = 10
// L = 50
// C = 100
// D = 500
// M = 1000
int romanToInt(std::string s)
{
    int output{0};
    std::unordered_map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;
    bool skip{false};
    for (int i = 0; i < s.size(); ++i)
    {
        if (skip)
        {
            skip = false;
            continue;
        }
        int temp = roman[s[i]];
        if ((i + 1) != s.size())
        {
            if (s[i] == 'I')
            {
                if (s[i + 1] == 'V' || s[i + 1] == 'X')
                {
                    temp = roman[s[i + 1]] - temp;
                    skip = true;
                }
            }
            else if (s[i] == 'X')
            {
                if (s[i + 1] == 'L' || s[i + 1] == 'C')
                {
                    temp = roman[s[i + 1]] - temp;
                    skip = true;
                }
            }
            else if (s[i] == 'C')
            {
                if (s[i + 1] == 'D' || s[i + 1] == 'M')
                {
                    temp = roman[s[i + 1]] - temp;
                    skip = true;
                }
            }
        }

        output += temp;
    }
    return output;
}

int main()
{
    int number = romanToInt("MCMXCIV");
    std::cout << number << std::endl;
    return 0;
}