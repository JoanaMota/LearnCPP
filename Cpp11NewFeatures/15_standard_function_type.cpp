#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

bool check(std::string text)
{
    return text.size() == 5;
}

class Check
{
private:
public:
    bool operator()(std::string &text)
    {
        return text.size() == 4;
    }
} check1;

void run(std::function<bool(std::string &)> check)
{
    std::string test = "dog";
    std::cout << check(test) << std::endl;
}

int main()
{
    int size = 3;
    std::vector<std::string> vec{"one", "two", "three"};

    // Count the number of strings that have a specific size

    // We just have to make sure that our function that we pass to count_if receives a string and returns bool
    auto lambda = [size](std::string test) { return test.size() == size; };
    int count1 = count_if(vec.begin(), vec.end(), lambda); // pass a lambda
    std::cout << count1 << std::endl;

    int count2 = count_if(vec.begin(), vec.end(), check); // pass a function pointer
    std::cout << count2 << std::endl;

    int count3 = count_if(vec.begin(), vec.end(), check1); // pass a functor
    std::cout << count3 << std::endl;

    std::cout << std::endl;

    // Wrap a lambda expression
    run(lambda); // Checks if "dog" size is equal to 3 (size variable)
    // Wrap a function
    run(check); // Checks if "dog" size is equal to 5 (defined on the free function)
    // Wrap a functor
    run(check1); // Checks if "dog" size is equal to 4 (defined on the functor)

    std::function<int(int, int)> add = [](int a, int b) { return a + b; };
    std::cout << add(5, 5) << std::endl;
    return 0;
}