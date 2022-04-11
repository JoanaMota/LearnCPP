#include <iostream>
#include <stack>
#include <unordered_map>

std::string isBalanced(std::string s)
{
    std::unordered_map<char, char> brackets;
    brackets['{'] = '}';
    brackets['['] = ']';
    brackets['('] = ')';

    std::stack<char> str;
    for (int i = 0; i < s.size(); i++)
    {
        char temp = s[i];
        if (brackets.count(temp))
        {
            str.push(temp);
        }
        else if (str.size() == 0)
        {
            return "NO";
        }
        else if (brackets[str.top()] != temp)
        {
            return "NO";
        }
        else
        {
            str.pop();
        }
    }
    if (str.size() != 0)
    {
        return "NO";
    }
    return "YES";
}

int main()
{
    std::cout << isBalanced("}][}}(}][))]") << std::endl;
    return 0;
}