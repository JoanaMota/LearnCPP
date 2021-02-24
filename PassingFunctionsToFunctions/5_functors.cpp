#include <iostream>

struct Test
{
    virtual bool operator()(std::string &text) = 0;
};

// Functor:
// Class or a struct that overloads the brackets operator
struct MatchTest : public Test
{
    // Overload the round brackets() operator
    bool operator()(std::string &f_text)
    {
        return f_text == "lion";
    }
};

void check(std::string f_text, Test &f_test)
{
    if (f_test(f_text))
    {
        std::cout << "Text Matches!" << std::endl;
    }
    else
    {
        std::cout << "Text Does Not Match!" << std::endl;
    }
}

int main()
{
    MatchTest pred;

    std::string value = "lion";

    // Looks like a functional call but it's not it's only the round brackets operator
    // being applied through this object to this value
    std::cout << pred(value) << std::endl;

    MatchTest matchTest;
    // check("lion", MatchTest()); // This does not work
    check("lion", matchTest);
    check("lion3", matchTest);
    return 0;
}