#include <iostream>
#include <unordered_map>
#include <stack>
bool isValid(std::string s)
{
    if (s.size() % 2 != 0)
    {
        return false;
    }

    std::unordered_map<char, char> parentheses;
    parentheses['{'] = '}';
    parentheses['('] = ')';
    parentheses['['] = ']';

    std::stack<char> stackS;
    stackS.push(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        char temp = s[i];
        if (parentheses.count(temp))
        {
            stackS.push(temp);
        }
        else if (stackS.size() == 0)
        {
            return false;
        }
        else if (temp != parentheses[stackS.top()])
        {
            return false;
        }
        else
        {
            stackS.pop();
        }
    }
    if (stackS.size() != 0)
    {
        return false;
    }
    return true;
}

int main()
{
    // std::string s = "{()(())}[]";
    std::string s = "(){}{}";
    std::cout << std::boolalpha << isValid(s) << std::endl;
    return 0;
}