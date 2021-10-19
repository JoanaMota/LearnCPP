#include <iostream>
#include <stack>
// '('')', '{''}', '['']'
bool isValid(std::string s)
{
    std::stack<char> brackStack;
    for (char a : s)
    {
        if (a == '(' || a == '{' || a == '[')
        {
            brackStack.push(a);
        }
        else
        {
            if (brackStack.empty())
                return false;
            if (a == ')')
            {
                if (brackStack.top() != '(')
                    return false;
            }
            else if (a == ']')
            {
                if (brackStack.top() != '[')
                    return false;
            }
            else if (brackStack.top() != '{')
                return false;
            brackStack.pop();
        }
    }
    return brackStack.empty();
}

int main()
{
    std::cout << std::boolalpha << isValid("([)]") << std::endl;
    return 0;
}