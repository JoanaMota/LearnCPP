#include <iostream>
#include <vector>
#include <stack>
class MinStackVector
{
private:
    std::vector<int> stack;

public:
    MinStackVector() {}

    void push(int val)
    {
        stack.push_back(val);
    }

    void pop()
    {
        stack.resize(stack.size() - 1);
    }

    int top()
    {
        return stack[stack.size() - 1];
    }

    int getMin()
    {
        int min{stack[0]};
        for (int i = 1; i < stack.size(); i++)
        {
            if (min > stack[i])
            {
                min = stack[i];
            }
        }
        return min;
    }
};
class MinStack
{
private:
    std::stack<int> stack;
    std::stack<int> stackMin;

public:
    MinStack() {}

    void push(int val)
    {
        stack.push(val);
        if (stackMin.empty())
            stackMin.push(val);
        else if (stackMin.top() >= val)
            stackMin.push(val);
    }

    void pop()
    {
        if (stack.top() == stackMin.top())
        {
            stackMin.pop();
        }
        stack.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return stackMin.top();
    }
};

int main()
{
    MinStack minStack = MinStack();
    minStack.push(0);
    minStack.push(1);
    minStack.push(0);
    std::cout << minStack.getMin() << std::endl; // return -3
    minStack.pop();
    std::cout << minStack.top() << std::endl;    // return 0
    std::cout << minStack.getMin() << std::endl; // return -2
    return 0;
}